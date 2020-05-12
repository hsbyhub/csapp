#include "show_bytes.c"

int main(){
  unsigned int val = 0x87654321;
  byte_pointer valp = (byte_pointer) &val;
  show_bytes(valp, sizeof(val));

  const char* cval = "abcdef";
  show_bytes((byte_pointer)cval, 7);

}
