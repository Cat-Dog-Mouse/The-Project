#include "food.hpp"
#include "settings.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

Food::Food(Screen* screen) : screen(screen), color(255, 0, 0,0), flag(false), rect(CELL_SIZE, CELL_SIZE) {}

void Food::generate()
{
    srand(time(NULL));
    
    int offset = CELL_SIZE + GAP_SIZE;
    int x = rand() % MAP_COLS;
    int y = rand() % MAP_ROWS;
    this->rect.move(x * offset, y * offset);
}

void Food::draw()
{
    this->rect.draw(screen, color);
}


int Food::x() const
{
    return rect.getX();
}
int Food::y() const
{
    return rect.getY();
}

int Food::w() const
{
    return rect.getW();
}
int Food::h() const
{
    return rect.getH();
}
