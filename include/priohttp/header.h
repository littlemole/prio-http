#ifndef INCLUDE_PROMISE_HTTP_HEADER_H_
#define INCLUDE_PROMISE_HTTP_HEADER_H_

#include "priohttp/common.h"
#include "priocpp/common.h"
#include "priohttp/cookie.h"
 

namespace prio  {


class HeaderValue
{
public:

	HeaderValue(const std::string& s);

	std::string main() const;
	std::map<std::string,std::string> params() const;

private:
	std::string value_;
};


class HeaderValues
{
public:

	HeaderValues(const std::string& val);

	size_t size() const;
	const HeaderValue& operator[](size_t index) const;
	const HeaderValue& value() const;

private:
	std::vector<HeaderValue> values_;
};

typedef std::pair<std::string,std::string> header_t;
typedef std::vector<header_t> headers_t;

class Headers
{
public:

    std::string toString() const;
    bool exists(const std::string& key) const noexcept;
    std::string get(const std::string& key) const noexcept;
    std::string accept() const noexcept;
    std::string content_type() const noexcept;
    size_t 		content_length() const;

    const Cookies& cookies() const noexcept;
    Headers& cookie(const Cookie& c);

    bool keep_alive(const std::string& proto)  const noexcept;

    Headers& set(const std::string& key, const std::string& value) ;

    void reset() noexcept;

    bool parse( std::istringstream& h);

    HeaderValues values(const std::string& key)
    {
    	return get(key);
    }

    std::vector<std::pair<std::string,std::string>>& raw()
    {
        return headers_;
    }

    Headers()
    {}

    Headers(const std::vector<std::pair<std::string,std::string>>& h)
    {
        for ( auto& it : h)
        {
            set(it.first,it.second);
        }
    }

private:

    std::vector<std::pair<std::string,std::string>> headers_;
    Cookies cookies_;
};



}

#endif /* INCLUDE_PROMISE_HTTP_HEADER_H_ */
