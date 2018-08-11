#include <event2/event.h>
#include "priohttp/conversation.h"
#include "priocpp/api.h"
#include "priohttp/server/reader.h"
#include "priohttp/server/writer.h"

using namespace repro;

namespace prio  {

LITTLE_MOLE_DECLARE_DEBUG_REF_CNT(server_connections);


HttpConversation::HttpConversation(Connection::Ptr f)
	: req(this),
	  res(this),
	  con_(f),
	  promise_(repro::promise<Request&,Response&>()),
	  keep_alive_(false),
	  completion_func_( [](Request&,Response&){})
{

	reader_.reset(new HttpHeaderReader(this));
	writer_.reset(new HttpPlainBodyWriter(this));

	LITTLE_MOLE_ADDREF_DEBUG_REF_CNT(server_connections);
}
 
HttpConversation::~HttpConversation()
{
	LITTLE_MOLE_RELEASE_DEBUG_REF_CNT(server_connections);
}

HttpConversation::FutureType HttpConversation::on(Connection::Ptr s)
{
	auto r =  Ptr( new HttpConversation(s));
	r->self_ = r;

	r->reader_->consume("");

	return r->promise_.future();
}


Future<std::string> HttpConversation::read()
{
	auto p = repro::promise<std::string>();

	con_->read()
	.then( [p] (Connection::Ptr c, std::string s)
	{
		p.resolve(s);
	})
	.otherwise([p](const std::exception& ex)
	{
		p.reject(ex);
	});

	return p.future();
}

Future<> HttpConversation::write(const std::string& s)
{
	auto p = repro::promise<>();

	con_->write(s)
	.then( [p] (Connection::Ptr c)
	{
		p.resolve();
	})
	.otherwise([p](const std::exception& ex)
	{
		p.reject(ex);
	});

	return p.future();
}


void HttpConversation::resolve(Request& req, Response& res)
{ 
    promise_.resolve(req,res);
}

void HttpConversation::flush(Response& res)
{
	if(res.isGzipped() && !res.isChunked())
	{
		writer_.reset( new HttpGzippedBodyWriter(new HttpPlainBodyWriter(this)));
	}
	writer_->flush();
}

void HttpConversation::chunk(const std::string& ch)
{
	HttpResponse& response = (HttpResponse&)res;
	if( !response.headersSent() )
	{
		HttpWriter* w = new HttpChunkedBodyWriter(this);
		if(res.isGzipped())
		{
			w = new HttpGzippedBodyWriter(w);
		}
		writer_.reset(w);
	}

	writer_->write(ch);
}


void HttpConversation::onHeadersComplete(const std::string& b)
{
	bool readBody = req.size() > 0; // TODO || req.isCHunked();

	if(readBody)
	{
		//ServerHttpReader* reader = nullptr;
		/*
		if(!con_->isChunked_)
		{
			reader = new HttpClientContentLengthBodyReader(con_,con_->res.size());
		}
		else
		{
			*/

		std::string s = b;
		reader_.reset(new HttpContentLengthBodyReader(this));
		reader_->consume(s);
	}
	else
	{
		onRequestComplete(b);
	}
}

void HttpConversation::onRequestComplete(const std::string& b)
{
	HttpRequest& request = (HttpRequest&)req;

	request.body(b);

	keep_alive_ = req.keep_alive();

	promise_.resolve(req,res);
}

void HttpConversation::onResponseComplete(const std::string&)
{
	if(completion_func_)
	{
		completion_func_(req,res);
	}

	HttpRequest& request = (HttpRequest&)req;
	HttpResponse& response = (HttpResponse&)res;

	request.reset();
	response.reset();

    if ( keep_alive_ && !req.detached())
    {
    	reader_.reset(new HttpHeaderReader(this));
		writer_.reset(new HttpPlainBodyWriter(this));

    	reader_->consume("");
        return;
    }

	if(!req.detached())
	{
		con_->close();
		self_.reset();
	}
	else
	{
		self_.reset();
	}
}

void HttpConversation::onRequestError(const std::exception& ex)
{
	promise_.reject(ex);
	con_->close();
	self_.reset();
}

Connection::Ptr HttpConversation::con()
{
	return con_;
}

void HttpConversation::onFlush(std::function<void(Request& req, Response& res)> f)
{
	completion_func_ = f;
}

bool HttpConversation::keepAlive()
{
	return keep_alive_;
}


////////////////


SubRequest::SubRequest()
	: req(this),
	  res(this),
	  promise_(repro::promise<Request&,Response&>()),
	  completion_func_( [](Request&,Response&){})
{
}
 
SubRequest::~SubRequest()
{
}

SubRequest::FutureType SubRequest::on(const Request& request, const std::string& path)
{
	req.path = request.path;
	req.headers = request.headers;
	req.path.path(path);
	self_ = shared_from_this();

	return promise_.future();
}


void SubRequest::resolve(Request& req, Response& res)
{ 
    promise_.resolve(req,res);
}

void SubRequest::flush(Response& res)
{
	resolve(req,res);
	completion_func_(req,res);
	self_.reset();
}

void SubRequest::chunk(const std::string& ch)
{
	res.body(res.body()+ ch);
}

void SubRequest::onRequestError(const std::exception& ex)
{
	promise_.reject(ex);
	self_.reset();
}

Connection::Ptr SubRequest::con()
{
	Connection::Ptr empty;
	return empty;
}

void SubRequest::onFlush(std::function<void(Request& req, Response& res)> f)
{
	completion_func_ = f;
}

bool SubRequest::keepAlive()
{
	return false;
}


} // close namespaces

