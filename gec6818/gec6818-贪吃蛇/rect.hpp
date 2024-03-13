#ifndef RECT_HPP_
#define RECT_HPP_

#include "point.hpp"
#include "color.hpp"
#include "screen.hpp"
/**
 * @brief 矩形类的声明
 *
 */

class Rect
{
public:
    Rect() = default;
    Rect(int w, int h);
    Rect(int w, int h, Point pos);
    Rect(int w, int h, int x, int y);
    int getW() const;
    int getH() const;
    void setWidth(int w);
    void setHeight(int h);
    void draw(Screen& screen, Color color);
    void draw(Screen* screen, Color color);
    void move(int x, int y);
    int getX() const;
    int getY() const;
private:
    int w;
    int h;
    Point start;
};


#endif