#ifndef __FIX_SET_DIAG__
#define __FIX_SET_DIAG__

#include <stdio.h>

#define N 16
typedef int fix_matrix[N][N];

void fix_set_diag(fix_matrix A, int val){

    int *Ap = A[0];
    int *Sp = Ap + N * N;

    do{
        *Ap = val;
        Ap += N + 1;
    }while( Ap < Sp );

}

void test_fix_set_diag(){

    fix_matrix A;
    int *Ap = A[0];
    int i;
    for ( i = 0; i < N << 4 ; i++){
        if ( i % N == 0 ){
            printf("\n");
        }
        *(Ap + i) = i;
        printf("%-4d", *(Ap + i)) ;
    }

    fix_set_diag(A, 9);

    for ( i = 0; i < N << 4 ; i++){
        if ( i % 16 == 0 ){
            printf("\n");
        }
        printf("%-4d", *(Ap + i)) ;
    }
    printf("\n");

}


#endif
