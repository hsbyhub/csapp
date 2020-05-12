
long lt_cnt = 0;
long ge_cnt = 0;

long absdiff_se(long x, long y){;
   long res ;
   if(x < y){
       lt_cnt++;
       res = y - x;
   }
   else{
       ge_cnt++;
       res = x - y;
   }
   return res;
}

long gotodiff_se(long x, long y){

    long res;
    if(x >= y) goto x_ge_y;
    lt_cnt++;
    res = y - x;
    return res;
    
x_ge_y:
    ge_cnt++;
    res = x - y;
    return res;
}
