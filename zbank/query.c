#include <stdio.h>
#include <unistd.h>
#include "bank.h"
#include "msgq.h"

Msg_ctos ctos={};
Msg_stoc stoc={};

void query_acc(void)
{
	printf("recv from %u:%s %lf\n",ctos.return_type,ctos.acc.card_id,ctos.acc.balance);
	//处理具体任务
	
	//准备提示信息
	stoc.type=ctos.return_type;
	sprintf(stoc.info,"You Query success!\n");
}

int main(int arcg,const char* argv[])
{
	printf("argv:%s\n",argv[0]);
	
	//获取消息队列
	int msgid=get_msg(ACCOUNT_PATH,SUBP_CNT);

	for(;;)
	{
		recv_msg(msgid,&ctos,sizeof(Msg_ctos),MSGTY_QUERY);
		query_acc();
		send_msg(msgid,&stoc,sizeof(Msg_stoc));
	}
}