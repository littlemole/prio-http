#include <event2/event.h>
#include "priohttp/http2_conversation.h"
#include "priocpp/api.h"
#include "priohttp/server/reader.h"
#include "priohttp/server/writer.h"
#include "priohttp/http2.h"
#include <set>
#include <sstream>
#include <deque>


namespace prio  {

LITTLE_MOLE_DECLARE_DEBUG_REF_CNT(server_connections);


Http2Conversation::Http2Conversation(Connection::Ptr f)
	: 
	  con_(f),
	  promise_(repro::promise<Request&,Response&>()),
	  flusheaders_func_( [](Request&,Response&)
        {
            auto p = repro::promise<>();
            nextTick([p]()
            {
                p.resolve();
            });
            return p.future();
        }),      
      completion_func_( [](Request&,Response&){}),
      http2_(std::make_unique<http2_server_session>(this))
{
	LITTLE_MOLE_ADDREF_DEBUG_REF_CNT(server_connections);
}
 
Http2Conversation::~Http2Conversation()
{
	LITTLE_MOLE_RELEASE_DEBUG_REF_CNT(server_connections);
}

Http2Conversation::FutureType Http2Conversation::on(Connection::Ptr s)
{
	auto r =  Ptr( new Http2Conversation(s));
	r->self_ = r;

    r->http2_->initialize_nghttp2_session();
    r->http2_->send_connection_header();
    r->http2_->send()
    .then([r]()
    {
       r->schedule_read();
    })
    .otherwise([r](const std::exception& ex)
	{
		r->onRequestError(ex);
	});     
    
	return r->promise_.future();
}

void Http2Conversation::schedule_read()
{
    auto ptr = shared_from_this();

    con_->read()
    .then([ptr](Connection::Ptr,std::string s)
    {
        return ptr->http2_->recv(s);
    })
    .then([ptr]()
    {
        ptr->schedule_read();
    })
    .otherwise([ptr](const std::exception& ex)
	{
		ptr->onRequestError(ex);
	}); 
}

void Http2Conversation::resolve(Request& req, Response& res)
{ 
    promise_.resolve(req,res);
}

void Http2Conversation::flush(Response& res)
{        
    int stream_id = res.attributes.attr<int>(":http2:stream:id");    
 
    //http2_server_stream* stream = http2_->get_stream_by_id(stream_id);

    auto stream = http2_->get_stream_by_id(stream_id)->shared_from_this();
    auto ptr = shared_from_this();

	flusheaders_func_(stream->req,res)
	.then( [ptr,stream,&res]()
	{
        ptr->http2_->flush(res);

        //auto ptr_stream = stream->shared_from_this();

        ptr->http2_->send()
        .then([ptr,stream]()
        {
            if(ptr->completion_func_)
            {
                ptr->completion_func_(stream->req,stream->res);
            }
        
            if(stream->req.detached())
            {
                ptr->self_.reset();
                return;
            }
        
            stream->reset();        
        })
        .otherwise([ptr](const std::exception& ex)
        {
            ptr->onRequestError(ex);
        });    

    });
}

void Http2Conversation::chunk(const std::string& ch)
{
   // TODO ?
}

void Http2Conversation::onRequestError(const std::exception& ex)
{
	promise_.reject(ex);
	con_->close();
	self_.reset();
}

Connection::Ptr Http2Conversation::con()
{
	return con_;
}

bool Http2Conversation::keepAlive()
{
	return false;
}

void Http2Conversation::onCompletion(std::function<void(Request& req, Response& res)> f)
{
    completion_func_ = f;
}

void Http2Conversation::onFlushHeaders(std::function<repro::Future<>(Request& req, Response& res)> f)
{
	flusheaders_func_ = f;
}


} // close namespaces

