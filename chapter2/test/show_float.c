#include<stdio.h>
#include<limits.h>
#include "show_bytes.c"

int main(){
  float a = 0.0, b = 1.1111, c = __FLT_MAX__;
  byte_pointer pa = (byte_pointer)&a;
  byte_pointer pb = (byte_pointer)&b;
  byte_pointer pc = (byte_pointer)&c;
  show_bytes(pa, sizeof(float));
  show_bytes(pb, sizeof(float));
  show_bytes(pc, sizeof(float));
}
