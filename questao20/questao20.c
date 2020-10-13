#include <gc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int main() {
    clock_t t1, t2;
    int *x;
    int n = 10000;

    // Verificando tempo de execucao do malloc/free
    t1 = clock(); // Armazena o tempo
    x = malloc(n * sizeof(int));
    free(x);
    t1 = clock() - t1; // Tempo final - tempo inicial

    GC_INIT();

    // Verificando tempo de execucao do GC_MALLOC/GC_FREE
    t2 = clock(); // Armazena o tempo
    x = GC_MALLOC(n * sizeof(int));
    GC_FREE(x);
    t2 = clock() - t2; // Tempo final - tempo inicial

    // Imprime os tempos em milissegundos
    printf("Tempo de execucao (malloc/free): %lf ms\n", ((double)t1)/((CLOCKS_PER_SEC/1000)));
    printf("Tempo de execucao (GC_MALLOC/GC_FREE): %lf ms", ((double)t2)/((CLOCKS_PER_SEC/1000)));

    return 0;
}
