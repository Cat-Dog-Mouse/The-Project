#include "touch.h"
#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#define  RIGHT 1;
#define DOWN 4;
#define LEFT 2;
#define UP 3;

/*
// 获取手指触摸屏幕的坐标
int get_coordinate()
{
	//打开屏幕文件 
	int fd = open("/dev/input/event0", O_RDWR);
	if(fd == -1)
	{
		perror("open event0 error ");
		return -1;
	}
	
	
	int x=-1, y=-1;
	
	//读取数据，并解析
	struct input_event ev;
	while(1)
	{
		//读取
		int re = read(fd, &ev, sizeof(ev));
		if(re != sizeof(ev))
		{
			continue;
		}
		
		//解析
		if(ev.type == EV_ABS)	//触摸事件
		{
			if(ev.code == ABS_X)	//x轴
			{
				x = ev.value;
			}
			else if(ev.code == ABS_Y)		//y轴
			{
				y = ev.value;
			}
			else if(ev.code == ABS_PRESSURE && ev.value == 0) //压力事件 且压力为0
			{
				if( x != -1 && y != -1)
				{
					break;
				}
			}
		}
		else if(ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0)	//按键事件
		{
			if( x != -1 && y != -1)
			{
				break;
			}
		}
		
		//printf("type = %d, code = %d, value = %d\n",ev.type,ev.code,ev.value);
	}
	
	printf("( %d , %d )\n",x,y);
	
	//关闭屏幕 
	close(fd);
	return 0;
}
*/
// 获取手指触摸屏幕的坐标
int get_coordinate(int *x,int *y)
{
	//打开屏幕文件 
	int fd = open("/dev/input/event0", O_RDWR);
	if(fd == -1)
	{
		perror("open event0 error ");
		return -1;
	}
	
	
	*x=-1, *y=-1;
	
	//读取数据，并解析
	struct input_event ev;
	while(1)
	{
		//读取
		int re = read(fd, &ev, sizeof(ev));
		if(re != sizeof(ev))
		{
			continue;
		}
		
		//解析
		if(ev.type == EV_ABS)	//触摸事件
		{
			if(ev.code == ABS_X)	//x轴
			{
				*x = ev.value;
			}
			else if(ev.code == ABS_Y)		//y轴
			{
				*y = ev.value;
			}
			else if(ev.code == ABS_PRESSURE && ev.value == 0) //压力事件 且压力为0
			{
				if( *x != -1 && *y != -1)
				{
					break;
				}
			}
		}
		else if(ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0)	//按键事件
		{
			if( *x != -1 && *y != -1)
			{
				break;
			}
		}
		
		//printf("type = %d, code = %d, value = %d\n",ev.type,ev.code,ev.value);
	}
	
	printf("( %d , %d )\n",x,y);
	
	//关闭屏幕 
	close(fd);
	return 0;
}


/*
1)获取手指滑动的方向 
返回值：
	1	上
	2	下
	3	左
	4	右
				*/	
int get_direction()
{
	//打开屏幕文件 
	int fd = open("/dev/input/event0", O_RDWR);
	if(fd == -1)
	{
		perror("open event0 error ");
		return -1;
	}


	//获取起点x0,y0 和 终点x1,y1的坐标
	int x0=-1, y0=-1;	//起点坐标
	int x1=-1, y1=-1;	//终点坐标

	struct input_event ev;
	while(1)
	{
		//读取
		int re = read(fd, &ev, sizeof(ev));
		if(re != sizeof(ev))
		{
			continue;
		}
		
		//解析
		if(ev.type == EV_ABS)	//触摸事件
		{
			if(ev.code == ABS_X)	//x轴
			{
				if(x0 == -1)
				{
					x0 = ev.value;
				}
				x1 = ev.value;
			}
			else if(ev.code == ABS_Y)		//y轴
			{
				if(y0 == -1)
				{
					y0 = ev.value;
				}
				y1 = ev.value;
			}
			else if(ev.code == ABS_PRESSURE && ev.value == 0) //压力事件 且压力为0
			{
				if( x0 != -1 && y0 != -1)
				{
					break;
				}
			}
		}
		else if(ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0)	//按键事件
		{
			if( x0 != -1 && y0 != -1)
			{
				break;
			}
		}
	}

	//关闭屏幕 
	close(fd);

	printf("( %d , %d ) -- ( %d , %d )\n",x0,y0,x1,y1);


	//判定方向
	int xx = abs(x0-x1);
	int yy = abs(y0-y1);

	if(xx > yy)		//水平方向
	{
		if(x0 < x1)
		{
			return RIGHT;	//右滑
		}
		else
		{
			return LEFT;	//左
		}
	}
	else 		//垂直方向
	{
		if(y0 < y1)
		{
			return DOWN;	//下
		}
		else
		{
			return UP;		//上
		}
	}

	
}

