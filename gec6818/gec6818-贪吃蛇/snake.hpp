#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "rect.hpp"
#include "food.hpp"
#include <vector>
#include "settings.hpp"
class Screen;

class Map;
class Snake
{
public:
    Snake(Screen* screen);
    void move(Direction direct, Map* map);
    bool eat(Food* food);
    bool dead() const;
    void draw();
    int getSpeed() const ;
    

private:
    Screen* screen;
    std::vector<Rect*> body;
    // int x_;
    // int y_;
    int speed;
    int step;
};

#endif