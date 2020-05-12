#include "vec.c"


#define INDENT  1;
#define OP      *;


void combine1( vec_ptr v, data_t *dest ){

    long i;
    long len = v->len;
    data_t* data = get_start( v );

    *dest = INDENT;
    for ( i = 0; i < len; i++ ){
        data_t val;
        val = data[i];
        *dest = *dest * val;
    }

}

int main(){

    int i;
    vec_ptr p = new_vec(10) ;
    for( i  = 0; i < p->len; i++ ){
        p->data[i] = i;
    }
    data_t a[10];

    combine1( p, a );

    return 0;

}
