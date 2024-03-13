#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>        
#include <sys/socket.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include "touchscreen.h"
#include"wuziqi.h"
#include "lcd.h"
//套接字初始化

//套接字的初始化
int client_sock;
int init_client_socket(char * ip, int port)
{
	//创建套接字
	client_sock = socket(AF_INET,SOCK_STREAM,0);
	if(client_sock == -1)
	{
		perror("sock client error");
	}
	//指定
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port); //设置端口号
	inet_aton(ip,&server_addr.sin_addr);
	//连接
	int re = connect(client_sock,(struct sockaddr *)&server_addr,sizeof(server_addr));
	if(re == -1)
	{
		perror("connect error");
	}

	printf("connect success\n");

	return client_sock;
}
void conmunicate(int client_sock,int *x,int *y)
{
	//通信
	while(1)
	{
        get_touchscreeen_idex(x,y);
		printf("%d ---- %d\n",*x,*y);
		change_xy(x,y);
     
		printf("%d ---- %d\n",*x,*y);
		if(luozi(s,*x,*y,&flag)==1)
          {
            continue;
        }
		//发送数据
		int buf[2] = {0};
        buf[0]=*x;
        buf[1]=*y;
		int re = send(client_sock,buf,8,0);
		if(re < 0)
		{
			perror("send error");
		}
          if(game_stata(s,*x,*y,flag)==0)
		{
			lcd_draw_bmppicture("./2",0,0);
			break;
		}


		//接收数据
		int str[2]={0};
		re = recv(client_sock,str,8,0);
		if(re > 0)
		{
			printf("recv : %d %d\n",str[0],str[1]);
		}	
		luozi(s,str[0],str[1],&flag);
        if(game_stata(s,str[0],str[1],flag)==0)
		{
			lcd_draw_bmppicture("./2",0,0);
			break;
		}
	}
}