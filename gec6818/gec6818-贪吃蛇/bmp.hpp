#ifndef BMP_HPP_
#define BMP_HPP_

#include <string>
#include "screen.hpp"
using namespace std;

class Bmp
{
public:
    Bmp(string name);
    ~Bmp();
    void draw(Screen& screen,int x = 0,int y = 0);
    void draw(Screen* screen, int x = 0, int y = 0);
private:
    string name;        //屏幕设备文件名
    int fd;             //文件下标
    int size;           //0x02  bmp文件的大小
    int w;              //位图的宽度
    int h;              //位图的高度
    short bits;         //位图的色深
    unsigned char * pixel;  //像素数组
};

#endif


