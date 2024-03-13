#include "screen.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <stdexcept>
#include <stdio.h>
#include <iostream>
using namespace std;

Screen * Screen::only1 = nullptr;

Screen::Screen(string name) 
{
    /*
     open - open and possibly create a file
		打开/创建一个文件
SYNOPSIS
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

       int open(const char *pathname, int flags);
       int open(const char *pathname, int flags, mode_t mode);
			pathname：路径名  带路径的文件名
            flags：标志位 打开的方式
                O_RDONLY  只读
                O_WRONLY  只写
                O_RDWR	  读写 
                上述三个三选一即可
            --------------------- 
                O_CREAT 创建 ，如果文件不存在就会创建
                O_APPEND 追加 文件打开后，光标/偏移量在文件尾
                O_TRUC  截断 打开时清空文件内容
                O_EXCL 这个标记一般是和O_CREAT配合使用，用来测试这个文件存在与否
                	O_EXCL | O_CREAT 如果文件存在，打开就会失败
                O_NONBLOCK 非阻塞的方式打开这个文件
                	非阻塞：不等待
                对于阻塞状态来说：
                	如果文件没有内容，那么read会阻塞，直到这个空间有内容
                	如果这个文件没有空间了，那么write会阻塞，直到这个文件有空间
                对于非阻塞状态：
                	如果文件没有内容，那么read不会阻塞，直接返回一个错误
                	如果这个文件没有空间了，那么write不会阻塞，直接返回一个错误
                如果你想要 只写 以及创建 的方式打开一个文件
                	O_WRONLY | O_CREAT
            mode:指定文件创建时权限，如果flags没有指定O_CREAT，这个参数就没有意义
                有两种方式来制定权限：rwx rwx rwx
                一：
                S_IRWXU  00700 user has read, write,and execute
                       permission
				S_IRUSR  00400 user has read permission
				S_IWUSR  00200 user has write permission
				S_IXUSR  00100 user has execute permission
				S_IRWXG  00070 group has read, write, and execute permission
				S_IRGRP  00040 group has read permission
				S_IWGRP  00020 group has write permission
				S_IXGRP  00010 group has execute permission
				S_IRWXO  00007 others have read, write, and execute permission
				S_IROTH  00004 others have read permission
				S_IWOTH  00002 others have write permission
				S_IXOTH  00001 others have execute permission
                
                user 用户可读可写  group用户可读可写 other用户可读
                S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH
                二：
                	user 用户可读可写  group用户可读可写 other用户可读
                	0664
       返回值：
           成功，返回一个文件描述符 >2
           失败，返回-1 并且errno被设置
                
操作系统 会为每个进程 自动打开三个文件：
        标准输入文件   STDIN_FILENO   0
        标准输出文件   STDOUT_FILENO  1
        标准出错文件   STDERR_FILENO  2
errno:错误编号
    不同的错误编号 代表了不同的错误原因
    可以使用perror 这个函数 输出当前错误号所对应的错误原因
    */
    fd = open(name.c_str(), O_RDWR);
    if (fd == -1)
    {
        perror("open lcd error\n");
        exit(-1);
    }

    //获取屏幕参数
	struct fb_var_screeninfo info;
	int re = ioctl( fd, FBIOGET_VSCREENINFO, &info );
	if( re == -1 )
	{
		perror("ioctl error ");
		return ;
	}

	w = info.xres;
	h = info.yres;
	bits = info.bits_per_pixel;

    addr = static_cast<int*>(mmap(NULL, w * h * bits / 8, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));
    if (addr == MAP_FAILED)
    {
        perror("mmap lcd error\n");
        exit(-1);
    }
    printf("screen init success!!!\n");
}

Screen::~Screen()
{
    ::close(fd);
    ::munmap(addr, w * h * bits / 8);
}

Screen * Screen::getonly1(string name)
{
    if(only1 == nullptr)
        only1 = new Screen(name);

    return only1;
}   

void Screen::drawPoint(int x, int y, Color color)
{
    if (x >= 0 && x < 800 && y >= 0 && y < 480)
        *(addr + w * y + x) = color.toInt();
}

void Screen::drawPoint(Point pos, Color color)
{
    drawPoint(pos.getX(), pos.getY(), color);
}
