#include "priohttp/attr.h"


namespace prio  {


void Attributes::set( const std::string& key,const any& a )
{
    attrs_.insert( std::pair<std::string,any>( key, a ) );
}

any Attributes::get( const std::string& key ) const
{
    if ( attrs_.count(key) == 0 )
    {
        return any(nullptr);
    }
    return attrs_.at(key);
}

bool Attributes::exists( const std::string& key ) const noexcept
{
    return attrs_.count(key) > 0;
}

void Attributes::reset()
{
	attrs_.clear();
}

}
