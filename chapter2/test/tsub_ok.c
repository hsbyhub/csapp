#ifndef __TSUB_OK__
#define __TSUB_OK__ 

#include <limits.h>
#include <stdio.h>
#include "tadd_ok.c"

/* 
 * 当其中某个值为INT_MIN的时候,直接改变符号会溢出
 */
int tsub_ok(int x, int y){
  return tadd_ok(x, -y);
}

int main(){
  printf("tsub_ok(INT_MIN, 1) = %d\n", tsub_ok(INT_MIN, 1));
  printf("tsub_ok(INT_MIN, INT_MAX) = %d\n", tsub_ok(INT_MIN, INT_MAX));
  printf("tsub_ok(INT_MIN, INT_MIN) = %d\n", tsub_ok(INT_MIN, INT_MIN));
}

#endif 
