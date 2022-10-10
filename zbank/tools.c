#include <getch.h>
#include "tools.h"

int get_cmd(char start,char end)
{
	puts("请输入指令：");
	for(;;)
	{
		char cmd=getch();
		if(start<=cmd && end>=end)
		{
			printf("%c\n",cmd);
			return cmd;
		}
	}
}
