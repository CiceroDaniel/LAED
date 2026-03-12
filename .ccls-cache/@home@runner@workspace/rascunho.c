/*
  Selection Sort — Esqueleto (com contadores + testes)
  Objetivos:
  1) Implementar selectionSort (crescente)
  2) Instrumentar comparações e trocas
  3) Testar com casos: vazio, 1 elemento, ordenado, inverso, repetidos
  4) Desafio: ordem crescente/decrescente via parâmetro

  Compile:
    gcc -Wall -Wextra -O2 selection_skeleton.c -o sel
  Run:
    ./sel
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long comparacoes;
    long long trocas;
} Metrics;

static void print_array(const int v[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]");
}

static void swap_int(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
  selectionSort:
    - ordem =  1  => crescente (seleciona o menor)
    - ordem = -1  => decrescente (seleciona o maior)

  Regras de instrumentação:
    - metrics->comparacoes++ em cada comparação entre elementos
    - metrics->trocas++ APENAS quando houver troca real (idxEscolhido != i)
*/
void selectionSort(int v[], int n, int ordem, Metrics *metrics) {
    int i,j,emnor, troca;
    for (i = 0; i < n-1; i++){
        menor = i;
        for(j = i+1; j < n; j++){
            if(v[j] < v[menor])
            menor = j;
        }
        if (i != menor){
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;

          }
    }
}

/* Executa um teste: copia o vetor base, ordena e imprime resultados */
static void run_test(const char *label, const int base[], int n, int ordem) {
    int *v = NULL;
    if (n > 0) {
        v = (int*) malloc((size_t)n * sizeof(int));
        if (!v) {
            printf("Falha de memória no teste %s\n", label);
            return;
        }
        for (int i = 0; i < n; i++) v[i] = base[i];
    }

    Metrics m = {0, 0};

    printf("\n=== %s | ordem=%s ===\n", label, (ordem == 1 ? "crescente" : "decrescente"));
    printf("Antes: ");
    print_array(v, n);
    printf("\n");

    selectionSort(v, n, ordem, &m);

    printf("Depois: ");
    print_array(v, n);
    printf("\n");
    printf("Comparacoes: %lld | Trocas: %lld\n", m.comparacoes, m.trocas);

    free(v);
}

int main(void) {
    // Casos pedidos
    int v_vazio[]      = {};                 // n = 0 (não use sizeof aqui)
    int v_um[]         = {7};
    int v_ordenado[]   = {1, 2, 3, 4, 5};
    int v_inverso[]    = {5, 4, 3, 2, 1};
    int v_repetidos[]  = {3, 1, 3, 2, 3};

    // Dica: para vetor vazio, passe base=NULL e n=0 (mais simples e portável).
    run_test("Vazio",     NULL,           0,  1);
    run_test("1 elemento", v_um,          1,  1);
    run_test("Ordenado",   v_ordenado,    5,  1);
    run_test("Inverso",    v_inverso,     5,  1);
    run_test("Repetidos",  v_repetidos,   5,  1);

    // Desafio extra: decrescente
    run_test("Ordenado",   v_ordenado,    5, -1);
    run_test("Inverso",    v_inverso,     5, -1);
    run_test("Repetidos",  v_repetidos,   5, -1);

    return 0;
}