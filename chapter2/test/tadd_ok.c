#ifndef __TADD_OK__
#define __TADD_OK__ 

int tadd_ok(int x, int y){
 return !(x >= 0 && y >= 0 && x + y < 0) && !(x < 0 && y < 0 && x + y <= 0);
}

#endif 
