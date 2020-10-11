#include <stdio.h>

// Programa que calcula uma potencia de 2 utilizando um ponteiro para funcao
int pow2(int x){
    return x*x;
}

int main(){
    int num = 5;
    int (*pf) (int) = &pow2;

    printf("%d^2 = %d", num, pf(num));

    return 0;
}
