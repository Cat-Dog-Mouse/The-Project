#include "lcd.h"
#include "wuziqi.h"
#include "touchscreen.h"
#include <stdio.h>
#include"client.h"
 #include <unistd.h>


int main()
{
	int fd = lcd_init();
	int i,j;
	lcd_clear(0x00969696); 
	map_init();
	int x,y;
	init_client_socket("172.8.1.236",8888);
	
		 conmunicate(client_sock,&x,&y);
		
	lcd_unint(fd);
	close(client_sock);
}




