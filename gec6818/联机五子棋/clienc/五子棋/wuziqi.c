#include"wuziqi.h"
#include"lcd.h"
 #include <stdio.h>

int s[12][20]={0};
int flag=0;


/*
    初始化棋盘
*/
void map_init(void)
{
    int i,j;
    for(i=1;i<12;i++)
    {
        for(j=0;j<800;j++)
        {
            lcd_draw_point(j,i*40,0);
        }
    }
    for(i=1;i<20;i++)
    {
        for(j=0;j<480;j++)
        {
            lcd_draw_point(i*40,j,0);
        }
    }
}


/*
    调整坐标
*/
void    change_xy(int *x,int *y)
{
    int i,j;
    if(*x<40)
    {
        *x=40;
    }
    if(*x>760)
    {
        *x=760;
    }
    if(*y<40)
    {
        *y=40;
    }
    if(*y>440)
    {
        *y=440;
    }
    i=*x/40;
    j=*y/40;
    if((*x-40*i)>(40*(i+1)-*x))
    {
        *x=40*(i+1);
    }
    else
    {
        *x=40*i;
    }
    if((*y-40*j)>(40*(j+1)-*y))
    {
        *y=40*(j+1);
    }
    else
    {
        *y=40*j;
    }
}



/*
    落子
*/
int luozi(int s[12][20],int x,int y,int *flag)
{
	if(*flag==0)
	{
		if(s[y/40-1][x/40-1]==0)
        { 
            printf("%s %d\n",__FUNCTION__,__LINE__);
            *flag=1;
            s[y/40-1][x/40-1]=1;
            lcd_draw_circle(x,y,18,0);
            return 0;
        }
	}
    else
    {
        if(s[y/40-1][x/40-1]==0)
        { printf("%s %d\n",__FUNCTION__,__LINE__);//打印函数跟行号
            *flag=0;
            s[y/40-1][x/40-1]=2;
            lcd_draw_circle(x,y,18,0x00FFFFFF);
            return 0;
        }
    }
    return 1;
}


/*
    游戏状态
*/
int game_stata(int s[12][20],int x,int y,int flag)
{
    int i,num=0;
    if(flag==0)
    {
        for(i=1;i<5;i++)
        {
            if(s[y/40-1][x/40-1+i]==2)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        for(i=1;i<5;i++)
        {
            if(s[y/40-1][x/40-1-i]==2)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        if(num>=4)
        {
            return 0;
        }
        num=0;//heng
        for(i=1;i<5;i++)
        {
            if(s[y/40-1+i][x/40-1]==2)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        for(i=1;i<5;i++)
        {
            if(s[y/40-1-i][x/40-1]==2)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        if(num>=4)
        {
            return 0;
        }
        num=0;//shu

        for(i=1;i<5;i++)
        {
            if(s[y/40-1+i][x/40-1+i]==2)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        for(i=1;i<5;i++)
        {
            if(s[y/40-1-i][x/40-1-i]==2)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        if(num>=4)
        {
            return 0;
        }
        num=0;

        for(i=1;i<5;i++)
        {
            if(s[y/40-1+i][x/40-1-i]==2)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        for(i=1;i<5;i++)
        {
            if(s[y/40-1-i][x/40-1+i]==2)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        if(num>=4)
        {
            return 0;
        }
        return 1;
    }
    else
    {
        for(i=1;i<5;i++)
        {
            if(s[y/40-1][x/40-1+i]==1)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        for(i=1;i<5;i++)
        {
            if(s[y/40-1][x/40-1-i]==1)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        if(num>=4)
        {
            return 0;
        }
        num=0;
        for(i=1;i<5;i++)
        {
            if(s[y/40-1+i][x/40-1]==1)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        for(i=1;i<5;i++)
        {
            if(s[y/40-1-i][x/40-1]==1)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        if(num>=4)
        {
            return 0;
        }
        num=0;

        for(i=1;i<5;i++)
        {
            if(s[y/40-1+i][x/40-1+i]==1)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        for(i=1;i<5;i++)
        {
            if(s[y/40-1-i][x/40-1-i]==1)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        if(num>=4)
        {
            return 0;
        }
        num=0;

        for(i=1;i<5;i++)
        {
            if(s[y/40-1+i][x/40-1-i]==1)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        for(i=1;i<5;i++)
        {
            if(s[y/40-1-i][x/40-1+i]==1)
            {
                num++;
            }
            else
            {
                break;
            }
        }
        if(num>=4)
        {
            return 0;
        }
        return 1;
    }
}
