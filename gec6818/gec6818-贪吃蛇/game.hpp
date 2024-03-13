#ifndef GAME_HPP_
#define GAME_HPP_

#include "screen.hpp"
#include "map.hpp"
#include "snake.hpp"
#include "touchevent.hpp"
#include <mutex>


class Game
{
public:
    Game();
    void run();
    void handle_touch_event();
    void draw_ui() const ;
private:
    Screen* screen;
    TouchEvent* tevent;
    Map* map;
    Snake* snake;
    Food* food;
    Direction direction;
    
    std::mutex mutex;
    int score;
};


#endif


