#include<stdio.h>
double x;
int y;

void f(){
    x = -0.0;
    int ys = sizeof(y);
    int xs = sizeof(x);
    printf("x = 0x%f, sizeof(x) = %d \ny = 0x%x, sizeof(y) = %d \n",x ,xs ,y , ys);
}
