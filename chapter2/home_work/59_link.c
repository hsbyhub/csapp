#ifndef __LINK_C__
#define __LINK_C__

#include <stdio.h>
#include <malloc.h>
#include "58_is_little_endian.c"

typedef unsigned char* byte_pointer;
size_t UINT_SIZE = sizeof(unsigned);

unsigned link(unsigned x, unsigned y){
    byte_pointer p = (byte_pointer)&y;
    byte_pointer resp = malloc(UINT_SIZE);
    size_t i;

    if(is_little_endian()){

        for (i = UINT_SIZE - 1; i > 0; i--){
            resp[i] = p[i];
        }
        p = (byte_pointer)&x;
        resp[0] = p[0];

    }else{

        for (i = 0; i < UINT_SIZE - 1; i++){
            resp[i] = p[i];
        }
        p = (byte_pointer)&x;
        resp[UINT_SIZE - 1] = p[UINT_SIZE - 1]; 

    }
    return *(unsigned*)resp;
}

void test_link(){
    unsigned a = 0x123456ab;
    unsigned b = 0x12345678;

    printf("%x\n", link(a, b));
}




#endif // !__LINK_C__
