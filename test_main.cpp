#include<iostream>
#include<stdlib.h>
#include<string>
#include"RedisUtil.h"

using namespace std;

int main(int argc,char **argv)
{
	RedisUtil r_util ;
	if (!r_util.initial("127.0.0.1",6379))
	{
		cout<<"连接redis数据库失败"<<endl;
		exit(1);
	}

	string str = r_util.get("name");
	cout<<str<<endl;
	r_util.set("qq","1678104640");
	
	r_util.set("mail","sd4313@163.com");
	int len = r_util.strlen("qq");
	cout<<"qq lenght is:"<<len<<endl;

	r_util.append("name"," chuan bing");

	return 0;
}

