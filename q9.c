#include<sdtio.h>
#include<gmp.h>

int main(){
    mpz_t a, m, order, modulo, temp;
    mpz_init(a);
    mpz_init(m);
    mpz_init(order);
    mpz_init(modulo);
    int i = 0;

    gmp_scanf("%Zd %Zd", a, m);
    mpz_set(temp, a);
    while(1){
        mpz_cdiv_r(modulo, a, m);
        if(mpz_cmp(modulo, 1)==0){
            mpz_set(order, i);
            break;
        }else{
            mpz_mul(a, a, temp);
            i++;
        }
    }

    gmp_printf("The inverse is %Zd", order);


    return 0;
}