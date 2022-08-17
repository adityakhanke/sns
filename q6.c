#include<gmp.h>
#include<stdio.h>

int main(){

    mpz_t a, b, x, y, d, temp;
    mpz_init(a);
    mpz_init(b);

    gmp_scanf("%Zd", a);
    gmp_scanf("%Zd", b);

    if(mpz_cmp(a, b)<0){
        mpz_t temp;
        mpz_set(temp, a);
        mpz_set(a, b);
        mpz_set(b, temp);
    }

    if(mpz_cmp(b, 0)==0){
        gmp_set(x, 1);
        gmp_set(y, 0);
    }else{
        mpz_t x2, x1, y2, y1, q, r;
        mpz_init(x);
        mpz_init(y);
        mpz_init(q);
        mpz_init(r);

        while(mpz_cmp(b, 0)>0){
            mpz_cdiv_q(q, a, b);
            mpz_cdiv_r(r, a, b);
            mpz_mul(temp, q, x1);
            mpz_sub(x, x2, temp);
            mpz_mul(temp, q, y1);
            mpz_sub(y, y2, temp);
            mpz_set(a, b);
            mpz_set(b, r);
            mpz_set(x2, x1);
            mpz_set(x1, x);
            mpz_set(y2, y1);
            mpz_set(y1, y);
        }
    }

    mpz_mul(temp, a, x);
    mpz_mul(y, b, y);
    mpz_add(d, temp, y);

    if(mpz_cmp(d, 1)>0){
        gmp_printf("it does not exist");
    }else{
        gmp_printf("The inverse is %Zd", x);
    }


    return 0;
}