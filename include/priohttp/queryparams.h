#ifndef _MOL_DEF_GUARD_DEFINE_MOD_HTTP_REQUEST_PARAMS_DEF_GUARD_
#define _MOL_DEF_GUARD_DEFINE_MOD_HTTP_REQUEST_PARAMS_DEF_GUARD_

#include "priohttp/common.h"

namespace prio  {

class QueryParams
{
public:

    QueryParams();
    QueryParams(const std::string& s);

    bool exists(const std::string& key);
    std::string get(const std::string& key);
    std::vector<std::string> keys();
        
    void set(const std::string& key, const std::string& value);
    std::string& operator[] (const std::string& key);
    std::string toString();

private:
    std::map<std::string,std::string> params_;
};

} // close namespaces

#endif

