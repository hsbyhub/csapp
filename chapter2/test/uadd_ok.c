#ifndef __UADD_OK__
#define __UADD_OK__ 

#include <limits.h>

int uadd_ok(unsigned int x, unsigned int y){
  return x <= x - y;
}

#endif 
