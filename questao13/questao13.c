#include <stdio.h>
#include <stdlib.h>

void funcao(int n){
    float *x;
    float aux;
    int i, j;

    x = malloc(n * sizeof(float));

    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Valores:\n");

    for (i = 0; i < n; i++) {
        printf("%.2f ", x[i]);
    }

    for (i = 1; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (x[j] > x[j+1]) {
                aux = x[j];
                x[j] = x[j+1];
                x[j+1] = aux;
            }
        }
    }

    printf("\n\nValores ordenados:\n");

    for (i = 0; i < n; i++) {
        printf("%.2f ", x[i]);
    }

    free(x);
}

int main(){
    int n;

    printf("Informe a quantidade de valores que serao lidos: ");
    scanf("%d", &n);

    funcao(n);

    return 0;
}
