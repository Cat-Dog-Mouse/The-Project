#ifndef __WUZIQI_H__
#define __WUZIQI_H__

int s[12][20];
int flag;
void map_init(void);
void change_xy(int *x,int *y);
int luozi(int s[12][20],int x,int y,int *flag);
int game_stata(int s[12][20],int x,int y,int flag);

#endif