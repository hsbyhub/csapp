
long sum ( long *start, long count ){

    long sum = 0;
    while ( count ){
        sum += *start;
        start++;
        count--;
    }

    return sum;

}

int main(){

    long a[4] = {
        6, 66, 666, 6666
    };
    sum(&a[0], 4);

    return 0;

}
