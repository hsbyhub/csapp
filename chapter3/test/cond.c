
void cond(long a, long *p){
    if(p && a > *p) *p = a;
}

int main(){

    long a = 1;
    long b = 1;
    long *p = &a;

    cond(b, p);
}

