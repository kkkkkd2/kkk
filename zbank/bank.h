#ifndef BANK_H
#define BANK_H

#include <sys/types.h>
#include <unistd.h>

#define MSGTY_OPEN (1)
#define MSGTY_DESTORY (2)
#define MSGTY_LOGIN (3)
#define MSGTY_UNLOCK (4)
#define MSGTY_QUERY (5)
#define MSGTY_TAKE (6)
#define MSGTY_SAVE (7)
#define MSGTY_TRANSFER (8)
#define MSGTY_REPASS (9)

#define SUBP_CNT (9)	//子进程的数量
#define ACCOUNT_PATH "./accounts"	//帐号文件路径
#define ID_PATH "./accounts/.id.dat"	//生成帐号文件

//帐号结构体
typedef struct Account
{
	double balance;		//余额
	char card_id[20];	//卡号
	char id[19];		//身份证号
	char pass[7];		//密码
	char is_lock;		//是否锁定
}Account;

//客户端发送服务器 消息结构体
typedef struct Msg_ctos
{
	long type;			//消息类型
	Account acc;
	pid_t return_type;	//客户端的pid
}Msg_ctos;

typedef struct Msg_stoc
{
	long type;			//客户端的pid
	char info[256];		//提示信息
}Msg_stoc;

#endif//BANK_H
