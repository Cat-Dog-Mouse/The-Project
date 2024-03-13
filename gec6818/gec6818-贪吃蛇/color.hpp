#ifndef COLOR_HPP_
#define COLOR_HPP_

/**
 * @brief Color类型声明
 * 
 */

class Color
{
public:
    Color(int r, int g, int b,int a =0);
    void setValue(int r, int g, int b,int a);
    int toInt() const;
private:
    int r_;
    int g_;
    int b_;
    int a_;
};



#endif