#ifndef DEFINE_MOL_HTTP_SERVER_RESPONSE_PROCESSOR_DEF_GUARD_DEFINE_
#define DEFINE_MOL_HTTP_SERVER_RESPONSE_PROCESSOR_DEF_GUARD_DEFINE_

#include "priohttp/conversation.h"

namespace prio      {


//////////////////////////////////////////////////////////////

class ClientHttpReader;
class http2_client_session;

class HttpClientConversation : public ReaderWriterConversation, public std::enable_shared_from_this<HttpClientConversation>
{
public:

	typedef std::shared_ptr<HttpClientConversation> Ptr;
	typedef repro::Promise<Request&,Response&> PromiseType;
	typedef repro::Future<Request&,Response&> FutureType;

	Request req;
	Response res;

	static FutureType on(Connection::Ptr client, Request& r);

    ~HttpClientConversation();

    HttpClientConversation(const HttpClientConversation& rhs) = delete;
    HttpClientConversation& operator=(const HttpClientConversation& rhs) = delete;

	virtual Connection::Ptr con();

	virtual void onHeadersComplete(const std::string& s);
	virtual void onRequestComplete(const std::string& s);
	virtual void onResponseComplete(const std::string& s);
	virtual void onRequestError(const std::exception& s);
	virtual Request& request() { return req; }
	virtual Response& response() { return res; }

	virtual repro::Future<std::string> read();
	virtual repro::Future<> write(const std::string& s);

	virtual void flush(Response& res) {}
	virtual void onFlush(std::function<void(Request& req, Response& res)> f) {};
	virtual void chunk(const std::string& ch) {};
	
	virtual bool keepAlive()
	{
		return keep_alive_;
	}
private:

	HttpClientConversation(Connection::Ptr client, Request& r);

	void read_channel();

	Connection::Ptr con_;
	PromiseType promise_;
	std::function<void(const std::string& s)> status_func_;


	bool keep_alive_;
	Ptr self_;

	std::unique_ptr<ClientHttpReader> reader_;
};

//////////////////////////////////////////////////////////////

class Http2ClientConversation : public Conversation, public std::enable_shared_from_this<Http2ClientConversation>
{
public:

	typedef std::shared_ptr<Http2ClientConversation> Ptr;
	typedef repro::Promise<Request&,Response&> PromiseType;
	typedef repro::Future<Request&,Response&> FutureType;

	Request req;
	//Response res;

	static FutureType on(Connection::Ptr client, Request& r);

    ~Http2ClientConversation();

    Http2ClientConversation(const Http2ClientConversation& rhs) = delete;
    Http2ClientConversation& operator=(const Http2ClientConversation& rhs) = delete;

	virtual Connection::Ptr con();

	virtual void onRequestError(const std::exception& s);
	virtual void flush(Response& res) {}
	virtual void onFlush(std::function<void(Request& req, Response& res)> f) {};
	virtual void chunk(const std::string& ch) {};
	
	virtual bool keepAlive()
	{
		return keep_alive_;
	}

	void resolve(Request& req, Response& res);

private:

	Http2ClientConversation(Connection::Ptr client, Request& r);

	void schedule_read();

	Connection::Ptr con_;
	PromiseType promise_;
	std::function<void(const std::string& s)> status_func_;

	bool keep_alive_;
	Ptr self_;

	std::unique_ptr<http2_client_session> http2_;
};


} // close namespaces


#endif



