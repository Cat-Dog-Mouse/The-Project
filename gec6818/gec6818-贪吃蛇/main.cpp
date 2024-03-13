#include <iostream>
#include "game.hpp"
#include "bmp.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    // Screen *screen =  Screen::getonly1("/dev/fb0");
    // // 绘制背景颜色
    // Rect(800, 480).draw(screen, Color(246, 246, 246));
    Game game;
    game.run();
    // Screen* s =  Screen::getonly1("/dev/fb0");
    // Bmp("./images/fengmian.bmp").draw(s);
    // Rect(800, 480).draw(s, Color(246, 246, 246,0));

    return 0;
}





