void merge( long src1[], long src2[], long dest[], long n ){

    long i1 = 0;
    long i2 = 0;
    long id = 0;

    while( i1 < n && i2 < n ){
        long v1 = src1[i1];
        long v2 = src2[i2];
        long test = v1 < v2;
        dest[id++] = test ? v1 : v2;//将数组中较小者加入目标数组
        i1 += test;
        i2 += (1 - test);
    }

    //上面循环结束时，可能存在其中一个数组的数据未归并
    while ( i1 < n ){
        dest[id++] = src1[i1++];
    }

    while ( i2 < n ){
        dest[id++] = src2[i2++];
    }

}
