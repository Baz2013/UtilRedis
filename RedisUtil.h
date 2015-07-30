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
		string get(const string &key);
		bool set(const string &key,const string &value);
		bool set(const string &key,const int value);
		bool set(const map<string,string> &strMap);
		int strlen(const string &key);
		bool append(const string &key,const string &value);
		bool incr(const string &key);
		bool incrby(const string &key,const int increment);
		bool incrbyfloat(const string &key,const float increment);
		bool decr(const string &key);
		bool decrby(const string &key,const int decrement);

	private:
		bool keyExists(const string &key);
		bool valueIsNum(const string &key);
		bool strIsDigit(const string &str);
};

#endif
