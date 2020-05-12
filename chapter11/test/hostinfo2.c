#include <csapp.h>

int main(int argc, char** argv){
    
    struct addrinfo *p;     //temp
    struct addrinfo *listp; //接收getaddrinfo的结果
    struct addrinfo hints;  //限制条件
    char buf[MAXLINE];
    int rc, flags;

    if( argc != 2){
        fprintf(stderr, "usage:%s <domain name> \n", argv[0]);
        exit(0);
    }

    memset(&hints, 0, sizeof(struct addrinfo));                         //清空
    hints.ai_family = AF_INET;                                          //设置为只接受IPv4
    hints.ai_socktype = SOCK_STREAM;                                    //套接字流
    if ( ( rc = getaddrinfo(argv[1], NULL, &hints, &listp) ) != 0 ){    //地址可以是域名，也可以使点分十进制地址，查询主机套接字
        fprintf(stderr, "getaddrinfo error:%s \n", gai_strerror(rc));
        exit(0);
    }

    flags = NI_NUMERICHOST;         //将主机名转换为数字地址字符串
    for( p = listp; p; p = p->ai_next ){
        getnameinfo(p->ai_addr, p->ai_addrlen, buf, MAXLINE, NULL, 0, flags);//将套接字地址的主机信息提取出来
        printf("%s \n", buf);
    }

    freeaddrinfo(listp);            //释放套接字地址链表

}
