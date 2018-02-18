#ifndef _MOL_DEF_GUARD_DEFINE_MOD_HTTP_REQUEST_DEF_GUARD_
#define _MOL_DEF_GUARD_DEFINE_MOD_HTTP_REQUEST_DEF_GUARD_

#include "priohttp/common.h"
#include "priohttp/arg.h"
#include "priohttp/path.h"
#include "priohttp/header.h"
#include "priohttp/attr.h"
#include "priohttp/queryparams.h"
#include "priocpp/api.h"
 
#include <regex>
   
//////////////////////////////////////////////////////////////

namespace prio  {

class HttpRequestParser;
class Conversation;


class Request
{
friend class HttpRequestParser;

public:

	PathInfo path;
	Headers headers;
	Attributes attributes;

	Request();
    Request(Conversation* con);
        
    const std::string& body() const noexcept;
    
    Connection::Ptr con()  const noexcept;
    bool keep_alive()  const noexcept;
    bool detached()  const noexcept;

    size_t size() const noexcept;
    std::string toString();

protected:

    Conversation* con_;
    size_t size_;
    std::string body_;
    bool detached_;
};


class HttpRequest : public Request
{
friend class HttpRequestParser;

public:

	HttpRequest();
	HttpRequest(Conversation* con);

    void action(const std::string& a);
    Request& header(const std::string& key, const std::string& value) ;
    void body(const std::string& b);
    
    void detach() noexcept;

    void reset() noexcept;

    bool match(const std::string& method, std::regex regex, std::vector<std::string> args);

    void size(size_t  s) { size_ = s; };

    bool parse(const std::string& h);

};


} // close namespaces

#endif

