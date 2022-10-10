#include <stdlib.h>
#include <string.h>
#include <getch.h>
#include "bank.h"
#include "msgq.h"
#include "tools.h"

void menu(void);

int msgid;
Msg_ctos ctos={};
Msg_stoc stoc={};

int main_menu(void)
{
	system("clear");
	puts("****欢迎使用ATM****");
	puts("1.开户	  2.销户");
	puts("3.登录	  4.解锁");
	puts("5.退卡");
	puts("*******************");
	return get_cmd('1','5');
}

void open_acc(void)
{
	puts("请输入身份证号：");
	scanf("%s",ctos.acc.id);
	puts("请输入六位密码：");
	scanf("%s",ctos.acc.pass);
	
	ctos.type=MSGTY_OPEN;
	ctos.acc.balance=0;
	
	send_msg(msgid,&ctos,sizeof(Msg_ctos));
	recv_msg(msgid,&stoc,sizeof(Msg_stoc),ctos.return_type);
	printf("recv:%s\n",stoc.info);
}

void destory_acc(void)
{
	puts("请输入帐号：");
	scanf("%s",ctos.acc.card_id);
	puts("请输入六位密码：");
	scanf("%s",ctos.acc.pass);
	
	ctos.type=MSGTY_DESTORY;
	
	send_msg(msgid,&ctos,sizeof(Msg_ctos));
	recv_msg(msgid,&stoc,sizeof(Msg_stoc),ctos.return_type);
	printf("recv:%s\n",stoc.info);
	if(getch()=='y') ctos.acc.is_lock='y';
	else ctos.acc.is_lock='n';
	send_msg(msgid,&ctos,sizeof(Msg_ctos));
	recv_msg(msgid,&stoc,sizeof(Msg_stoc),ctos.return_type);
	printf("recv:%s\n",stoc.info);
}

void login_acc(void)
{
	puts("请输入帐号：");
	scanf("%s",ctos.acc.card_id);
	puts("请输入六位密码：");
	scanf("%s",ctos.acc.pass);
	
	ctos.type=MSGTY_LOGIN;
	
	send_msg(msgid,&ctos,sizeof(Msg_ctos));
	recv_msg(msgid,&stoc,sizeof(Msg_stoc),ctos.return_type);
	printf("recv:%s\n",stoc.info);
	if(0==strcmp(stoc.info,"You Login success!\n")) menu();
	else return;
}

void unlock_acc(void)
{
	puts("请输入帐号：");
	scanf("%s",ctos.acc.card_id);
	puts("请输入身份证号：");
	scanf("%s",ctos.acc.id);
	
	ctos.type=MSGTY_UNLOCK;
	
	send_msg(msgid,&ctos,sizeof(Msg_ctos));
	recv_msg(msgid,&stoc,sizeof(Msg_stoc),ctos.return_type);
	printf("recv:%s\n",stoc.info);
}

void save_acc(void)
{
	puts("请输入存款金额：");
	scanf("%lf",&ctos.acc.balance);
	
	ctos.type=MSGTY_SAVE;
	
	send_msg(msgid,&ctos,sizeof(Msg_ctos));
	recv_msg(msgid,&stoc,sizeof(Msg_stoc),ctos.return_type);
	printf("recv:%s\n",stoc.info);
}

void take_acc(void)
{
	puts("请输入取款金额：");
	scanf("%lf",&ctos.acc.balance);
	
	ctos.type=MSGTY_TAKE;
	
	send_msg(msgid,&ctos,sizeof(Msg_ctos));
	recv_msg(msgid,&stoc,sizeof(Msg_stoc),ctos.return_type);
	printf("recv:%s\n",stoc.info);
}

void transfer_acc(void)
{
	puts("请输入转账帐号：");
	scanf("%s",ctos.acc.card_id);
	puts("请输入转账金额：");
	scanf("%lf",&ctos.acc.balance);
	
	ctos.type=MSGTY_TRANSFER;
	
	send_msg(msgid,&ctos,sizeof(Msg_ctos));
	recv_msg(msgid,&stoc,sizeof(Msg_stoc),ctos.return_type);
	printf("recv:%s\n",stoc.info);
}

void query_acc(void)
{
	ctos.type=MSGTY_QUERY;
	
	send_msg(msgid,&ctos,sizeof(Msg_ctos));
	recv_msg(msgid,&stoc,sizeof(Msg_stoc),ctos.return_type);
	printf("recv:%s\n",stoc.info);
}

void repass_acc(void)
{
	puts("请输入原密码：");
	scanf("%s",ctos.acc.pass);
	
	ctos.type=MSGTY_REPASS;
	
	send_msg(msgid,&ctos,sizeof(Msg_ctos));
	
	puts("请输入新密码：");
	scanf("%s",ctos.acc.pass);
	
	send_msg(msgid,&ctos,sizeof(Msg_ctos));
	recv_msg(msgid,&stoc,sizeof(Msg_stoc),ctos.return_type);
	printf("recv:%s\n",stoc.info);
}

void menu(void)
{
	while(1)
	{	
		system("clear");
		puts("*********************");
		puts("1.存钱	    2.取钱");
		puts("3.转账	    4.查询");
		puts("5.改密码    6.退出");
		puts("*********************");
		switch(get_cmd('1','6'))
		{	
			case '1':save_acc();break;
			case '2':take_acc();break;
			case '3':transfer_acc();break;
			case '4':query_acc();break;
			case '5':repass_acc();break;
			case '6':return;
		}
	}
}

int main()
{	
	msgid=get_msg(ACCOUNT_PATH,SUBP_CNT);
	ctos.return_type=getpid();
	for(;;)
	{
		switch(main_menu())
		{
			case '1':open_acc();break;
			case '2':destory_acc();break;
			case '3':login_acc();break;
			case '4':unlock_acc();break;
			case '5':return 0;
		}
	}
	/*
	//测试
	int msgid=get_msg(ACCOUNT_PATH,SUBP_CNT);
	Msg_ctos ctos={};
	Msg_stoc stoc={};
	
	sprintf(ctos.acc.card_id,"1001");
	ctos.acc.balance=10.1;
	
	ctos.type=MSGTY_LOGIN;
	ctos.return_type=getpid();
	
	send_msg(msgid,&ctos,sizeof(Msg_ctos));
	recv_msg(msgid,&stoc,sizeof(Msg_stoc),ctos.return_type);
	printf("recv:%s\n",stoc.info);
	*/
}
