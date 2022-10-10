#include "phone_book.h"
#include "tools.h"

int main(void)
{
	for(;;)
	{
		//显示主界面
		switch(menu())
		{
			case '1': add(); break;
			case '2': del(); break;
			case '3': mod(); break;
			case '4': find(); break;
			case '5': show(); break;
			case '6': return 0;
		}	
	}
}
