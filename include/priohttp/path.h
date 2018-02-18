#ifndef INCLUDE_PROMISE_HTTP_PATH_H_
#define INCLUDE_PROMISE_HTTP_PATH_H_

#include "priohttp/common.h"
#include "priohttp/arg.h"
#include "priohttp/queryparams.h"


namespace prio  {

class PathInfo
{
public:

	const std::string& action() const noexcept  {return action_; }
	const std::string& protocol() const noexcept  {return protocol_; }
    const std::string& method() const noexcept;
    const std::string& url() const noexcept;
    std::string path() const noexcept;
    std::string querystring() const noexcept;

    patharguments_t path_info()  const noexcept;

    QueryParams queryParams() const;
    Args args() const noexcept;

    void reset() noexcept;

    void action(const std::string& a);
    void method(const std::string& m)   { method_ = m; };
    void path(const std::string& p)     { path_ = p; };
    void protocol(const std::string& p) { protocol_ = p; };

    void set(pathargument_t t)
    {
    	args_.push_back(t);
    }

    std::string operator()() { return path(); }

    bool parse(const std::string& h);

private:

    std::string action_;
    std::string method_;
    std::string path_;
    std::string protocol_;

    patharguments_t args_;
};


}


#endif /* INCLUDE_PROMISE_HTTP_PATH_H_ */
