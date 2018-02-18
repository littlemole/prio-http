#include "priohttp/queryparams.h"
#include "priohttp/urlencode.h"

namespace prio  {

QueryParams::QueryParams()
{

}

QueryParams::QueryParams(const std::string& s)
{
    std::vector<std::string> v = split(s,'&');
    for ( size_t i = 0; i < v.size(); i++ )
    {
        if ( !v[i].empty() )
        {
            std::vector<std::string> p = split(v[i],'=');
            if ( p.size() > 1 )
            {
                params_[Urlencode::decode(p[0])] = Urlencode::decode(p[1]);
            }
        }
    }
}

std::string QueryParams::get(const std::string& key)
{
    if ( params_.count(key) == 0 )
    {
        return "";
    }
    
    return params_[key];
}

std::vector<std::string> QueryParams::keys()
{
	std::vector<std::string> v;
	for ( auto it = params_.begin(); it != params_.end(); it++)
	{
		v.push_back(it->first);
	}
	return v;
}

void QueryParams::set(const std::string& key, const std::string& value)
{
	params_[key] = value;
}

std::string& QueryParams::operator[] (const std::string& key)
{
	return params_[key];
}

std::string QueryParams::toString()
{
	std::ostringstream oss;
	for ( auto it = params_.begin(); it != params_.end(); it++)
	{
		oss << (*it).first << "=" << Urlencode::encode( (*it).second ) << "&";
	}
	std::string tmp = oss.str();
	tmp.pop_back();
	return tmp;
}




} // close namespaces

