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


void selectionSort(int v[], int n, int ordem, Metrics *metrics) {
    int i,j,menor, troca;

    if (!v || n <= 1) return;

    if(ordem ==1){
        metrics->comparacoes = 0;
        for (i = 0; i < n-1; i++){
            metrics->comparacoes += 1;
            menor = i;
            for(j = i+1; j < n; j++){
                if(v[j] < v[menor]){
                    menor = j;

                } 

            }
            if (i != menor){
                troca = v[i];
                v[i] = v[menor];
                v[menor] = troca;
                metrics->trocas += 1;
            }
        }
    }
    else if(ordem == -1){
        metrics->comparacoes = 0;
        for (i = 0; i < n-1; i++){
            metrics->comparacoes += 1;
            menor = i;
            for(j = i+1; j < n; j++){
                if(v[j] > v[menor]){
                    menor = j;

                } 

            }
            if (i != menor){
                troca = v[i];
                v[i] = v[menor];
                v[menor] = troca;
                metrics->trocas += 1;
              }

        }
    }


}


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
    int op;
    printf("Digite 1 para crescente e -1 para decrescente: ");
    scanf("%d", &op);

    // Casos pedidos
    int v_vazio[]      = {};                 
    int v_um[]         = {7};
    int v_ordenado[]   = {1, 2, 3, 4, 5};
    int v_inverso[]    = {5, 4, 3, 2, 1};
    int v_repetidos[]  = {3, 1, 3, 2, 3};


    if (op == 1){
        run_test("Vazio",     NULL,           0,  1);
        run_test("1 elemento", v_um,          1,  1);
        run_test("Ordenado",   v_ordenado,    5,  1);
        run_test("Inverso",    v_inverso,     5,  1);
        run_test("Repetidos",  v_repetidos,   5,  1);
    }else if(op == -1){
        run_test("Vazio",     NULL,           0,  -1);
        run_test("1 elemento", v_um,          1,  -1);
        run_test("Ordenado",   v_ordenado,    5,  -1);
        run_test("Inverso",    v_inverso,     5,  -1);
        run_test("Repetidos",  v_repetidos,   5,  -1);
    }else{
        printf("opção invalida");
    } 

    return 0;
}