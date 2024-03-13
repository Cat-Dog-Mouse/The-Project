#ifndef TOUCHEVENT_HPP
#define TOUCHEVENT_HPP

#include <string>
#include "point.hpp"
#include "settings.hpp"

class TouchEvent
{
public:
    TouchEvent(std::string name);
    ~TouchEvent();
    Direction touchScreen();
private:
    Direction analyseDirection(Point start, Point end);
    int fd_;
};


#endif