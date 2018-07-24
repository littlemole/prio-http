#include "priohttp/client_conversation.h"
#include "priohttp/conversation.h"
#include "priohttp/client.h"
#include "priocpp/connection.h"
#include "priocpp/ssl_connection.h"

using namespace repro;

namespace prio  {


HttpClient::Ptr HttpClient::url(const std::string& url)
{
	HttpClient::Ptr result = std::shared_ptr<HttpClient>(new HttpClient(url));
	result->method_ = "GET";
	return result;
}



HttpClient::Ptr HttpClient::url(prio::SslCtx& ctx,const std::string& url)
{
	HttpClient::Ptr result = std::shared_ptr<HttpClient>(new HttpClient(ctx,url));
	result->method_ = "GET";
	return result;
}

Future<Response&> HttpClient::GET()
{
	method_ = "GET";
	return fetch();
}


Future<Response&> HttpClient::POST(const std::string& body)
{
	method_ = "POST";
	return fetch();
}


Future<Response&> HttpClient::PUT( const std::string& body)
{
	method_ = "PUT";
	return fetch();
}


Future<Response&> HttpClient::DEL()
{
	method_ = "DELETE";
	return fetch();
}

HttpClient::Ptr HttpClient::header(const std::string& h, const std::string& v)
{
	HttpRequest& req = (HttpRequest&)request;
	req.header(h,v);
	return shared_from_this();
}

HttpClient::Ptr HttpClient::accept(const std::string& v)
{
	HttpRequest& req = (HttpRequest&)request;
	req.header("ACCEPT",v);
	return shared_from_this();
}


HttpClient::Ptr HttpClient::content_type(const std::string& v)
{
	HttpRequest& req = (HttpRequest&)request;
	req.header("CONTENT-TYPE",v);
	return shared_from_this();
}


HttpClient::Ptr HttpClient::protocol(const std::string& v)
{
	proto_ = v;
	return shared_from_this();
}

HttpClient::Ptr HttpClient::body(const std::string& v)
{
	HttpRequest& req = (HttpRequest&)request;

	std::ostringstream oss;
	oss << v.size();
	req.header("CONTENT-SIZE",oss.str());
	req.body(v);
	return shared_from_this();
}

HttpClient::Ptr HttpClient::keepAlive(bool b)
{
	keep_alive_ = b;
	return shared_from_this();
}

Future<Response&> HttpClient::fetch()
{
	HttpRequest& req = (HttpRequest&)request;

	auto p = repro::promise<Response&>();

	self_ = shared_from_this();

	if(keep_alive_) {
		req.header("Connection","KEEP-ALIVE");
	}
	else {
		req.header("Connection","Close");
	}

	req.header("HOST",dest_.getHost());

	Future<Connection::Ptr> con;

	if ( dest_.getProto() == "http")
	{
		con = TcpConnection::connect(dest_.getHost(),dest_.getPort());
	}
	else if (dest_.getProto() == "https")
	{
		con = SslConnection::connect(dest_.getHost(),dest_.getPort(),*ctx_);
	}
	else
	{
		throw repro::Ex("unknown proto");
	}

	con
	.then([this,&req](Connection::Ptr client)
	{
		con_ = client;

		std::ostringstream oss;
		oss << method_ << " " << dest_.getFullPath() << " " << proto_;
		req.action(oss.str());

		if(client->isHttp2Requested())
		{
			return Http2ClientConversation::on(client,request);
		}

		return HttpClientConversation::on(client,request);
	})
	.then( [p,this](Request& req,Response& res)
	{
		p.resolve(res);
		self_.reset();
	})
	.otherwise( [p,this](const std::exception& ex)
	{
		p.reject(ex);
		self_.reset();
	});

	return p.future();
}




} // close namespaces

