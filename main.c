int comparacoes = 0; // Contador global
int trocas = 0;      // Contador global

void bubbleSort(int v[], int n) {
  // TODO: Implementar aqui
  // Incrementar comparacoes++ a cada comparação
  // Incrementar trocas++ a cada troca

  int i, j, aux;

  // BUBBLE SORT COM EARLY STOP

  for (i = 0; i < n - 1; i++) {
    int houveTroca = 0;
    for (j = 0; j < n - i - 1; j++) {
      comparacoes++;
      
      if (v[j] > v[j + 1]) {
        aux = v[j];
        v[j] = v[j + 1];
        v[j + 1] = aux;
        trocas++;
        houveTroca = 1;
      }
    }

    if (houveTroca == 0){
      break;
    }
    
  }
}

void imprimirVetor(int v[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");
}

int main() {
  int dados[] = {64, 25, 34, 12, 22, 11, 90};
  int n = 7;

  printf("Vetor original: ");
  imprimirVetor(dados, n);

  bubbleSort(dados, n);

  printf("Vetor ordenado: ");
  imprimirVetor(dados, n);
  printf("Comparações: %d | Trocas: %d\n", comparacoes, trocas);

  return 0;
}