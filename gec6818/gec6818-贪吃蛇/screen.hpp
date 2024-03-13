/*
屏幕类的作用是打开屏幕文件，映射之后可以通过drawpoint函数来绘制屏幕的颜色
*/

#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include <string>
#include "color.hpp"
#include "point.hpp"
using std::string;


class Screen
{
protected:
    Screen(string name); 
    ~Screen();
    Screen(const Screen &) = delete;
public: 
    static Screen * getonly1(string name);
    static void destory();
    void drawPoint(int x, int y, Color color);
    void drawPoint(Point pos, Color color);
    
private:
    string name;        //屏幕文件
    int fd;             //文件下标
    int* addr;          //文件映射
    int w;              
    int h;
    int bits;           // 位深

    static Screen * only1;
    static Screen & only2;
};


#endif