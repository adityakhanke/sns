#include<gmp.h>
#include<stdio.h>

int main(){
    mpz_t a, n, b;
    mpz_init(a);
    mpz_init(n);
    mpz_init(b);

    int x, temp;

    gmp_scanf("%Zd", a);
    gmp_scanf("%d", x);
    gmp_scanf("%Zd", n);

    // gmp_printf("a: %Zd, x: %d, n: %Zd", a, x, n);
    int arr[1000], i;
    temp = x;
    i = 0;
    while(temp){
        arr[i] = temp%2;
        temp = temp/2;
        i++;
    }

    gmp_set(b, 1);
    if(mpz_cmp(x, 0) == 0){
        gmp_printf(1);
    }else{
        if(arr[0] == 1){
            mpz_set(b, a);
        }
        for(int j=1;j<i;j++){
            
        }
    }

    return 0;
}