#include "touchscreen.h"
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

/*
	获取手指点击的坐标
*/
void get_touchscreeen_idex(int *x,int *y)
{
	int ts_fd = open("/dev/input/event0",O_RDONLY);
	if(ts_fd == -1)
	{
		perror("open ts error");
		return;
	}
	struct input_event ev; //这个结构专门用来保存外部输入的信息
	while(1)
	{
		read(ts_fd,&ev,sizeof(ev)); //如果你手指没有碰到触摸屏，程序就会阻塞在此

		if(ev.type == EV_ABS && ev.code == ABS_X) //表示读到的是触摸事件，并且是x轴
		{
			*x = ev.value;
			*x = *x*800/1024;
		}
		if(ev.type == EV_ABS && ev.code == ABS_Y) //表示读到的是触摸事件，并且是Y轴
		{
			*y = ev.value;
			*y = *y*480/600;
		}
		if(ev.type == EV_KEY && ev.value == 0) //把触摸屏当作按键，并且按键弹起,表示手指离开
		{
			break;
		}	
	}
	close(ts_fd);
}
