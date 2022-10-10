#include "game2048.h"
#include "tools.h"
#include <stdlib.h>
#include <time.h>
#include <getch.h>
#include "direction.h"

int (*game)[4]=NULL;
int score=0;
// 判断是否产生移动、合并标志
bool is_move_merge=true;

//初始化相关数据/加载数据
void init_game(void)
{
	debug("%s\n",__func__);
	//申请堆内存
	game=calloc(sizeof(game[0][0]),16);
	//数据初始化
	srand(time(NULL));
	//读取文件，加载数据
}

//运行游戏
void start_game(void)
{
	debug("%s\n",__func__);
	for(;;)
	{
		//随机位置生成2
		rand_two();
		
		is_move_merge=false;
		//显示界面
		show_view();
		//检查是否还能继续
		if(is_die())
		{
			printf("游戏失败!");
			return;
		}
		//获取方向键并处理
		switch(getch())
		{
			case 183: up(); break;
			case 184: down(); break;
			case 186: left(); break;
			case 185: right(); break;
		}
		
		

	}
}

//释放相关资源、保存数据
void end_game(void)
{
	debug("%s\n",__func__);
	//保存数据
	//释放堆内存
	free(game);
	game=NULL;
	
}
