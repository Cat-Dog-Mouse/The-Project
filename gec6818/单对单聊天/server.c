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

int sockfd = -1;

int exit_flag = 0; //客户端退出标志位，1表示客户端断开连接了

/**
 * @brief 服务端初始化
 * 
 * @param port 网络程序对应的端口号
 */
void init_server(int port)
{
    //step1: 创建通信节点(通信设备)
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
    {
        perror("socket error");
        exit(1);
    }
    //step2：绑定(准备通信地址)
    struct sockaddr_in addr;
    addr.sin_family = AF_INET; //协议族
    addr.sin_port = htons(port); //端口号
    //addr.sin_addr.s_addr = inet_addr("172.5.1.30"); //必须是本机的IP地址
    addr.sin_addr.s_addr = INADDR_ANY;  //使用本机任意地址(代表本机上的所有有效地址)
    int ret = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if(ret == -1)
    {
        perror("bind error");
        exit(1);
    }

    //step3: 监听
    ret = listen(sockfd, 10);
    if(ret == -1)
    {
        perror("listen error");
        exit(1);
    }
}

void* handle_connect(void* arg)
{
    //设置线程为分离模式
    pthread_detach(pthread_self());
    
    int confd = (long)arg;

    //接收客户端发送过来的数据
    while(1)
    {
        char buf[100] = {0};
        int ret = read(confd, buf, sizeof(buf));
        if(ret == -1) //出错了
        {
            perror("read error");
            exit(1);
        }
        if(ret == 0)
        {
            //表示客户端断开了连接
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
    //服务端初始化
    init_server(10010);
    
    while(1)
    {
        //接收连接
        struct sockaddr_in client_addr; //用来保存客户端的IP信息
        socklen_t len = sizeof(client_addr);
        int confd = accept(sockfd, (struct sockaddr*)&client_addr, &len);
        if(confd == -1)
        {
            perror("accept error");
            exit(1);
        }
        printf("new client: %s\n", inet_ntoa(client_addr.sin_addr));


        //创建一个线程来处理连接
        pthread_t pid;
        int ret = pthread_create(&pid, NULL, handle_connect, (void*)(long)confd);
        if(ret != 0)
        {
            errno = ret;
            perror("pthread_create error");
            exit(1);
        }

        //往客户端发送信息
        exit_flag = 0;
        while(1)
        {
            //向客户端发生数据
            char buf[100] = {0};
            fgets(buf, 100, stdin);

            if(exit_flag == 1) //已经断开连接
                break;

            ret = write(confd, buf, strlen(buf)-1);
            if(ret == -1)
            {
                perror("write confd error");
                exit(1);
            }
            printf("write Bytes : %d\n", ret);
        }

    }

    //6、断开连接
    close(sockfd);

    return 0;
}

