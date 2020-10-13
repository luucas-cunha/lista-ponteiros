#include <stdio.h>
#include <stdlib.h>

void ordenar(float *x, int n){
    float aux;
    int i, j;

    for (i = 1; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (x[j] > x[j+1]) {
                aux = x[j];
                x[j] = x[j+1];
                x[j+1] = aux;
            }
        }
    }
}

void funcao(float *x, int n, int size, void (*f) (float*, int)) {
    float aux;
    int i;

    x = malloc(n * size);

    for(i = 0; i < n; i++){
        scanf("%f", &x[i]);
    }

    f(x, n);

    printf("\nVetor ordenado:\n");
    for(i = 0; i < n; i++){
        printf("%.2f ", x[i]);
    }

    free(x);
}

int main(){
    float *x;
    int n;

    printf("Informe o tamanho do array: ");
    scanf("%d", &n);

    funcao(x, n, sizeof(float), ordenar);

    return 0;
}
