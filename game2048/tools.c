#include <stdlib.h>
#include "game2048.h"
#include "tools.h"

//判断是否有满
static bool is_full(void)
{
	int* num=(int*)game;
	for(int i=0;i<16;i++)
	{
		if(0==num[i]) return false;
	}
	return true;
}

void rand_two(void)
{
	if(is_full())
	{
		debug("没有空位置\n");
		return;
	}
	for(;is_move_merge;)
	{
		int x=rand()%4;
		int y=rand()%4;
		if(0==game[x][y])
		{
			game[x][y]=2;
			return;
		}
	}
}

void show_view(void)
{
	system("clear");
	for(int i=0;i<4;i++)
	{	
		printf("---------------------\n");
		for(int j=0;j<4;j++)
		{
			if(game[i][j]) printf("|%4d",game[i][j]);
			else printf("|    ");
		}
		printf("|\n");
	}
	printf("---------------------\n");
}

bool is_die(void)
{
	if(!is_full()) return false;
	for(int y=0;y<4;y++)
	{
		for(int x=0;x<3;x++)
		{
			if(game[x][y]==game[x+1][y]) return false;
		}
	}
	for(int x=0;x<4;x++)
	{
		for(int y=0;y<3;y++)
		{
			if(game[x][y]==game[x][y+1]) return false;
		}
	}
	return true;
}
