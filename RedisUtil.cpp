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

RedisUtil::~RedisUtil(){
	freeReplyObject(m_redisReply);
	redisFree(m_redisConn);
}

string RedisUtil::get(const string &key){
	string value = "";
	m_redisReply = (redisReply *)redisCommand(m_redisConn,"get %s",key.c_str());
	if( m_redisReply->type == REDIS_REPLY_NIL )
	{
#ifdef debug
		cout<<"不存在的键"<<endl;
#endif
	}else if( m_redisReply->type != REDIS_REPLY_STRING){
		cout<<"execute command failed!!"<<endl;
	}
	value = m_redisReply->str;

	return value;
}

bool RedisUtil::set(const string &key,const string &value){
	m_redisReply = (redisReply *)redisCommand(m_redisConn,"set %s %s",key.c_str(),value.c_str());
	if( m_redisReply == NULL){
		cout<<"execute redis command [set "<<key<<" " <<value<<" failed!!"<<endl;
		return false;
	}

	return true;
}
