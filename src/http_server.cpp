#include <event2/event.h>
#include <fcntl.h>
#include "priohttp/conversation.h"
#include "priohttp/http2_conversation.h"
#include "priocpp/api.h"
#include "priohttp/http_server.h"
#include "priocpp/ssl_connection.h"
#include <iostream>

namespace prio  {


http_server::http_server()
 : promise_(repro::promise<Request&,Response&>())
{
	listener_ = std::make_shared<Listener>();
}


http_server::http_server(prio::SslCtx& ctx)
 : promise_(repro::promise<Request&,Response&>())
{
	listener_ = std::make_shared<Listener>(ctx);	
}

http_server::~http_server()
{
	listener_->cancel();
}	

void http_server::shutdown()
{
	listener_->cancel();
}

http_server::FutureType http_server::bind(int port)
{
	listener_->bind(port)
	.then( [this](Connection::Ptr client)
	{
		if(client->isHttp2Requested())
		{
			onAccept2(client);			
		}
		else
		{
			onAccept(client);			
		}
	})
	.otherwise([](const std::exception& ex){
		std::cerr << "http_server ex: " << ex.what() << std::endl;
	});	
	return promise_.future();
}
    
void http_server::onAccept(Connection::Ptr client)
{
    try 
    {
		HttpConversation::on(client)
		.then( [this] (Request& req, Response& res) 
		{
			promise_.resolve(req,res);
		})
		.otherwise( [this] (const std::exception& ex) 
		{
			 promise_.reject(ex);
		});
    }
    catch( repro::Ex& ex)
    {
        std::cerr << "ex: " << ex.msg << std::endl;
    }  
} 

void http_server::onAccept2(Connection::Ptr client)
{
    try 
    {
		Http2Conversation::on(client)
		.then( [this] (Request& req, Response& res) 
		{
			promise_.resolve(req,res);
		})
		.otherwise( [this] (const std::exception& ex) 
		{
			 promise_.reject(ex);
		});
    }
    catch( repro::Ex& ex)
    {
        std::cerr << "ex: " << ex.msg << std::endl;
    }  
} 


} // close namespaces


