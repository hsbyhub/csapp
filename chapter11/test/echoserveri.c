/* 
 * echoserveri.c - An iterative echo server 
 */ 
/* $begin echoserverimain */
#include "csapp.h"

void echo(int connfd);

int main(int argc, char **argv) 
{
    int listenfd, connfd, port, clientlen;
    struct sockaddr_in clientaddr;
    struct hostent *hp;
    char *haddrp;
    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(0);
    }
    port = atoi(argv[1]);

    listenfd = Open_listenfd(port);                                     //获得已连接的监听套接字描述符
    while (1) {
        clientlen = sizeof(clientaddr);
        connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);       //转换为连接套接字描述符，并获取客户端套接字地址

        /* determine the domain name and IP address of the client */
        hp = Gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr,   //通过套接字地址结构中的IP地址字段获取客户端信息
                   sizeof(clientaddr.sin_addr.s_addr), AF_INET);        
        haddrp = inet_ntoa(clientaddr.sin_addr);                        //客户端地址的字符串表示
        printf("server connected to %s (%s)\n", hp->h_name, haddrp);    

        echo(connfd);                                                   //输出客户端发来的消息
        Close(connfd);
    }
    exit(0);
}
/* $end echoserverimain */
