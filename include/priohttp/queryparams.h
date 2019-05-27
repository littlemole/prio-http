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

    bool exists(const std::string& key) const;
    std::string get(const std::string& key) const;
    std::set<std::string> keys() const;
    std::vector<std::string> array(const std::string& key) const;

    void remove(const std::string& key);

    void set(const std::string& key, const std::string& value);
    void add(const std::string& key, const std::string& value);
    std::string& operator[] (const std::string& key);
    std::string toString() const;

protected:
    std::vector<std::pair<std::string,std::string>> params_;
};

} // close namespaces

#endif

