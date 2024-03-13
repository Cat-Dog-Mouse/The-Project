#include "snake.hpp"
#include "settings.hpp"
#include "map.hpp"
#include <iostream>
#include <thread>
using namespace std;


Snake::Snake(Screen* screen) 
{
    this->screen = screen;
    speed = 1;
    step = CELL_SIZE + GAP_SIZE;

    body.push_back(new Rect(CELL_SIZE, CELL_SIZE, 4 * step, 2 * step));
    body.push_back(new Rect(CELL_SIZE, CELL_SIZE, 3 * step, 2 * step));
    body.push_back(new Rect(CELL_SIZE, CELL_SIZE, 2 * step, 2 * step));
}

void Snake::draw()
{
    body.at(0)->draw(screen, Color(0, 150, 200));
    for (int i = 1; i < body.size(); i++)
    {
        body.at(i)->draw(screen, Color(0,200, 200));
         std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
    }
}

void Snake::move(Direction direct, Map* map)
{
    // 擦除蛇尾
    map->flush(body.back()->getX(), body.back()->getY());

    // 绘制蛇身
    for (int i = body.size() - 1; i > 0; i--)
    {
        body[i]->move(body.at(i - 1)->getX(), body.at(i - 1)->getY());
    }
    // 绘制蛇头
    if (direct == Up)
    {
        body[0]->move(body[0]->getX(), body[0]->getY() - step);
    }
    else if (direct == Down)
    {
        body[0]->move(body[0]->getX(), body[0]->getY() + step);
    }
    else if (direct == Left)
    {
        body[0]->move(body[0]->getX() - step, body[0]->getY());
    }
    else if (direct == Right)
    {
        body[0]->move(body[0]->getX() + step, body[0]->getY());
    }

}
int Snake::getSpeed() const
{
    return this->speed;
}

bool Snake::eat(Food* food)
{
    if (body.at(0)->getX() == food->x() && body.at(0)->getY() == food->y())
    {
        body.push_back(new Rect(CELL_SIZE, CELL_SIZE, food->x(), food->y()));
        this->speed += 1;
        return true;
    }
    return false;
}

bool Snake::dead() const
{
    // 撞左右边界，死亡
    if (body[0]->getX() < 0 || body[0]->getX() >= MAP_COLS * (CELL_SIZE + GAP_SIZE))
    {
        cout<<"error1"<<endl;
        return true;
    }
    // 撞上下边界，死亡
    if (body[0]->getY() < 0 || body[0]->getY() >= MAP_ROWS * (CELL_SIZE + GAP_SIZE))
    {
        cout<<"error2"<<endl;
        return true;
    }
    // 撞到自已的身体，死亡
    for (int i = 1; i < body.size(); i++)
    {
        if (body[0]->getX() == body[i]->getX() && body[0]->getY() == body[i]->getY())
            
            {
                cout<<"error1"<<endl;
                return true;
            }
               
    }
    return false;
}

