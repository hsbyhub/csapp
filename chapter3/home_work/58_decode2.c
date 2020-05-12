long decode2( long x, long y, long z ){

    long tmp = ( y - z );
    long res = x * tmp;
    tmp <<= 63;
    tmp >>= 63;
    res ^= tmp;
    return res;
    
}
