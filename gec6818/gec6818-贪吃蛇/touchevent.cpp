#include "touchevent.hpp"
#include "point.hpp"
#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdexcept>


TouchEvent::TouchEvent(std::string name)
{
    fd_ = ::open(name.c_str(), O_RDONLY);
    if (fd_ == -1)
        throw std::logic_error("open " + name + " error");
}


TouchEvent::~TouchEvent()
{
    ::close(fd_);
}

Direction TouchEvent::touchScreen()
{
    struct input_event event;
    Point start;
    Point end;
    while (1)
    {
        int r = ::read(fd_, &event, sizeof(event));
        if (r == -1)
            throw std::runtime_error("touch read error!");
        if (event.type == EV_ABS && event.code == ABS_X)
        {
            if (start.getX() == 0)
            {
                start.setX(event.value);
            }
            end.setX(event.value);
        }
        else if (event.type == EV_ABS && event.code == ABS_Y)
        {
            if (start.getY() == 0)
            {
                start.setY(event.value);
            }
            end.setY(event.value);
        }
        else if (event.type == EV_KEY && event.value == 0)
        {
            break;
        }
    }

    return analyseDirection(start, end);
}

Direction TouchEvent::analyseDirection(Point start, Point end)
{
    // 如果水平方向的偏移>垂直方向的偏移，则为左或右
    if (abs(start.getX()-end.getX()) > abs(start.getY() - end.getY()))
    {
        if (start.getX() > end.getX())
            return Direction::Left;
        return Direction::Right;
    }   
    else 
    {
        if (start.getY() > end.getY())
            return Direction::Up;
        return Direction::Down;
    }
}

