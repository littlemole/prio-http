#ifndef _MOL_DEF_GUARD_DEFINE_MOD_HTTP_REQUEST_CLIENT_DEF_GUARD_
#define _MOL_DEF_GUARD_DEFINE_MOD_HTTP_REQUEST_CLIENT_DEF_GUARD_

#include "priocpp/api.h"
#include "priohttp/response.h"
#include "priocpp/ssl_connection.h"

//////////////////////////////////////////////////////////////

namespace prio  {


class HttpConversation;
class HttpClientConversation;
class HttpRequestParser;


class HttpClient : public std::enable_shared_from_this<HttpClient>
{
public:

	typedef std::shared_ptr<HttpClient> Ptr;

	Request request;

	static HttpClient::Ptr url(const std::string& url);
	static HttpClient::Ptr url(prio::SslCtx& ctx,const std::string& url);

	Future<Response&> GET();
	Future<Response&> POST(const std::string& body);
	Future<Response&> PUT( const std::string& body);
	Future<Response&> DEL();

	HttpClient::Ptr header(const std::string& h, const std::string& v);
	HttpClient::Ptr accept(const std::string& v);
	HttpClient::Ptr content_type(const std::string& v);
	HttpClient::Ptr protocol(const std::string& v);

	HttpClient::Ptr body(const std::string& v);
	HttpClient::Ptr keepAlive(bool b);

	Future<Response&> fetch();

private:

	HttpClient(const prio::Url& u)
	: dest_(u),proto_("HTTP/1.0"),keep_alive_(false),ctx_(nullptr)
	{}

	HttpClient(prio::SslCtx& ctx,const prio::Url& u)
	: dest_(u),proto_("HTTP/1.0"),keep_alive_(false),ctx_(&ctx)
	{}

	prio::Connection::Ptr con_;

	prio::Url dest_;
	std::string method_;
	std::string proto_;
	bool keep_alive_;
	Ptr self_;
	prio::SslCtx* ctx_;
};



} // close namespaces

#endif

