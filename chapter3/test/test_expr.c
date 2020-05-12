
long test(long a, long b){

    return a > b ? a - b : b - a;

}

long test2(long a, long b){

    long res = a - b;
    long tmp = b - a;
    int test = a < b;
    if (test) res = tmp;

    return res;

}
