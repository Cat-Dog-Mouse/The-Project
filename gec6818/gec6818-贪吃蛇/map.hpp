#ifndef MAP_HPP_
#define MAP_HPP_

#include "point.hpp"
#include "rect.hpp"
#include "color.hpp"
#include "settings.hpp"
class Screen;
class Snake;

class Map
{
public:
    Map(Color color, Screen* screen, int x = 0, int y = 0);
    ~Map();
    void draw();
    Color background() const;
    void flush(int x, int y);
private:
    Screen* screen;
    Point pos;
    int w = 40;
    int h  = 28;
    Rect* cells[MAP_ROWS][MAP_COLS];
    Color bg_color;
};


#endif