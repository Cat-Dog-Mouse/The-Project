#ifndef FOOD_HPP
#define FOOD_HPP

#include "color.hpp"
#include "screen.hpp"
#include "rect.hpp"

class Food
{
public:
    Food(Screen* screen);
    void generate();
    void draw();
    int x() const;
    int y() const;
    int w() const;
    int h() const;
private:
    Screen* screen;
    Color color;
    Rect rect;
    bool flag;
};


#endif