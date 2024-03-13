#include "color.hpp"

Color::Color(int r, int g, int b,int a): r_(r), g_(g), b_(b), a_(a) {}

//Color::Color(int r, int g, int b): r_(r), g_(g), b_(b) {}


void Color::setValue(int r, int g, int b,int a = 0)
{
    r_ = r;
    g_ = g;
    b_ = b;
    a_ = a;
}

// int Color::toInt() const
// {
//     return ( r_ << 16 | g_ << 8 | b_);
// }

int Color::toInt() const
{
    return (a_ << 24 | r_ << 16 | g_ << 8 | b_);
}
