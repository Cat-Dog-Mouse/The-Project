#include <stdlib.h>
#include"01bmp.h"
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include <unistd.h>
#include <errno.h>
#include<unistd.h>
#include<dirent.h>
#include <sys/mman.h>

int * plcd = NULL;		//指向帧缓冲的首地址  全局变量
int lcd_fd;			//lcd屏幕 文件描述符

//lcd屏幕的初始化
void lcd_init()
{
	//1.打开屏幕文件 /dev/fb0
	lcd_fd = open( "/dev/fb0" , O_RDWR );
	if(lcd_fd == -1)
	{
		perror("open fb0 error ");
		return ;
	}
	
	//2.内存映射
	plcd = mmap( NULL, 800*480*4, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0 );
	if( plcd == MAP_FAILED )
	{
		perror("mmap error ");
		return ;
	}
}

//关闭屏幕，解除映射
void lcd_close()
{
	//解除映射
	munmap(plcd , 800*480*4);
	
	//关闭屏幕文件
	close(lcd_fd);
}

//画点：在指定的坐标上，显示一个颜色
void display_point(int x, int y, int color)
{
	if( x>=0 && x<800 && y>=0 && y<480 )
	{
		*( plcd + 800*y + x ) = color;
	}
}


//显示一张纯色的图片
int show_a_color(int c)
{
	int i,j;
	for(i=0; i<480; i++)
	{
		for(j=0; j<800; j++)
		{
			display_point(j, i, c);
		}
	}
}

void display_Rectangle(int x0, int y0, int w, int h, int color)//矩形
{
	int i,j;
	for(i=0; i<480; i++)
	{
		for(j=0; j<800; j++)
		{
			if(i >= y0 && i<= y0+h && j>=x0 && j <= x0+w)
			{
				display_point(j, i, color);
			}
		}
	}
}

/*
int show_bmp(int x0,int y0,int x, int y, char *filename)
	{
		//1.打开图片
		int fd=open(filename,O_RDWR);
		if(fd==-1)
		{

			perror("open failed");
			return -1;
		
		}
		
		//2.读取数据
			//宽、高、色深
			//像素点数据(bgr/bgra)
		int width = 0;
		lseek(fd, 0x12, SEEK_SET);
		read(fd, &width, 4);
		
		int  height= 0;
		lseek(fd, 0x16, SEEK_SET);
		read(fd, &height, 4);
		
		int  depth= 0;
		lseek(fd, 0x1C, SEEK_SET);
		read(fd, &depth, 2);

		int line_size = 0;	//保存一行实际字节数：有效字节数 + “赖子”
				
		int laizi = 0;	//“赖子”无效数据的个数
		laizi = 4 - (abs(width)*(depth/8)) % 4;
		if(laizi == 4)
		{
			laizi = 0;
		}
		//一行实际字节数：有效字节数   +   “赖子”
		line_size = abs(width)*(depth/8) + laizi;

		
		//一次性把图像数据（bgr/bgra）全部读取出来 
		unsigned char buf[abs(height) * line_size];
		// unsigned char *buf = malloc( abs(height) * line_size );
		lseek(fd, 0x36, SEEK_SET);
		read(fd, buf, abs(height) * line_size );
	
		//3.显示
		unsigned char b, g, r, a=0;
		int color;
		int num=0;
		
		for(y=y0; y<abs(height)+y0; ++y)
		{
			for(x=x0; x<abs(width)+x0; ++x)
			{
				b = buf[num++];
				g = buf[num++];
				r = buf[num++];
				if(depth == 32)
				{
					a = buf[num++];
				}
				color = a<<24 | r<<16 | g<<8 | b;
				
				display_point(	width>0 ? x+x0 : abs(width)-1-x+x0 ,
								height>0 ? abs(height)-1-y+y0 : y+y0, 
								color);
			}
			num = num + laizi;	//每显示完一行，跳过末尾填充的无效数据
		}
		
		//4.关闭文件
		close(fd);
}
*/
int show_bmp(int x0, int y0, char *filename)
{
	//1.打开图片
	int fd = open(filename, O_RDWR);
	if(fd == -1)
	{
		perror("open bmp error ");
		return -1;
	}
	
	//2.读取数据
	//宽、高、色深
	int width = 0;
	lseek(fd, 0x12, SEEK_SET);
	read(fd, &width, 4);
	
	int height = 0;
	lseek(fd, 0x16, SEEK_SET);
	read(fd, &height, 4);
	
	short depth = 0;
	lseek(fd, 0x1C, SEEK_SET);
	read(fd, &depth, 2);

	printf("w = %d, h = %d, d = %d\n",width,height,depth);
	
	//像素点数据(bgr/bgra)
	int line_size = 0;	//保存一行实际字节数：有效字节数 + “赖子”			
	int laizi = 0;	//“赖子”无效数据的个数
	laizi = 4 - (abs(width)*(depth/8)) % 4;
	if(laizi == 4)
	{
		laizi = 0;
	}
	//一行实际字节数：有效字节数   +   “赖子”
	line_size = abs(width)*(depth/8) + laizi;
	
	//一次性把图像数据（bgr/bgra）全部读取出来 
	unsigned char buf[abs(height) * line_size];
	// unsigned char *buf = malloc( abs(height) * line_size );
	lseek(fd, 0x36, SEEK_SET);
	read(fd, buf, abs(height) * line_size );

		
	//3.显示
	unsigned char b, g, r, a=0;
	int color;
	int num=0;
	int x,y;
	
	for(y=0; y<abs(height); ++y)
	{
		for(x=0; x<abs(width); ++x)
		{
			b = buf[num++];
			g = buf[num++];
			r = buf[num++];
			if(depth == 32)
			{
				a = buf[num++];
			}
			color = a<<24 | r<<16 | g<<8 | b;
			
 			display_point(	width>0 ? x+x0 : abs(width)-1-x+x0 , height>0 ? abs(height)-1-y+y0 : y+y0, color);
		}
		num = num + laizi;	//每显示完一行，跳过末尾填充的无效数据
	}
	
	//4.关闭文件
	close(fd);
	return 0;
}


