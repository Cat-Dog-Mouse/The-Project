#include "map.hpp"
#include "snake.hpp"
#include <iostream>
using namespace std;

Map::Map(Color color, Screen* screen, int x, int y) : screen(screen), pos(x, y), bg_color(color)
{
    for (int i = 0; i < this->h; i++)
    {
        for (int j = 0; j < this->w; j++)
        {
            this->cells[i][j] = new Rect(CELL_SIZE, CELL_SIZE, j * CELL_SIZE + GAP_SIZE * j, i * CELL_SIZE + GAP_SIZE * i);
        }
    }
}
Map::~Map()
{
    for (int i = 0; i < this->h; i++)
    {
        for (int j = 0; j < this->w; j++)
        {
            delete this->cells[i][j];
        }
    }
}

void Map::draw()
{
    for (int i = 0; i < this->h; i++)
    {
        for (int j = 0; j < this->w; j++)
        {
            this->cells[i][j]->draw(screen, this->bg_color);
        }
    }
}

Color Map::background() const
{
    return this->bg_color;
}

void Map::flush(int x, int y)
{
    // 根据尾部的坐标计算它在地图的哪个cell
    int row = y / (CELL_SIZE + GAP_SIZE);
    int col = x / (CELL_SIZE + GAP_SIZE);
    // 把相应的cell还原成背景
    this->cells[row][col]->draw(screen, this->bg_color);
}




