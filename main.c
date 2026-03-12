#include <stdio.h>

int particiona (int *V, int inicio, int final) {
    int esq, dir, pivo, aux;
    esq = inicio+1;
    dir = final;
    pivo = V[inicio];
    while (esq <= dir) {
        while (esq <= final && V[esq] <= pivo )
            esq++;
        while (dir >= inicio && V[dir] > pivo)
            dir--;
        if (esq < dir) {
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }

  aux = V[inicio];
  V[inicio] = V[dir];
  V[dir] = aux;
    return dir;
}

void quickSort(int *V, int inicio, int fim) {
    int pivo;
    if (fim > inicio) {
        pivo = particiona (V, inicio,fim);
        quickSort(V, inicio, pivo-1);
        quickSort(V, pivo+1, fim);
    }
}


int main() {

  int n;
  printf("Digite o tamanho do vetor: ");
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
  scanf("%d", &n);
#pragma GCC diagnostic pop
  int vetor[n];

  printf("Digite os %d elementos:\n", n);
  for(int i = 0; i < n; i++) {
      printf("Elemento %d: ", i + 1);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
      scanf("%d", &vetor[i]);
#pragma GCC diagnostic pop
  }
  printf("Vetor ANTES: ");
  for(int i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
  
  quickSort(vetor, 0, n-1);
  
  printf("Vetor DEPOIS: ");
  for(int i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
  /*89 77 2 20 38 */
  return 0;
}
