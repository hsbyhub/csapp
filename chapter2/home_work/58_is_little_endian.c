#ifndef __IS_LITTLE_ENDIAN__
#define __IS_LITTLE_ENDIAN__

#include <stdio.h>

int is_little_endian(){
    unsigned int x = 1;
    unsigned char* b ;//最小存取单位为字节
    int i = 0;
    for(i = 0; i < sizeof(int)>>1; ++i){
        b = (unsigned char *)&x;
        if(*b == 1) return 1;//说明1放在了左半段，说明是用小端法操作
    }
    return 0;
    
}

void test_is_little_endian(){

    int is = is_little_endian();
    printf("%s\n",
            is==1 ? "is little endian" : "is not little endian"
            );

}

#endif // !__IS_LITTLE_ENDIAN__