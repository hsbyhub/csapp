#include <csapp.h>

typedef void ( *sighandler_t )(int);

void mysighandler(int pid){
    return;
}

unsigned int smooze(unsigned int want){

    int r = sleep(want);
    printf("Sleep %d of %d seconds \n", want - r, want) ;
    
    return r;

}

int main( int argc, char *argv[] ){

    if ( argc != 2 ){
        fprintf( stderr, " usage: %s <secs> \n", argv[0] );
        exit(0);
    }

    signal(SIGINT, mysighandler);
    (void)snooze( atoi( argv[1] ) );
    
    exit(0);

}
