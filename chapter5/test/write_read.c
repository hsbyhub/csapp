void write_read( long *src, long *dest, long n ){

    long cnt = n;
    long val = 0;

    while(cnt){
        *dest = val;
        val = ( *src ) + 1;
        cnt--;
    }

}
