#include <csapp.h>

void div0_handler(int sig){
    printf("Div to 0 error!\n");
    exit(0);
}

int main(){
    signal(8, div0_handler);
    float a = 1/0;
    exit(0);
}
