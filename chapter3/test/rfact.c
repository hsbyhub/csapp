long rfact( long n ){
    
    long res;
    if( n <= 1 )
        return 1;
    else
        res = n * rfact( n - 1 );

    return res;

}
