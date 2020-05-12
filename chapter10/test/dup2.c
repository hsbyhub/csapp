#include <csapp.h>

int main(){

    char c;
    int f1, f2 ;

    f1 = Open("./foobar.txt", O_RDONLY, 0);
    f2 = Open("./foobar.txt", O_RDONLY, 0);

    Read(f2, &c, 1);
    dup2(f2, f1);
    Read(f1, &c, 1);

    printf("c = %c \n", c);

    exit(0);

}
