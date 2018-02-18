#include <sstream>
#include <fstream>
#include <openssl/ssl.h>



#ifndef _WIN32
#include <dirent.h>

#else
#include "priohttp/msdirent.h"
#include <stdlib.h>  
#define PATH_MAX MAX_PATH
#endif
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex>

#include "priohttp/common.h"

#include <limits.h>
#include <stdlib.h>

#ifdef _WIN32
#include <inttypes.h>
typedef int ssize_t;
#endif

#include <nghttp2/nghttp2.h>
#include "priocpp/impl/event.h"
#include "priocpp/impl/asio.h"

namespace prio  {


std::vector<std::string> split(const std::string &s, char delim, std::vector<std::string> &elems) 
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        if(!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) 
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}


std::vector<std::string> split(const std::string &s, std::string delim)
{
    std::vector<std::string> elems;

    size_t last = 0;
    size_t pos = s.find(delim,last);
    while(pos != std::string::npos)
    {
    	if(pos != 0)
    	{
    		std::string tmp = s.substr(last,pos-last);

    		if(!tmp.empty())
    		{
    			elems.push_back(tmp);
    		}
    	}
    	last = pos + delim.size();
    	pos = s.find(delim,last);
    }

    if ( last < s.size())
    {
    	elems.push_back(s.substr(last));
    }
    return elems;
}

std::vector<std::string> glob(const std::string& f)
{
  DIR           *d;
  struct dirent *dir;
  
  std::vector<std::string> result;
  
  d = opendir(f.c_str());
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
        if (dir->d_type == DT_REG)
        {   
            std::string n = std::string(dir->d_name);
            if ( n != "." && n != "..")
            {
                result.push_back(dir->d_name);
            }
        }
    }
    closedir(d);
  }
  return result;
}

std::string safe_path( const std::string& path )
{
    std::regex e ("\\.\\.");
    return std::regex_replace(path,e,"");
}

#ifndef _WIN32
std::string realpath(const std::string& path)
{
	char buf[PATH_MAX];
	::realpath(path.c_str(),buf);
	return buf;
}
#endif

std::string slurp( const std::string& fp )
{
    std::ostringstream oss;
    std::ifstream ifs;
    ifs.open(fp,std::ios::binary);
    if(!ifs)
    {
        return "";
    }

    while(ifs)
    {
        char buf[4096];
        ifs.read(buf,4096);
        std::streamsize s = ifs.gcount();
        oss.write(buf,s);
    }

    ifs.close();
    return oss.str();
}

unsigned char next_proto_list[256];
size_t next_proto_list_len;

int next_proto_cb(SSL *ssl, const unsigned char **data,unsigned int *len, void *arg) 
{
  *data = next_proto_list;
  *len = (unsigned int)next_proto_list_len;
  return SSL_TLSEXT_ERR_OK;
}

#if OPENSSL_VERSION_NUMBER >= 0x10002000L
int alpn_select_proto_cb(SSL *ssl, const unsigned char **out,
          unsigned char *outlen, const unsigned char *in,
		  unsigned int inlen, void *arg) 
{
  int rv = nghttp2_select_next_protocol((unsigned char **)out, outlen, in, inlen);

  if (rv != 1) {
    return SSL_TLSEXT_ERR_NOACK;
  }

  return SSL_TLSEXT_ERR_OK;
}
#endif // OPENSSL_VERSION_NUMBER >= 0x10002000L



#ifdef PROMISE_USE_LIBEVENT

struct Http2SslCtxImpl : public SslCtxImpl
{
	Http2SslCtxImpl();
	~Http2SslCtxImpl();
	
	void enableHttp2();
	void enableHttp2Client();
};



Http2SslCtxImpl::Http2SslCtxImpl()
{
}

Http2SslCtxImpl::~Http2SslCtxImpl()
{
}

/*
int next_proto_cb(SSL *ssl, const unsigned char **data,unsigned int *len, void *arg);

#if OPENSSL_VERSION_NUMBER >= 0x10002000L
int alpn_select_proto_cb(SSL *ssl, const unsigned char **out,
          unsigned char *outlen, const unsigned char *in,
		  unsigned int inlen, void *arg);
#endif
*/
/*
void Http2SslCtxImpl::loadKeys( const std::string& keyfile )
{
	if(!(SSL_CTX_use_certificate_chain_file(ctx,	keyfile.c_str())))
		throw repro::Ex("Can't read certificate file");

	if(!(SSL_CTX_use_PrivateKey_file(ctx,keyfile.c_str(),SSL_FILETYPE_PEM)))
		throw repro::Ex("Can't read key file");
	  
}
*/

void Http2SslCtxImpl::enableHttp2(  )
{
	next_proto_list[0] = NGHTTP2_PROTO_VERSION_ID_LEN;
	memcpy(&next_proto_list[1], NGHTTP2_PROTO_VERSION_ID,
	NGHTTP2_PROTO_VERSION_ID_LEN);
	next_proto_list_len = 1 + NGHTTP2_PROTO_VERSION_ID_LEN;
	
	SSL_CTX_set_next_protos_advertised_cb(ctx, next_proto_cb, NULL);
	
#if OPENSSL_VERSION_NUMBER >= 0x10002000L
	SSL_CTX_set_alpn_select_cb(ctx, alpn_select_proto_cb, NULL);
#endif // OPENSSL_VERSION_NUMBER >= 0x10002000L
	  
}

static int select_next_proto_cb(SSL *ssl, unsigned char **out,
	unsigned char *outlen, const unsigned char *in,
	unsigned int inlen, void *arg) 
{
	if (nghttp2_select_next_protocol(out, outlen, in, inlen) <= 0) 
	{
		std::cout << "err select_next_proto_cb ACK failed -no http2" << std::endl;
		return SSL_TLSEXT_ERR_NOACK;
	}
	return SSL_TLSEXT_ERR_OK;
}

void Http2SslCtxImpl::enableHttp2Client(  )
{
	next_proto_list[0] = NGHTTP2_PROTO_VERSION_ID_LEN;
	memcpy(&next_proto_list[1], NGHTTP2_PROTO_VERSION_ID,
	NGHTTP2_PROTO_VERSION_ID_LEN);
	next_proto_list_len = 1 + NGHTTP2_PROTO_VERSION_ID_LEN;

	SSL_CTX_set_next_proto_select_cb(ctx, select_next_proto_cb, NULL);
	
#if OPENSSL_VERSION_NUMBER >= 0x10002000L
	  SSL_CTX_set_alpn_protos(ctx, (const unsigned char *)"\x02h2", 3);
#endif // OPENSSL_VERSION_NUMBER >= 0x10002000L	  
}



Http2SslCtx::Http2SslCtx()
{
    ctx.reset(new Http2SslCtxImpl());
}

Http2SslCtx::~Http2SslCtx()
{
}


void Http2SslCtx::load_cert_pem(const std::string& file)
{
	ctx->loadKeys(file);
}


void Http2SslCtx::enableHttp2()
{
	((Http2SslCtxImpl*)(ctx.get()))->enableHttp2();
}


void Http2SslCtx::enableHttp2Client()
{
	((Http2SslCtxImpl*)(ctx.get()))->enableHttp2Client();
}


#endif // USE_LIBEVENT



} // end namespaces


