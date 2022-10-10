#ifndef NETWORK_H
#define NETWORK_H

/*
1、struct class关键字可以省略
2、bool不需要加头文件 C++的关键字
3、如果自行定义了构造函数，则不再自动生成无参构造
4、结构/联合/类 都有构造、析构、拷贝构造、赋值等函数
5、class中成员默认是private属性 struct中默认public属性
6、构造函数没有返回值，且能重载
7、析构函数没有返回值、参数，不能重载
8、只能在构造函数进行初始化列表，写在定义处
9、函数还可以设置默认形参，声明可以写，定义不可以写
10、函数可以重载
11、通过域限定符:: 可以指定访问同名的成员函数/全局函数
12、通过域限定符:: 访问被同名的局部变量屏蔽的全局变量
13、类中的成员函数可以直接使用成员变量
14、任意类型的指针可以自动转成void*,void* 不能自动转换其他类型指针，必须使用强制类型转换 static_cast
*/

#include <cstdio>
#include <netinet/in.h>

typedef sockaddr* SP;

class NetWork
{
	int sock;
	int type;
	sockaddr_in addr;
	socklen_t addrlen;
	bool is_svr;
public:
	NetWork(void);
	NetWork(int type,const char* ip,short port,bool is_svr=false);
	~NetWork(void);
	bool open(void);	//创建socket
	NetWork* accept(void);
	int send(const void* buf,size_t len,int flag=0);
	int send(const void* buf,int flag=0);
	int recv(void* buf,size_t len,int flag=0);
};

#endif//NETWORK_H
