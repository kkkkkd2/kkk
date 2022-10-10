#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "network.h"
using namespace std;

#define BUF_SIZE (4096)

void* run(void* arg)
{
	NetWork* cnw = static_cast<NetWork*>(arg);

	char* buf = new char[BUF_SIZE];
	for(;;)
	{
		int ret = cnw->recv(buf,BUF_SIZE);
		if(0 >= ret || 0 == strncmp(buf,"quit",4))
		{
			cout << "客户端退出" << endl;
			delete[] buf;
			delete cnw;
			return NULL;
		}
		printf("recv:%s\n",buf);
		strcat(buf,":return");
		ret = cnw->send(buf);
		if(0 >= ret)
		{
			cout << "客户端退出" << endl;
			delete[] buf;
			delete cnw;
			return NULL;
		}
	}
}

int main(int argc,const char* argv[])
{
	if(3 != argc)
	{
		puts("User: ./server <ip> <port>");
		return 0;
	}

	NetWork* snw = 
		new NetWork(SOCK_STREAM,argv[1],atoi(argv[2]),true);
	if(!snw->open())
	{
		delete snw;
		return -1;
	}

	for(;;)
	{
		NetWork* cnw = snw->accept();
		if(NULL == cnw)	continue;

		pthread_t tid;
		pthread_create(&tid,NULL,run,cnw);
	}
}



