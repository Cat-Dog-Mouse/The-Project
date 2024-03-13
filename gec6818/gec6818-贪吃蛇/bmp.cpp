#include "bmp.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
bmp文件 格式 分为四大块：
BITMAP 文件头
00h  		2 bytes         BM
02h 		 4 bytes         图片文件大小
0Ah		  4 bytes         像素数组的地址偏移

DIB头
12h           4					位图宽度
位图宽度：图片一行有多少个像素点
16			  4					位图高度
位图宽度：图片有多少行
1Ch			2					色深
色深：单个颜色所占位数
24  /  32  
24 RGB888
32 ARGB8888
22h 
			4					像素数组大小
调色板  16位以上没有这个板块

像素数组
保存了完整的像素信息
问题：解析像素数组
1. 获取像素数组
   从 .bmp文件中  来读取 像素数组
   生成bmp图片 ---> 画图方式 
   打开图片
   判断这是不是bmp图片
   获取像素数组的偏移量
   获取像素数组大小
   获取像素数组

2. 解析像素数组
   24位图   合成颜色   BGR   对于颜色来说  4个字节
   32位图   不需要合成颜色
   color  =  A<<24 | R<<16 | G<<8 | B;

3. 显示图片
   根据图片的位图宽度、位图高度来判断一个图片需要绘制多少个点（即一行有多少个点，有多少行）
*/
Bmp::Bmp(string name)
{
    this->name = name;
    this->fd = open(this->name.c_str(), O_RDONLY);
    if (fd == -1)
    {
        perror("open bmp error");
        exit(1);
    }
    lseek(fd, 0x2,SEEK_SET);
    read(fd, &size, 4);         //获得bmp文件大小

    lseek(fd, 0x12, SEEK_SET);
    read(fd, &w, 4);            //获取宽度
    read(fd, &h, 4);            //获取高度

    lseek(fd, 0x1c, SEEK_SET);  //获取色深
    read(fd, &bits, 2);

    int laizi = ((w * bits / 8) % 4 == 0) ? 0 : (4 - (w * bits / 8) % 4);
    
    
    pixel = new unsigned char[size-54];   //像素数组
    lseek(fd, 0x36, SEEK_SET);              
    read(fd, pixel, size-54);             //保存像素数组
    printf("size =  %d width = %d, height = %d, bits = %d\n", size, w, h, bits);
}
Bmp::~Bmp()
{
    
    delete[] pixel;
    close(fd);
}
void Bmp::draw(Screen& screen,int x,int y)
{
    unsigned char r, g, b,a;
    unsigned char* p = pixel;

    int laizi = ((w * bits / 8) % 4 == 0) ? 0 : (4 - (w * bits / 8) % 4);
    for(int j = 0;j<abs(h);j++)
    {
        for(int i = 0;i<abs(w);i++)
        {
            b = *p++;
            g = *p++;
            r = *p++;
            if(bits == 32)
            {
                a = *p++;
            }    
             //screen->drawPoint(i, j, Color(a , r, g, b));
            screen.drawPoint( w>0 ? i+x : abs(w)-1-i+x , 
							h>0 ? abs(h)-1-j+y : j+y , 
							Color(r,g,b,a) );
        }
        p += laizi;         //跳过每一行的赖子
    }
}

void Bmp::draw(Screen* screen, int x, int y)
{
    unsigned char r, g, b,a;
    unsigned char* p = pixel;

    int laizi = ((w * bits / 8) % 4 == 0) ? 0 : (4 - (w * bits / 8) % 4);
    for(int j = 0;j<abs(h);j++)
    {
        for(int i = 0;i<abs(w);i++)
        {
            b = *p++;
            g = *p++;
            r = *p++;
            if(bits == 32)
            {
                a = *p++;
            }    
             //screen->drawPoint(i, j, Color(a , r, g, b));
            screen->drawPoint( w>0 ? i+x : abs(w)-1-i+x , 
							h>0 ? abs(h)-1-j+y : j+y , 
							Color(r,g,b,a) );
        }
        p += laizi;         //跳过每一行的赖子
    }
}

