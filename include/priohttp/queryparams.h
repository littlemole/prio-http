#ifndef _MOL_DEF_GUARD_DEFINE_MOD_HTTP_REQUEST_PARAMS_DEF_GUARD_
#define _MOL_DEF_GUARD_DEFINE_MOD_HTTP_REQUEST_PARAMS_DEF_GUARD_

#include "priohttp/common.h"
#include <set>

namespace prio  {

class QueryParams
{
public:

    QueryParams();
    QueryParams(const std::string& s);

    bool exists(const std::string& key);
    std::string get(const std::string& key);
    std::set<std::string> keys();
    std::vector<std::string> array(const std::string& key);

    void remove(const std::string& key);

    void set(const std::string& key, const std::string& value);
    void add(const std::string& key, const std::string& value);
    std::string& operator[] (const std::string& key);
    std::string toString();

protected:
    std::vector<std::pair<std::string,std::string>> params_;
};

} // close namespaces

#endif

