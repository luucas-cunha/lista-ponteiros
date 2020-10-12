#include <stdio.h>
#include <stdlib.h>

// Funcao responsavel pela multiplicacao matricial
void funcao(int **A, int **B, int **C, int nl_A, int nc_A, int nc_B){
    int nl_B = nc_A;
    int nl_C = nl_A;
    int nc_C = nc_B;
    int i, j, k;

    // Lendo os valores da matriz A
    for(i = 0; i < nl_A; i++){
        for(j = 0; j < nc_A; j++){
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\n");

    // Lendo os valores da matriz B
    for(i = 0; i < nl_B; i++){
        for(j = 0; j < nc_B; j++){
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Zerando os valores da matriz C
    for(i = 0; i < nl_C; i++){
        for(j = 0; j < nc_C; j++){
            C[i][j] = 0;
        }
    }

    // Armazenando o resultado da multiplicacao das matrizes A e B na matriz C
    for(i = 0; i < nl_C; i++){
        for(j = 0; j < nc_C; j++){
            for(k = 0; k < nl_C + abs(nl_A - nl_B); k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(){
    int **A, **B, **C;
    int nl_A, nc_A, nc_B;

    printf("Informe o numero de linhas da matriz A: ");
    scanf("%d", &nl_A);
    printf("Informe o numero de colunas da matriz A: ");
    scanf("%d", &nc_A);
    printf("Informe o numero de colunas da matriz B: ");
    scanf("%d", &nc_B);

    int nl_B = nc_A;
    int nl_C = nl_A;
    int nc_C = nc_B;
    int i, j, k;

    // Alocacao dinamica de memoria
    A = malloc(nl_A * sizeof(int*));
    A[0] = malloc(nl_A * nc_A * sizeof(int));

    B = malloc(nl_B * sizeof(int*));
    B[0] = malloc(nl_B * nc_B * sizeof(int));

    C = malloc(nl_C * sizeof(int*));
    C[0] = malloc(nl_C * nc_C * sizeof(int));

    for(i = 1; i < nl_A; i++){
        A[i] = A[i-1] + nc_A;
    }

    for(i = 1; i < nl_B; i++){
        B[i] = B[i-1] + nc_B;
    }

    for(i = 1; i < nl_C; i++){
        C[i] = C[i-1] + nc_C;
    }

    // Chamando a funcao responsavel por realizar a multiplicacao matricial
    funcao(A, B, C, nl_A, nc_A, nc_B);

    // Imprimindo as 3 matrizes
    printf("\nMatriz A\n");

    for(i = 0; i < nl_A; i++){
        for(j = 0; j < nc_A; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz B\n");

    for(i = 0; i < nl_B; i++){
        for(j = 0; j < nc_B; j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz C\n");

    for(i = 0; i < nl_C; i++){
        for(j = 0; j < nc_C; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Liberando a memoria alocada
    free(C[0]);
    free(C);
    free(B[0]);
    free(B);
    free(A[0]);
    free(A);

    return 0;
}
