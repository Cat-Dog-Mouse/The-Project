#include "game.hpp"
#include "food.hpp"
#include "bmp.hpp"
#include <iostream>
#include <chrono>
#include <thread>

#include <unistd.h>
using namespace std;


Game::Game() : direction(Right), score(0)
{
    const char* lcd_name = nullptr;
    const char* ts_name = nullptr;

    lcd_name = "/dev/fb0";
    ts_name = "/dev/input/event0";
    this->tevent = new TouchEvent(ts_name);
    this->screen =Screen::getonly1(lcd_name);
    this->map = new Map(Color(200, 200, 200), this->screen);
    this->snake = new Snake(this->screen);
    this->food = new Food(this->screen);
}

void Game::draw_ui() const 
{
    // 绘制背景颜色
    Rect(800, 480).draw(screen, Color(246, 246, 246));

    cout<<"step1"<<__LINE__<<endl;
    // 绘制地图
    this->map->draw();

    // 绘制logo
    Bmp bmp("./images/logo.bmp");
    bmp.draw(screen, 680, 0);
}

void Game::run()
{
    // 绘制界面
    draw_ui();

    std::thread(&Game::handle_touch_event, this).detach();

    food->generate();
    while (1)
    {
        {
            std::lock_guard<std::mutex> lg(mutex);
            snake->move(direction, map);
        }
        if (snake->dead())
        {
            Bmp("./images/game_over.bmp").draw(screen, (800 - 160) / 2, (480 - 96) / 2);
            cout << "total score: " << this->score << endl;
            exit(-1);
        }

        if (snake->eat(food))
        {
            this->score += 10;
            food->generate();
        }
        
        snake->draw();
        food->draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(500 / snake->getSpeed()));
    }
}


void Game::handle_touch_event()
{
    while (1)
    {
        Direction d = this->tevent->touchScreen();
        // cout << "d = " << d << endl;
        
        std::lock_guard<std::mutex> lg(mutex);
        // 上
        if (d == Direction::Up)
        {
            if (this->direction != Down)
                this->direction = Up;
        }
        // 下
        else if (d == Direction::Down)
        {
            if (this->direction != Up)
                this->direction = Down;
        }
        // 左
        else if (d == Direction::Left)
        {
            if (this->direction != Right)
                this->direction = Left;
        }
        // 右
        else if (d == Direction::Right)
        {
            if (this->direction != Left)
                this->direction = Right;
        }
        else
        {
            continue;
        }
    }
}
