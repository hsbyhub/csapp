#include <stdio.h>

long fact_do_int(){

    long res;
    long tmp = 1;
    long n = 1;
    do{

        n++;
        res = tmp;
        tmp *= n;

    }while(tmp / n == res);

    return res;
}

int main(){

    printf("%ld \n", fact_do_int());

}
