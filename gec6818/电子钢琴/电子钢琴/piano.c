#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include"01bmp.h"
#include"piano.h"
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include"touch.h"
#include <unistd.h>
#include <errno.h>
#include<dirent.h>

void *piano(void *arg)
{
	
	char *music[12] = {"d1.mp3", "d2.mp3", "d3.mp3","d4.mp3","d5.mp3","d6.mp3","d7.mp3","d8.mp3","d9.mp3","d10.mp3","d11.mp3","d12.mp3"};
	
	char cmd[128] = {0};
	snprintf(cmd, 128, "madplay -Q %s &", music[0]);
	
	system(cmd);

}
int my_piano()
{
	//打开显示屏、内存映射、打开触摸屏
	lcd_init();
	int fd=open("/dev/input/event0",O_RDWR);
	
	char *music[12] = {"d1.mp3", "d2.mp3", "d3.mp3","d4.mp3","d5.mp3","d6.mp3","d7.mp3","d8.mp3","d9.mp3","d10.mp3","d11.mp3","d12.mp3"};
	
	char cmd[128] = {0};
	show_bmp(0, 0, "background.bmp");
	show_bmp(229,67,"logo.bmp");
	//显示界面
		//背景、标题logo、乐谱 ...
		//显示12个琴键
	int i;
	for(i=0;i<12;i++)
	{		
		show_bmp(i*66, 200,"key_off.bmp");
	}
	while(1)
	{
		system("killall madplay");
		//获取手指的坐标
		int x,y;
		get_coordinate(&x,&y);
		if(x>=0 && x<84 && y>250)	//琴键1  触摸屏坐标（注意触摸屏和显示屏坐标的换算）
		{
			//显示灰色	按下	
			show_bmp(0, 200, "key_on.bmp");
			
			//播放当前的琴键的声音	
			snprintf(cmd, 128, "madplay -Q %s &", music[0]);
			
			system(cmd);
			//恢复白色	松开
			show_bmp(0, 200, "key_off.bmp");
			x=-1;//都加了没检验
			y=-1;
			usleep(300000);
		}
		else if(x>=84&&x<169 && y>250) //琴键2
		{
			//显示灰色	按下	
			show_bmp(66, 200, "key_on.bmp");
			
			//播放当前的琴键的声音	
			snprintf(cmd, 128, "madplay -Q %s &", music[1]);
			
			system(cmd);
			//恢复白色	松开
			show_bmp(66, 200, "key_off.bmp");
			x=-1;
			y=-1;			
			usleep(300000);
		}
		//...
		else if(x>=169&&x<254 && y>250) //琴键3
		{

					//显示灰色	按下	
			show_bmp(132, 200, "key_on.bmp");
			
			//播放当前的琴键的声音	
			snprintf(cmd, 128, "madplay -Q %s &", music[2]);
			
			system(cmd);
			//恢复白色	松开
			show_bmp(132, 200, "key_off.bmp");
			x=-1;
			y=-1;			
			usleep(300000);
		}
		//...
		else if(x>=254&&x<338 && y>250) //琴键4
		{

			//显示灰色	按下	
			show_bmp(198, 200, "key_on.bmp");
			
			//播放当前的琴键的声音	
			snprintf(cmd, 128, "madplay -Q %s &", music[3]);
			
			system(cmd);
			//恢复白色	松开
			show_bmp(198, 200, "key_off.bmp");
			x=-1;
			y=-1;			
			usleep(300000);
		}
		//...
		else if(x>=338&&x<423 && y>250) //琴键5
		{
					//显示灰色	按下	
			show_bmp(264, 200, "key_on.bmp");
			
			//播放当前的琴键的声音	
			snprintf(cmd, 128, "madplay -Q %s &", music[4]);
			
			system(cmd);
			//恢复白色	松开
			show_bmp(264, 200, "key_off.bmp");
			x=-1;
			y=-1;			
			usleep(300000);
		}
		//...
		else if(x>=423&&x<507 && y>250) //琴键6
		{
					//显示灰色	按下	
			show_bmp(330, 200, "key_on.bmp");
			
			//播放当前的琴键的声音	
			snprintf(cmd, 128, "madplay -Q %s &", music[5]);
			
			system(cmd);
			//恢复白色	松开
			show_bmp(330, 200, "key_off.bmp");
			x=-1;
			y=-1;			
			usleep(300000);
		}
		//...
		else if(x>=507&&x<592 && y>250) //琴键7
		{
					//显示灰色	按下	
			show_bmp(396, 200, "key_on.bmp");
			
			//播放当前的琴键的声音	
			snprintf(cmd, 128, "madplay -Q %s &", music[6]);
			
			system(cmd);
			//恢复白色	松开
			show_bmp(396, 200, "key_off.bmp");
			x=-1;
			y=-1;			
			usleep(300000);
		}
		//...
		else if(x>=592&&x<676 && y>250) //琴键8
		{
					//显示灰色	按下	
			show_bmp(462, 200, "key_on.bmp");
			
			//播放当前的琴键的声音	
			snprintf(cmd, 128, "madplay -Q %s &", music[7]);
			
			system(cmd);
			//恢复白色	松开
			show_bmp(462, 200, "key_off.bmp");
			x=-1;
			y=-1;			
			usleep(300000);
		}
		//...
		else if(x>=676&&x<761 && y>250) //琴键9
		{
					//显示灰色	按下	
			show_bmp(528, 200, "key_on.bmp");
			
			//播放当前的琴键的声音	
			snprintf(cmd, 128, "madplay -Q %s &", music[8]);
			
			system(cmd);
			//恢复白色	松开
			show_bmp(528, 200, "key_off.bmp");
			x=-1;
			y=-1;			
			usleep(300000);
		}
		//...
		else if(x>=761&&x<845&& y>250) //琴键10
		{
					//显示灰色	按下	
			show_bmp(594, 200, "key_on.bmp");
			
			//播放当前的琴键的声音	
			snprintf(cmd, 128, "madplay -Q %s &", music[9]);
			
			system(cmd);
			//恢复白色	松开
			show_bmp(594, 200, "key_off.bmp");
			x=-1;
			y=-1;			
			usleep(300000);
		}
		//...
		else if(x>=845&&x<930 &y>250) //琴键11
		{
					//显示灰色	按下	
			show_bmp(660, 200, "key_on.bmp");
			
			//播放当前的琴键的声音	
			snprintf(cmd, 128, "madplay -Q %s &", music[10]);
			
			system(cmd);
			//恢复白色	松开
			show_bmp(660, 200, "key_off.bmp");
			x=-1;
			y=-1;			
			usleep(300000);
		}
		else if(x>=930&&x<1014 &&y>250) //琴键11
		{
					//显示灰色	按下	
			show_bmp(726, 200, "key_on.bmp");
			
			//播放当前的琴键的声音	
			snprintf(cmd, 128, "madplay -Q %s &", music[11]);
			
			system(cmd);
			//恢复白色	松开
			show_bmp(726, 200, "key_off.bmp");
			x=-1;
			y=-1;			
			usleep(300000);
		}
		//..				
		/*
		if( ) //退出按钮
		{
			break;
		}
		*/
	}
	
	//关闭屏幕
	close(fd);
}


