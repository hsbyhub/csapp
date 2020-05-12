#include <csapp.h>

#define MAX_LINE 128

int main(){

    char c[MAX_LINE];
    while(rio_readn(0, c, 1) != 0){
        rio_writen(1, c, 1);
    }
    
}
