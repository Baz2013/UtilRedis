#include"RedisUtil.h"

RedisUtil::RedisUtil(){
	;
}

/**
 * 初始化redis连接
 **/
bool RedisUtil::initial(const string &host,const int port){
	m_redisConn = redisConnect(host.c_str(),port);
	if( m_redisConn->err != REDIS_OK)
	{
#ifdef debug
		cout<<"连接Redis数据库失败"<<endl;
		cout<<"错误信息为:[err_code:"<<m_redisConn->err<<",err_msg:"<<m_redisConn->errstr<<"]"<<endl;
#endif
		return false;
	}
	return true;
}

/**
 * 初始化redis连接 , 带有超时限制
 **/
bool RedisUtil::initial(const string &host,const int port,const struct timeval tv){
	return true;
}
