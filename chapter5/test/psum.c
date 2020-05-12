void psum1( float a[], float p[], long n ){

    long i;
    p[0] = a[0];
    for ( i = 0; i < n; i++ )
        p[i] = p[i - 1] + a[i];

}

void psum2( float a[], float p[], long n ){
    long i;
    p[0] = a[0];
    for ( i = 0; i < n - 1; i += 2 ){
        int tmp = p[i - 1] + a[i];
        p[i] = tmp;
        p[i + 1] = tmp + a[i + 1];
    }
    if (i < n){
        p[i] = p[i - 1] + a[i];
    }
}
