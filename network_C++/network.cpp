#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include "network.h"

NetWork::NetWork(void)
{
	addrlen=sizeof(addr);
	type=SOCK_STREAM;
	is_svr=true;
}

NetWork::NetWork(int type,const char* ip,short port,bool is_svr):type(type),is_svr(is_svr)
{
	//不在构造函数创建socket，因为有可能会失败，但是构造函数没有返回值，因此不适合在此创建
	addr.sin_family=AF_INET;
	addr.sin_port=htons(port);
	addr.sin_addr.s_addr=inet_addr(ip);
	addrlen=sizeof(addr);
}

NetWork::~NetWork(void)
{
	close(sock);
}

bool NetWork::open(void)	//创建socket
{
	sock=socket(AF_INET,type,0);
	if(0>sock)
	{
		perror("NetWork::open");
		return false;
	}

	//服务器端
	if(is_svr)
	{
		if(bind(sock,(SP)&addr,addrlen))
		{
			perror("bind");
			return false;
		}
		//TCP
		if(SOCK_STREAM==type && listen(sock,50))
		{
			perror("listen");
			return false;
		}
	}
	else if(SOCK_STREAM==type && connect(sock,(SP)&addr,addrlen))
	{
		perror("connect");
		return false;
	}
	return true;
}

NetWork* NetWork::accept(void)
{
	if(SOCK_STREAM!=type||!is_svr)
	{
		puts("只有type为SOCK_STREAM且为服务端才能调用此函数");
		return NULL;
	}

	NetWork* nw=new NetWork;//调用NetWork无参构造，需要重载

	nw->sock=::accept(sock,(SP)&nw->addr,&nw->addrlen);
	if(0>nw->sock)
	{
		perror("NetWork::accept");
		delete nw;
		return NULL;
	}
	return nw;
}

int NetWork::send(const void* buf,size_t len,int flag)
{
	if(SOCK_STREAM==type)
		return ::send(sock,buf,len,flag);
	else
		return sendto(sock,buf,len,flag,(SP)&addr,addrlen);
}

int NetWork::send(const void* buf,int flag)
{
	if(SOCK_STREAM==type)
		return ::send(sock,buf,strlen((char*)buf)+1,flag);
	else
		return sendto(sock,buf,strlen((char*)buf)+1,flag,(SP)&addr,addrlen);
}

int NetWork::recv(void* buf,size_t len,int flag)
{
	if(SOCK_STREAM==type)
		return ::recv(sock,buf,len,flag);
	else
		return recvfrom(sock,buf,len,flag,(SP)&addr,&addrlen);
}
