#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <getch.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

//	棋盘数组
char board[15][15];
//	棋子坐标
char key_x = 7,key_y = 7;
//	角色 黑'@' 白'$'
char role = '$';
int sock_fd;
struct sockaddr_in addr;
socklen_t addrlen=sizeof(addr);
typedef struct sockaddr* SP;

//	初始化棋盘
void init_board(short port)
{
	//初始化网络
	sock_fd=socket(AF_INET,SOCK_DGRAM,0);
	if(0>sock_fd)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
	//准备通信地址
	struct sockaddr_in addr={};
	addr.sin_family=AF_INET;
	addr.sin_port=htons(port);
	addr.sin_addr.s_addr=INADDR_ANY;

	if(bind(sock_fd,(SP)&addr,addrlen))
	{
		perror("bind");
		exit(EXIT_FAILURE);
	}

	for(int i=0; i<15; i++)
	{
		for(int j=0; j<15; j++)
		{
			board[i][j] = '*';	
		}
	}
}

//	显示棋盘
void show_board(void)
{
	system("clear");
	for(int i=0; i<15; i++)
	{
		for(int j=0; j<15; j++)
		{
			printf(" %c",board[i][j]);	
		}
		printf("\n");
	}
}

//	落子
void get_key(void)
{
	char buf[256]={};
	size_t buf_size=sizeof(buf);

	if(role=='$')
	{
		printf("等待对方落子...\n");
		int ret=recvfrom(sock_fd,buf,buf_size,0,(SP)&addr,&addrlen);
		if(0>=ret)
		{
			printf("对面逃跑了，恭喜你赢了！\n");
			exit(EXIT_SUCCESS);
		}
		sscanf(buf,"%hhd %hhd",&key_x,&key_y);
		board[key_x][key_y]='@';
	}
	else
	{
		printf("请你落子...\n");
		for(;;)
		{
			printf("\33[%hhd;%hhdH",key_x+1,(key_y+1)*2);
			switch(getch())
			{
				case 183:	key_x>0 && key_x--;	break;	
				case 184:	key_x<14 && key_x++;break;	
				case 186:	key_y>0 && key_y--;	break;	
				case 185:	key_y<14 && key_y++;break;
				case 10:	
						if('*' == board[key_x][key_y])
						{
							board[key_x][key_y] ='$';
							sprintf(buf,"%hhd %hhd",key_x,key_y);
							int ret=sendto(sock_fd,buf,strlen(buf)+1,0,(SP)&addr,addrlen);
							if(0>=ret)
							{
								printf("你掉线了！\n");
								exit(EXIT_FAILURE);
							}
							return;
						}
						break;
			}
		}
	}
}

//	计算某个小方向有连续几个棋子
int count_key(int ox,int oy)
{
	int count = 0;
	for(int x=key_x+ox,y=key_y+oy;
		x>=0 && x<=14 && y>=0 && y<=14; x+=ox,y+=oy)
	{
		if(board[x][y] == board[key_x][key_y])
		{
			count++;	
		}
		else
		{
			return count;	
		}
	}
	return count;
}

//	检查是否五子连珠
bool is_win(void)
{
	if(count_key(-1,0)+count_key(1,0) >= 4)	return true;
	if(count_key(0,-1)+count_key(0,1) >= 4)	return true;
	if(count_key(-1,-1)+count_key(1,1)>= 4) return true;
	if(count_key(-1,1)+count_key(1,-1)>= 4)	return true;
	return false;
}

int main(int argc,const char* argv[])
{
	if(2!=argc)
	{
		printf("User:./recv port\n");
		return EXIT_SUCCESS;
	}

	init_board(atoi(argv[1]));

	for(;;)
	{
		show_board();	
		get_key();
		if(is_win())
		{
			show_board();
			printf("%c胜利\n",board[key_x][key_y]);
			return 0;
		}
		//	交换角色
		role = '@'==role?'$':'@';
	}
}
