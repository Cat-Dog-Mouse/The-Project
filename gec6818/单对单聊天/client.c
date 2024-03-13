#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

int exit_flag = 0;

void* handle_connect(void* arg)
{
    //设置线程为分离模式
    pthread_detach(pthread_self());
    
    int confd = (long)arg;

    //接收服务端发送过来的数据
    while(1)
    {
        char buf[100] = {0};
        int ret = read(confd, buf, sizeof(buf));
        if(ret == -1) //出错了8
        {
            perror("read error");
            exit(1);
        }
        if(ret == 0)
        {
            //表示服务端断开了连接
            printf("对方已经断开连接....\n");
            exit_flag = 1; //表示客户端断开连接
            close(confd);
            pthread_exit(NULL);
        }

        printf("recv %d Bytes datas : %s\n", ret, buf);
    }
}

int main(int argc, char const *argv[])
{
    //step1: 创建通信节点(通信设备)
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
    {
        perror("socket error");
        exit(1);
    }
    //step2：对服务端发起连接
    //配置对方的通信地址
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;  //协议族
    addr.sin_port = htons(10010); //端口号
    addr.sin_addr.s_addr = inet_addr("172.2.1.151"); //服务端的ip
    //连接服务端
    int ret = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if(ret == -1)
    {
        perror("connect error");
        exit(1);
    }
    
    //创建一个线程来处理连接
    pthread_t pid;
    ret = pthread_create(&pid, NULL, handle_connect, (void*)(long)sockfd);
    if(ret != 0)
    {
        errno = ret;
        perror("pthread_create error");
        exit(1);
    }


    //step3: 向服务端发送数据
    while(1)
    {
        //向客户端发生数据
        char buf[100] = {0};
        fgets(buf, 100, stdin);

        if(exit_flag == 1) //已经断开连接
            break;

        ret = write(sockfd, buf, strlen(buf)-1);
        if(ret == -1)
        {
            perror("write confd error");
            exit(1);
        }
        printf("write Bytes : %d\n", ret);
    }

    //step4: 断开连接
    close(sockfd);

    return 0;
}

