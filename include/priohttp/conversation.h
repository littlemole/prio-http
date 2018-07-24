#ifndef DEFINE_MOL_HTTP_SERVER_REQUEST_PROCESSOR_DEF_GUARD_DEFINE_
#define DEFINE_MOL_HTTP_SERVER_REQUEST_PROCESSOR_DEF_GUARD_DEFINE_

#include "priohttp/response.h"

namespace prio  {

// forwards;
class Loop;
Loop& theLoop();


class ServerHttpReader;
class HttpWriter;


//////////////////////////////////////////////////////////////

class Conversation
{
public:

	virtual ~Conversation() {}

	virtual bool keepAlive() = 0;
	virtual void flush(Response& res) = 0;
	virtual void onFlush(std::function<void(Request& req, Response& res)> f) = 0;
	virtual void chunk(const std::string& ch) = 0;
	virtual prio::Connection::Ptr con() = 0;
	virtual void onRequestError(const std::exception& s)  = 0;
	virtual void resolve(Request& req, Response& res) = 0;
};
 
class ReaderWriterConversation //: public Conversation
{
public:

	virtual ~ReaderWriterConversation() {}

	virtual void onRequestError(const std::exception& s)  = 0;
	virtual void onHeadersComplete(const std::string& s)  = 0;
	virtual void onRequestComplete(const std::string& s)  = 0;
	virtual void onResponseComplete(const std::string& s) = 0;

	virtual repro::Future<std::string> read() = 0;
	virtual repro::Future<> write(const std::string& s) = 0;

	virtual Request& request() = 0;
	virtual Response& response() = 0;
};

class HttpConversation : public Conversation, public ReaderWriterConversation, public std::enable_shared_from_this<HttpConversation>
{
public:

	typedef std::shared_ptr<HttpConversation> Ptr;
	typedef repro::Promise<Request&,Response&> PromiseType;
	typedef repro::Future<Request&,Response&> FutureType;

	Request req;
	Response res;

	static FutureType on(Connection::Ptr client);

    ~HttpConversation();

	virtual void flush(Response& res);
    virtual void onFlush(std::function<void(Request& req, Response& res)> f);
	virtual void chunk(const std::string& ch);
	virtual bool keepAlive();
	virtual Connection::Ptr con();

	virtual void onHeadersComplete(const std::string& s);
	virtual void onRequestComplete(const std::string& s);
	virtual void onResponseComplete(const std::string& s);
	virtual void onRequestError(const std::exception& s);

	virtual Request& request() { return req; }
	virtual Response& response() { return res; }
	virtual repro::Future<std::string> read();
	virtual repro::Future<> write(const std::string& s);
	virtual void resolve(Request& req, Response& res);
	
private:

	HttpConversation(Connection::Ptr f);

	HttpConversation(const HttpConversation& rhs) = delete;
	HttpConversation(HttpConversation&& rhs) = delete;
	HttpConversation& operator=(const HttpConversation& rhs) = delete;
	HttpConversation& operator=(HttpConversation&& rhs) = delete;

	Connection::Ptr con_;
	PromiseType promise_;

	bool keep_alive_;

	std::unique_ptr<ServerHttpReader> reader_;
	std::unique_ptr<HttpWriter> writer_;

	std::function<void(Request& req, Response& res)> completion_func_;

	Ptr self_;
};

//////////////////////////////////////////////////////////////

} // close namespaces


#endif



