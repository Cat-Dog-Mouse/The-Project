#ifndef _01BMP_H_
#define _01BMP_H_

int show_bmp(int x, int y, char *filename);
void lcd_init();
void lcd_close();
void display_point(int x, int y, int color);
int show_a_color(int c);
void display_Rectangle(int x0, int y0, int w, int h, int color);


#endif
