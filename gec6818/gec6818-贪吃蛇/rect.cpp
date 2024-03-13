#include "rect.hpp"
#include <iostream>
using namespace std;
Rect::Rect(int w, int h) : w(w), h(h),start(0,0){}
Rect::Rect(int w, int h, Point pos) : w(w), h(h), start(pos) {}
Rect::Rect(int w, int h, int x, int y) :w(w), h(h), start(x, y) {}


int Rect::getW() const
{
    return w;
}
int Rect::getH() const
{
    return h;
}
void Rect::setWidth(int w)
{
    w = w;
}
void Rect::setHeight(int h)
{
    h = h;
}

void Rect::draw(Screen& screen, Color color)
{
    for (int i = this->start.getY(); i < h + this->start.getY(); i++)
    {
        for (int j = this->start.getX(); j < w + this->start.getX(); j++)
        {
            screen.drawPoint(Point(j, i), color);
        }
    }
}
void Rect::draw(Screen* screen, Color color)
{
    this->draw(*screen, color);
}

void Rect::move(int x, int y)
{
    this->start.move(x, y);
}

int Rect::getX() const 
{
    return start.getX();
}
int Rect::getY() const 
{
    return start.getY();
}



