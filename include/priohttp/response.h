#ifndef _MOL_DEF_GUARD_DEFINE_MOD_HTTP_RESPONSE_DEF_GUARD_
#define _MOL_DEF_GUARD_DEFINE_MOD_HTTP_RESPONSE_DEF_GUARD_

#include "priohttp/request.h"
#include "priohttp/header.h"
#include "priohttp/compress.h"
   
//////////////////////////////////////////////////////////////

namespace prio  {


class Conversation;
class HttpClientConversation;


//////////////////////////////////////////////////////////////

class Response
{
friend class HttpConversation;
public:

    Headers headers;
    Attributes attributes;

    Response(Conversation* rp);
        
    // setters

    Response& contentType(const std::string& val);
    Response& header(const std::string& key, const std::string& val);
    Response& body(const std::string& b);
    
    Response& cookie(const Cookie& c);    
        
    void statusCode(int);
    void proto(const std::string& p);

    Response& status(const std::string& s);

    // status setter helpers

    Response& ok();
    Response& error();
    Response& bad_request();
    Response& unauthorized();
    Response& forbidden();
    Response& not_found();
    Response& redirect(const std::string& s, int code = 302);
    Response& gzip();

    // getters

    const std::string& status() const noexcept;
    const std::string& proto() const noexcept;
    int statusCode() const noexcept;
    const std::string& body() const noexcept;
    size_t size() const noexcept;
    
    std::string toString();

    // methods

    void chunk(const std::string& ch);

    void flush();

    bool isChunked() { return isChunked_; }

    bool isGzipped() { return isGzipped_; }

protected:

    Response(const Response&) = delete;
    Response(Response&&) = delete;
    Response& operator=(const Response&) = delete;
    Response& operator=(Response&&) = delete;

    Conversation* http_;
    std::string status_;
    std::string proto_;
    int status_code_;
    std::string body_;
    size_t size_;
    bool headersSent_;
    bool isChunked_;
    bool isGzipped_;
};




class HttpResponse : public Response
{
friend class HttpConversation;
public:

	HttpResponse(Conversation* rp);

	HttpResponse& reset();

    void size(size_t);

    void onFlush(std::function<void(Request& req, Response& res)> f);

    bool headersSent() { return headersSent_; }

    void isChunked(bool b) { isChunked_ = b; }

    void flushHeaders();

private:

    HttpResponse(const HttpResponse&) = delete;
    HttpResponse(HttpResponse&&) = delete;
    HttpResponse& operator=(const HttpResponse&) = delete;
    HttpResponse& operator=(HttpResponse&&) = delete;
};



} // close namespaces
#endif

