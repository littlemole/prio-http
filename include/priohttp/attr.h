#ifndef INCLUDE_PROMISE_HTTP_ATTR_H_
#define INCLUDE_PROMISE_HTTP_ATTR_H_

#include "priohttp/common.h"
#include <any>

namespace prio  {


class Attributes
{
public:

    // attribute getters
    bool exists( const std::string& key ) const noexcept;
    std::any get( const std::string& key ) const;


    template<class T>
    T attr(const std::string& key) const
    {
    	try
    	{
            return std::any_cast<T>(get(key));
    	}
    	catch(...)
    	{
    		throw repro::Ex("key not found");
    	}
    }

    // attribute setter
    void set( const std::string& key, const std::any& a );

    template<class T>
	void set(const std::string& key, T a )
	{
    	set( key, std::any(a) );
	}

    void reset();

private:
    std::map<std::string,std::any> attrs_;
};

}



#endif /* INCLUDE_PROMISE_HTTP_ATTR_H_ */
