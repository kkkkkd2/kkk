#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getch.h>

//	棋盘数组
char board[15][15];
//	棋子坐标
char key_x = 7,key_y = 7;
//	角色 黑'@' 白'$'
char role = '@';

//	初始化棋盘
void init_board(void)
{
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
	printf("请%c落子",role);
	for(;;)
	{
		printf("\33[%hhd;%hhdH",key_x+1,(key_y+1)*2);
		switch(getch())
		{
			case 183:	key_x>0 && key_x--;	break;	
			case 184:	key_x<14 && key_x++;break;	
			case 186:	key_y>0 && key_y--;	break;	
			case 185:	key_y<14 && key_y++;break;
			case 10:	if('*' == board[key_x][key_y])
						{
							board[key_x][key_y] = role;
							return;
						}
						break;
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
		if(board[x][y] == role)
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
	init_board();
	for(;;)
	{
		show_board();	
		get_key();
		if(is_win())
		{
			show_board();
			printf("%c胜利\n",role);
			return 0;
		}
		//	交换角色
		role = '@'==role?'$':'@';
	}
}
