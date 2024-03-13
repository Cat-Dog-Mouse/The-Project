#ifndef __CLIENT_H__
#define __CLIENT_H__

int init_client_socket(char * ip, int port);
void conmunicate(int client_sock,int *x,int *y);
int client_sock;


#endif