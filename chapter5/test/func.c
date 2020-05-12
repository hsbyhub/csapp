long count = 0;

long f(){
    return count++;
}

long fun1(){
    return f() + f() + f() + f();
}

long fun1in(){

    long tmp = count++;
    tmp += count++;
    tmp += count++;
    tmp += count++;
    return tmp;

}
