#include <stdlib.h>


typedef long data_t;
typedef struct {
    long len;
    data_t* data;
}vec_rec, *vec_ptr;


vec_ptr new_vec( long len ){

    vec_ptr res = (vec_ptr) malloc(sizeof(vec_rec));
    if ( res == NULL )
        return NULL;
    res->len = len;

    if ( len > 0 ){
        res->data = (data_t *) malloc( len * sizeof(data_t) );
        if(res->data == NULL){
            free( ( void * ) res );
            return NULL;
        }
    }
    
    return res;

}

int get_vec_element( vec_ptr v, long index, data_t* dest ){

    if ( index < 0 || index >= v->len )
        return 0;
    *dest = v->data[index];
    return 1;

}

long vec_length( vec_ptr v ){
    return v->len;
}

data_t* get_start( vec_ptr v ){
    return v->data;
}
