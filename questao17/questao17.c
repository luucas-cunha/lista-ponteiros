#include <stdio.h>
#include <stdlib.h>

void funcao(int *a, int *b, int *c, int n){
    // Alocacao dinamica
    a = malloc(n * sizeof(int));
    b = malloc(n * sizeof(int));
    c = malloc(n * sizeof(int));

    int i;

    // Vetor a
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    // Vetor b
    for(i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }

    // Vetor c
    for(i = 0; i < n; i++){
        c[i] = a[i] + b[i];
        printf("%d ", c[i]);
    }

    // Liberacao de memoria
    free(c);
    free(b);
    free(a);
}

int main() {
    int *x, *y, *z;
    int n;

    printf("Informe o tamanho dos vetores: ");
    scanf("%d", &n);

    funcao(x, y, z, n);

    return 0;
}
