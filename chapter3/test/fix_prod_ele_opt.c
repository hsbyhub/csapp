#define N 16
typedef int fix_matrix[N][N];

int fix_prod_ele_opt(fix_matrix A, fix_matrix B, long i, long k){

    int *Ap = &A[i][0];
    int *Bp = &B[0][k];
    int *Sp = &B[N][k];

    int res = 0;
    do{

        res += *Ap * *Bp;
        Ap++;
        Bp += N;

    }while( Bp != Sp );

    return res;

}
