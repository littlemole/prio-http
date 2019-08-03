#ifndef INCLUDE_PROMISE_HTTP_ATTR_H_
#define INCLUDE_PROMISE_HTTP_ATTR_H_

//! \file attr.h

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

//! any_cast wrapper for various compilers
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

//! \brief Generic Attributes 
//! 
//! attached to HTTP request/response
//! stores attributes as std::any objects
class Attributes
{
public:

    //! cgeck whether attribute exists
    bool exists( const std::string& key ) const noexcept;
	//! get specific object as a std::any object
    any get( const std::string& key ) const;

	//! fetch attribute of type T for the given key
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

    //! set attribute as std::any object
    void set( const std::string& key, const any& a );

	//! set object a of tyoe T as attribute under given key
    template<class T>
	void set(const std::string& key, T a )
	{
    	set( key, any(a) );
	}

	//! clear attributes
    void reset();

private:
    std::map<std::string,any> attrs_;
};

}



#endif /* INCLUDE_PROMISE_HTTP_ATTR_H_ */
