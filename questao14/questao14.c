//Inclusao das bibliotecas do C
#include <stdio.h>
#include <stdlib.h>

// Funcao de ordenacao da funcao qsort() do C
int compare(const void * a, const void * b){
  return (*(float*)a - *(float*)b);
}

// Funcao responsavel por ler os valores do array e ordena-lo
void funcao(int n){
  // Declaracao de variaveis locais da funcao
  int i;
  float *x;

  // Alocacao dinamica
  x = malloc(n * sizeof(float));

  // Lendo os valores do array
  for(i = 0; i < n; i++){
    scanf("%f", &x[i]);
  }

  // Chamando a funcao qsort() do C
  qsort(x, n, sizeof(float), compare);

  // Exibindo o array ordenado
  for (i = 0; i < n; i++){
      printf("%.2f ", x[i]);
  }

  // Liberando o bloco de memoria alocado
  free(x);
}

int main(){
  // Declaracao da variavel n
  int n;

  // Pedindo ao usuario para que digite o tamanho do array
  printf("Informe o tamanho do array: ");

  // Lendo o tamanho do array
  scanf("%d", &n);

  // Chamando a funcao
  funcao(n);

  // Retorno da funcao main
  return 0;
}
