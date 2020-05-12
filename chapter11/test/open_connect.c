#include <csapp.h>

int open_clientfd( char* hostname, char* port ){

    int clientfd;
    struct addrinfo hints;      //限制getaddrinfo的结果
    struct addrinfo *listp;
    struct addrinfo *p;

    memset( &hints, 0, sizeof(struct addrinfo) );
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_NUMERICSERV |                   //设置服务用端口号表示
                     AI_ADDRCONFIG ;                    
    getaddrinfo( hostname, port, &hints, &listp );      //查询套接字链表

    for ( p = listp; p; p->ai_next ){                   //尝试连接每个查询到的套接字
        if( ( clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol ) ) < 0 )  //建立与服务端监听套接字匹配的客户端套接字
            continue;
        
        if( connect( clientfd, p->ai_addr, p->ai_addrlen ) != -1 )   //connect会阻塞，如果连接成功就跳出循环
            break;
        Close(clientfd);                                //否则说明本次尝试连接失败，关闭套接字
    }

    freeaddrinfo(listp);                                //释放套接字地址结构链表
    if ( !p )
        return -1;
    else 
        return clientfd;

}

int open_listenfd(char *port){

    int listenfd;
    int optval = 1;
    struct addrinfo hints;
    struct addrinfo *listp;
    struct addrinfo *p;
   
    memset( &hints, 0, sizeof(struct addrinfo) );
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags =    AI_PASSIVE|             //套接字将作为服务器端
                        AI_ADDRCONFIG|          //使用与主机相同的IPv?地址
                        AI_NUMERICSERV;         //将服务名用端口号表示
    getaddrinfo(NULL, port, &hints, &listp);    //查询端口上的套接字
    
    for( p = listp; p; p = p->ai_next ){
        if( ( listenfd = socket( p->ai_family, p->ai_socktype, p->ai_protocol ) ) < 0 )         //配置一个与客户端套接字匹配的监听套接字
            continue;

        setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, ( const void * )&optval, sizeof(int));   //配置服务器
        
        if( bind(listenfd, p->ai_addr, p->ai_addrlen) == 0 )                                    //将监听套接字与监听到的套接字连接起来
            break;
        Close(listenfd);
    }

    freeaddrinfo(listp);                    //释放套接字链表
    if(!p)                                  //如果没有查询到套接字
        return -1;

    if( listen(listenfd, LISTENQ) < 0 ){    //开始监听
        close(listenfd);
        return -1;
    }

    return listenfd;                        //返回已连接的套接字

}
