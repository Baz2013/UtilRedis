#ifndef _REDIS_UTIL_H_
#define _REDIS_UTIL_H_

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include"hiredis/hiredis.h"

using namespace std;

class RedisUtil{
	private:
		redisContext *m_redisConn;
		redisReply *m_redisReply;


	public:
		RedisUtil();
		bool initial(const string &host,const int port);
		bool initial(const string &host,const int port,const struct timeval tv);
		~RedisUtil();
};

#endif
