#ifndef INCLUDE_PROMISE_HTTP_ATTR_H_
#define INCLUDE_PROMISE_HTTP_ATTR_H_

#include "priohttp/common.h"
#ifndef _WIN32
#ifdef __clang__
#include <boost/any.hpp>
#else
#include <experimental/any>
#endif
#else
#include <boost/any.hpp>
//#include <any>
#endif

namespace prio  {


#ifndef _WIN32
#ifdef __clang__
	typedef boost::any any;
#else
	typedef std::experimental::any any;
#endif	
#else
	typedef boost::any any;
#endif

template<class T>
auto any_cast(T&& t)
{
#ifndef _WIN32
#ifdef __clang__
	return boost::any_cast<T>(std::forward<T>(t));
#else
	return std::experimental::any_cast<T>(std::forward<T>(t));
#endif
#else
	return std::any_cast<T>(std::forward<T>(t));
#endif
}

class Attributes
{
public:

    // attribute getters
    bool exists( const std::string& key ) const noexcept;
    any get( const std::string& key ) const;


    template<class T>
    T attr(const std::string& key) const
    {
    	try
    	{
            return any_cast<T>(get(key));
    	}
    	catch(...)
    	{
    		throw repro::Ex("key not found");
    	}
    }

    // attribute setter
    void set( const std::string& key, const any& a );

    template<class T>
	void set(const std::string& key, T a )
	{
    	set( key, any(a) );
	}

    void reset();

private:
    std::map<std::string,any> attrs_;
};

}



#endif /* INCLUDE_PROMISE_HTTP_ATTR_H_ */
