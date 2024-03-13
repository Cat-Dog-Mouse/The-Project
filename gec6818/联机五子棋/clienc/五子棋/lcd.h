#ifndef __LCD_H__
#define __LCD_H__

int *plcd; //操作屏幕的指针

int lcd_init();

void lcd_unint(int fd);
void lcd_draw_point(int x,int y,int color);
void lcd_draw_circle(int x,int y,int r,int color);
void lcd_draw_trangle(int x1,int y1,int x2,int y2,int x3,int y3,int color);
void lcd_clear(int color);
void lcd_draw_five_angle_star(int x,int y,int a,int color);
void lcd_draw_chinese(char * word,int width,int height,int x,int y, int color);
void lcd_draw_ellipse(long long int x,long long int y,long long int a,long long int b,int color);
void lcd_draw_bmppicture(char * bmp_pathname,int x0,int y0);


#endif
