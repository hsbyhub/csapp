#include <csapp.h>
//#include <sys/types.h>
//#include <unistd.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <errno.h>
//#include <string.h>
//#include <time.h>

void unix_error( char *msg ){

    fprintf(stderr, "%s: %s \n", msg, strerror(errno));

}

pid_t Fork(){

    pid_t pid;

    if( ( pid = fork() ) < 0){
        unix_error("fork error");
    }

    return pid;

}

void test1(){

    pid_t pid;
    int x = 1;

    pid = Fork();
    if( pid == 0 ){
        printf("child: x = %d \n", ++x);
        exit(0);
    }

    printf("parent: x = %d \n", --x);
    exit(0);
    
}

void test2(){
    Fork();
    Fork();
    printf("hello\n");
    exit(0);
}

void test3(){
    printf("hello");
    Fork();
    Fork();
    printf(" world!\n");
    exit(0);

}

int main(){
    test3();
}
