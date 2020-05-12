#include <csapp.h>

int main(){

    char c;
    ssize_t flag;

    while( ( flag = Read(STDIN_FILENO, &c, 1) )!= 0  && flag != -1)
        Write(STDOUT_FILENO, &c, 1);

    exit(0);

}
