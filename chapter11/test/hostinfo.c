/* $begin hostinfo */
#include <csapp.h>

int main(int argc, char **argv) 
{
    char **pp;
    struct in_addr addr;    //IP地址结构
    struct hostent *hostp;  //主机套接字信息

    if (argc != 2) {
        fprintf(stderr, "usage: %s <domain name or dotted-decimal>\n", argv[0]);       
        exit(0);
    }

    if (inet_aton(argv[1], &addr) != 0) 
        hostp = Gethostbyaddr((const char *)&addr, sizeof(addr), AF_INET);  //转换成功
    else                                    
        hostp = Gethostbyname(argv[1]);                                     //转换失败默认源地址为域名，

    printf("official hostname: %s\n", hostp->h_name);

    for (pp = hostp->h_aliases; *pp != NULL; pp++)                          //多个域名映射到同一个主机
        printf("alias: %s\n", *pp);

    for (pp = hostp->h_addr_list; *pp != NULL; pp++) {                      //遍历IP地址结构数组
        addr.s_addr = ((struct in_addr *)*pp)->s_addr;
        printf("address: %s\n", inet_ntoa(addr));                           //将IP地址转化为字符串
    }
    exit(0);
}
/* $end hostinfo */
