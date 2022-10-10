#include "game2048.h"
#include "direction.h"
#include "tools.h"

void up(void)
{
	//debug("%s\n",__func__);
    for(int y=0;y<4;y++)
    {
    	int end=0;
        for(int x=1;x<4;x++)
        {
            for(int k=x;k>end;k--)
            {
            	if(game[k][y]&&0==game[k-1][y])
            	{
            		game[k-1][y]=game[k][y];
            		game[k][y]=0;
            		is_move_merge=true;
            	}
            	else if(game[k][y]&&game[k][y]==game[k-1][y])
                {
                    game[k-1][y]*=2;
                    game[k][y]=0;
                    end=k;
                    is_move_merge=true;
                }
            }
        }
    }
}

void down(void)
{
	//debug("%s\n",__func__);
    for(int y=0;y<4;y++)
    {
    	int end=3;
        for(int x=2;x>=0;x--)
        {
            for(int k=x;k<end;k++)
            {
            	if(game[k][y]&&0==game[k+1][y])
            	{
            		game[k+1][y]=game[k][y];
            		game[k][y]=0;
            		is_move_merge=true;
            	}
            	else if(game[k][y]&&game[k][y]==game[k+1][y])
                {
                    game[k+1][y]*=2;
                    game[k][y]=0;
                    end=k;
                    is_move_merge=true;
                }
            }
        }
    }
}

void left(void)
{
	//debug("%s\n",__func__);
    for(int x=0;x<4;x++)
    {
    	int end=0;
        for(int y=1;y<4;y++)
        {
            for(int k=y;k>end;k--)
            {
            	if(game[x][k]&&0==game[x][k-1])
            	{
            		game[x][k-1]=game[x][k];
            		game[k][y]=0;
            		is_move_merge=true;
            	}
            	else if(game[x][k]&&game[x][k]==game[x][k-1])
                {
                    game[x][k-1]*=2;
                    game[x][k]=0;
                    end=k;
                    is_move_merge=true;
                }
            }
        }
    }
}

void right(void)
{
	//debug("%s\n",__func__);
    for(int x=0;x<4;x++)
    {
    	int end=3;
        for(int y=2;y>=0;y--)
        {
            for(int k=y;k<end;k++)
            {
            	if(game[x][k]&&0==game[x][k+1])
            	{
            		game[x][k+1]=game[x][k];
            		game[k][y]=0;
            		is_move_merge=true;
            	}
            	else if(game[x][k]&&game[x][k]==game[x][k+1])
                {
                    game[x][k+1]*=2;
                    game[x][k]=0;
                    end=k;
                    is_move_merge=true;
                }
            }
        }
    }
}
