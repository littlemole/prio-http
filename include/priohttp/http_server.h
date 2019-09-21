#ifndef DEFINE_MOL_HTTP_SERVER_HTTPSERVER_DEF_GUARD_DEFINE_
#define DEFINE_MOL_HTTP_SERVER_HTTPSERVER_DEF_GUARD_DEFINE_

#include "priocpp/api.h"

namespace prio   {

class Request;
class Response;

	
class HttpClientConversation;

class http_server
{
public:

	typedef repro::Promise<Request&,Response&> PromiseType;
	typedef repro::Future<Request&,Response&> FutureType;

	http_server();
	http_server(prio::SslCtx& ctx);
	~http_server();

    FutureType bind(int port);

    void shutdown();
    
private:

    http_server(const http_server& rhs) = delete;
    http_server& operator=(const http_server& rhs) = delete;

    void onAccept(Connection::Ptr, int port);
    void onAccept2(Connection::Ptr, int port);
    
    PromiseType promise_;

    std::shared_ptr<Listener> listener_;
    bool isSecure_;
};


} // close namespaces


#endif



