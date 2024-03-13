#ifndef POINT_HPP_
#define POINT_HPP_

class Point
{
public:
    Point(int x = 0, int y = 0);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    void move(int x, int y);
private:
    int x;
    int y;
};

#endif