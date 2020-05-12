#include <stdio.h>
#include <stdint.h>


int main(){
  
  int x = -1;
  unsigned u = 2147483648;

  printf("sizeof(int) = %d \n", sizeof(x));
  printf("sizeof(unsigned) = %d \n", sizeof(unsigned));

  printf("x = %u = %d\n", x, x);
  printf("u = %u = %d\n", u, u);

  return 0;
}
