#include "lcd.h"
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#define PI 3.1415926
int *plcd =NULL; //操作屏幕的指针
/*
	初始化屏幕
*/
int lcd_init()
{
	int fd = open("/dev/fb0",O_RDWR); //打开帧缓冲
	if(fd == -1)
	{
		perror("open dev/fb0 error");
	}
	plcd = (int *)mmap(NULL,800*480*4,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
	if(plcd ==NULL)
	{
		perror("mmap error");
	}
	return fd;
}
/*
	关闭屏幕
*/
void lcd_unint(int fd)
{
	close(fd);
	munmap(plcd,800*480*4);
}
/*
	在屏幕上左边为x,y的像素点上画上color色
*/
void lcd_draw_point(int x,int y,int color)
{
	if(x>=0 && x<800 && y>=0 && y<480)
	{
		*(plcd +800*y+x) = color;
	}
}
/*
	在屏幕上画一个，以(x,y)为圆心，半径为r，颜色为color的圆
*/
void lcd_draw_circle(int x,int y,int r,int color)
{
	int i,j;
	for(j=y-r;j<=y+r;j++)
	{
		for(i = x-r;i<=x+r;i++)
		{
			if((i - x)*(i-x) + (j-y)*(j-y) <= r*r)
			{
				lcd_draw_point(i, j, color);
			}
		}
	}
}

void lcd_draw_ellipse(long long int x,long long int y,long long int a,long long int b,int color)
{
	int i,j;
	for(j=y-b;j<=y+b;j++)
	{
		for(i = x-a;i<=x+a;i++)
		{
			if((i - x)*(i-x)*b*b + (j-y)*(j-y)*a*a <= a*a*b*b)
			{
				lcd_draw_point(i, j, color);
			}
		}
	}
}
/*
	以参数中的三个顶点，画一个颜色为color的三角形
	s= 0.5*abs(x1y2+x2y3+x3y1-x1y3-x2y1-x3y2)
*/
void lcd_draw_trangle(int x1,int y1,int x2,int y2,int x3,int y3,int color)
{
	int i,j;
	int s,s1,s2,s3;
	for(j=0;j<480;j++)
	{
		for(i=0;i<800;i++)
		{
			s1 = abs(i*y2+x2*y3+x3*j-i*y3-x2*j-x3*y2);
			s2 = abs(x1*j+i*y3+x3*y1-x1*y3-i*y1-x3*j);
			s3 = abs(x1*y2+x2*j+i*y1-x1*j-x2*y1-i*y2);
			s = abs(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
			if(s1+s2+s3 == s)
			{
				lcd_draw_point(i, j, color);
			}

		}
	}

}
void lcd_clear(int color)
{
	int i,j;
	for(j=0;j<480;j++)
	{
		for(i=0;i<800;i++)
		{
			lcd_draw_point(i, j, color);
		}
	}
}
void lcd_draw_five_angle_star(int x,int y,int a,int color)
{
	lcd_draw_trangle(x,y-a*cos(PI/10),x-a*sin(PI/10),y,x+a*sin(PI/10),y,color);
	lcd_draw_trangle(x-a-a*sin(PI/10), y, x+a*sin(PI/10), y, x+a*cos(PI/5), y+a*cos(PI/10)+a*sin(PI/5), color);
	lcd_draw_trangle(x+a+a*sin(PI/10), y, x-a*sin(PI/10), y, x-a*cos(PI/5), y+a*cos(PI/10)+a*sin(PI/5), color);
}
/*
	在(x,y)处显示一个宽为width，高为height，颜色为color的文字
*/
void lcd_draw_chinese(char * word,int width,int height,int x,int y, int color)
{
	//遍历数组的每一个元素每一个bit位
	int i,j;
	int num=0;
	for(i=0;i<width*height/8;i++)//先遍历数组元素
	{
		for(j=7;j>=0;j--)
		{
			if(word[i] & (1<<j )) //表示笔画经过的像素点
			{
				lcd_draw_point(x+num%width, y+num/width, color);
			}
			num++;
		}	
	}
}
/*
	在屏幕的(x,y)处，显示一张名字(带路径)为bmp_pathname的图片
*/
void lcd_draw_bmppicture(char * bmp_pathname,int x0,int y0)
{
	int bmp_fd = open(bmp_pathname,O_RDONLY);
	if(bmp_fd == -1)
	{
		perror("open bmp error");
	}
	//获取bmp的属性

	int width,height;
	short depth;
	//读宽
	lseek(bmp_fd,18,SEEK_SET);
	read(bmp_fd,&width,4);

	printf("kuan = %d\n",width);
	//读高
	read(bmp_fd,&height,4);
	printf("gao = %d\n",height);

	//读色深
	lseek(bmp_fd,28,SEEK_SET);
	read(bmp_fd,&depth,2);
	printf("seshen = %d\n",depth);

	int laizi = 0;
	if(width * depth /8 %4) 
	{
		laizi = 4 - width * depth /8 %4;
	}

	//计算像素数组的大小
	int total = ((width * depth/8)+laizi)*height;

	char piexe[total]; //定义像素数组的大小

	lseek(bmp_fd,54,SEEK_SET);
	read(bmp_fd,piexe,total); //此时像素点的信息全部保存了piexe这个数组里面

	char b,g,r,a=0;
	
	int num=0;
	int i,j;
	for(j=0;j<height;j++)
	{
		for(i=0;i<width;i++)//遍历一行像素点
		{
			b = piexe[num++];
			g = piexe[num++];
			r = piexe[num++];
			if(depth == 32)
			{
				a=piexe[num++];
			}
			int color = b |g<<8 |r << 16 | a<<24; //还原一个像素点
			
			int x,y; //实际要画的位置
			x = width > 0? x0+i : abs(width)-1-i+x0;
			y = height <0? y0+j : abs(height)-1-j +y0;
			lcd_draw_point(x, y, color);
		}
		num+=laizi; //每一行的末尾跳过癞子
	}
	close(bmp_fd);
}



