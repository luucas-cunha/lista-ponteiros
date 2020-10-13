// A biblioteca GC permite alocar memoria dinamicamente sem
// desalocar explicitamente a memoria que nao eh mais util
#include <gc.h>
#include <stdio.h>

int main(){
    int i, n, *x;

    scanf("%d", &n);

    // Inicializacao
    GC_INIT();

    // O malloc convencional eh substituido por GC_MALLOC
    // Ha tambem a funcao GC_REALLOC(), que se comporta como a funcao realloc do C
    x = GC_MALLOC(n * sizeof(int));

    for (i = 0; i < n; i++){
        x[i] = i+1;
    }

    // Uma funcao GC_FREE() eh fornecida, mas nao precisa ser chamada
    // As vezes, para objetos muito pequenos, o programa tera um desempenho
    // melhor caso a funcao nao seja chamada e o proprio coletor fique
    // responsavel por fazer o trabalho

    return 0;
}
