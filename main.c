#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sem_otimizacao(int dados[], int n, long *comparacoes, long *trocas){
  *comparacoes = 0, *trocas = 0;
  for(int i = 0; i < n -1; i++){
    for(int j = 0; j < n - i - 1; j++){
      (*comparacoes)++;
      if(dados[j] > dados[j+1]){
        int aux = dados[j];
        dados[j] = dados[j + 1];
        dados[j + 1] = aux;
        (*trocas)++;
      }
    }
  }
}

void bubble_otimizado(int dados[], int n, long *comparacoes, long *trocas){
  *comparacoes = 0, *trocas = 0;
  for(int i = 0; i < n-1; i++){
    int trocou = 0;
    for(int j = 0; j < n-i-1; j++){
      (*comparacoes)++;
      if(dados[j] > dados[j+1]){
        int aux = dados[j];
        dados[j] = dados[j+1];
        dados[j+1] = aux;
        (*trocas)++;
        trocou = 1;
      }
    }
    if (trocou == 0){
      break;
    }
  }
}

void testar(char* nome, int dados[], int n){
  printf("\n------- %s -------\n", nome);

  // SEM otimização
  int copia1[20]; 
  for(int k = 0; k<n; k++) copia1[k] = dados[k];
  long comps1, trocas1;
  bubble_sem_otimizacao(copia1, n, &comps1, &trocas1);  
  printf("Sem otimização: %ld comparações, %ld trocas\n", comps1, trocas1);

  // COM otimização
  int copia2[20]; 
  for(int k = 0; k<n; k++) copia2[k] = dados[k];
  long comps2, trocas2;
  bubble_otimizado(copia2, n, &comps2, &trocas2);  
  printf("Com otimização: %ld comparações, %ld trocas\n", comps2, trocas2);
}

int main(){
  int n = 20;

  // 1. Vetor ORDENADO
  int ordenado[20];
  for(int i = 0; i < n; i++){
    ordenado[i] = i;
  }
  testar("Vetor ordenado", ordenado, n);

  // 2. Vetor REVERSO
  int reverso[20];
  for(int i = 0; i < n; i++){
    reverso[i] = n - 1 - i;  
  }
  testar("Vetor reverso", reverso, n);

  // 3. Vetor ALEATÓRIO
  int aleatorio[20];  
  srand(time(NULL));
  for(int i = 0; i < n; i++){
    aleatorio[i] = rand() % 100;
  }
  testar("Vetor aleatorio", aleatorio, n);

  return 0;
}
