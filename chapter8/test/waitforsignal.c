#include <csapp.h>

volatile sig_atomic_t pid;

void sigchld_handler( int s ){

    int olderrno = errno;
    printf(" 父进程调用处理程序，处理中... \n");
    pid = waitpid(-1, NULL, 0);
    errno = olderrno;

}

void sigint_handler(int s){
    putchar('\n');
    exit(0);
}

int main(){

    sigset_t mask, prev;
    
    Signal( SIGCHLD, sigchld_handler );
    Signal( SIGINT, sigint_handler );

    Sigemptyset(&mask);
    Sigaddset(&mask, SIGCHLD);

    while(1){

        Sigprocmask(SIG_BLOCK, &mask, &prev);//阻塞所有信号
        if( Fork() == 0 ){
            exit(0);
        }

        pid = 0;
        Sigprocmask(SIG_SETMASK, &prev, NULL);//解锁所有信号


        while( !pid ) sigsuspend(&prev);//等待子进程结束的信号
        printf("pid %d running...", getpid());

    }
    
    exit(0);

}
