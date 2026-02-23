#include <stdio.h>

//QUESTÃO 3, LETRA A

void bubble_notas(float notas[], int n, long *comparacoes, long *trocas){
  *comparacoes = 0, *trocas = 0;
  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n-i-1; j++){
      (*comparacoes)++;
      if(notas[j] < notas[j+1]){
        float aux = notas[j];
        notas[j] = notas[j+1];
        notas[j+1] = aux;
        (*trocas)++;
      }
    }
  }
}

int main(){
  int n = 12;
  float notas[12] = {725.5, 892.0, 650.0, 945.5, 780.2, 910.0, 
                     675.8, 823.4, 955.0, 712.3, 880.7, 698.1};
  printf("--Notas antes da ordenação--\n");
  for(int i = 0;i <n;i++){
    printf("%.1f ", notas[i]);
  }

  long comparacoes, trocas;
  bubble_notas(notas, n, &comparacoes, &trocas);

  printf("notas depois da ordenação\n");

  for(int i =0; i < n;i++){
    printf("%.1f ", notas[i]);
  }

  printf("\n");


  printf("\n TOP 3 notas: %.1f, %.1f, %.1f\n", notas[0], notas[1], notas[2]);

  float media = 0;
  for(int i = 0; i < n;i++){
    media += notas[i];
  }

  media /= n;

  printf("Média das notas: %.1f\n", media);
  printf("Número de comparações: %ld\n", comparacoes);
  printf("Número de trocas: %ld\n", trocas);
}