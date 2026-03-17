#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void copiarVetor(int origem[], int destino[], int n){
    for(int i=0;i<n;i++)
        destino[i]=origem[i];
}

void imprimirVetor(int v[], int n){
    for(int i=0;i<n;i++)
        printf("%d ",v[i]);
    printf("\n");
}

// =====================================================
// QUESTÃO 1 – Bubble Sort básico
// =====================================================

void bubbleSort(int v[], int n){
    int temp;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(v[j]>v[j+1]){
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
}

// =====================================================
// QUESTÃO 2 – Bubble Sort instrumentado
// =====================================================

void bubbleSortInstrumentado(int v[], int n){
    int temp;
    int comparacoes=0;
    int trocas=0;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){

            comparacoes++;

            if(v[j]>v[j+1]){
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
                trocas++;
            }
        }
    }

    printf("Comparacoes: %d\n",comparacoes);
    printf("Trocas: %d\n",trocas);
}

// =====================================================
// QUESTÃO 3 – Bubble Sort com Early Stop
// =====================================================

void bubbleSortOptimizado(int v[], int n){

    int temp;
    int houveTroca;

    for(int i=0;i<n-1;i++){

        houveTroca=0;

        for(int j=0;j<n-1-i;j++){

            if(v[j]>v[j+1]){

                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;

                houveTroca=1;
            }
        }

        if(!houveTroca)
            break;
    }
}

// =====================================================
// QUESTÃO 5 – Bubble Sort com ordem
// =====================================================

void bubbleSortOrdem(int v[], int n, int ordem){

    int temp;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){

            if((ordem==1 && v[j]>v[j+1]) ||
               (ordem==-1 && v[j]<v[j+1])){

                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
}

// =====================================================
// QUESTÃO 6 – Selection Sort
// =====================================================

void selectionSort(int v[], int n){

    int menor,temp;

    for(int i=0;i<n-1;i++){

        menor=i;

        for(int j=i+1;j<n;j++){
            if(v[j]<v[menor])
                menor=j;
        }

        temp=v[i];
        v[i]=v[menor];
        v[menor]=temp;
    }
}

// =====================================================
// QUESTÃO 8 – Selection Sort instrumentado
// =====================================================

void selectionSortInstrumentado(int v[], int n){

    int comparacoes=0;
    int trocas=0;
    int menor,temp;

    for(int i=0;i<n-1;i++){

        menor=i;

        for(int j=i+1;j<n;j++){

            comparacoes++;

            if(v[j]<v[menor])
                menor=j;
        }

        if(menor!=i){
            temp=v[i];
            v[i]=v[menor];
            v[menor]=temp;
            trocas++;
        }
    }

    printf("Comparacoes: %d\n",comparacoes);
    printf("Trocas: %d\n",trocas);
}

// =====================================================
// QUESTÃO 10 – Selection Sort com ordem
// =====================================================

void selectionSortOrdem(int v[], int n, int ordem){

    int pos,temp;

    for(int i=0;i<n-1;i++){

        pos=i;

        for(int j=i+1;j<n;j++){

            if((ordem==1 && v[j]<v[pos]) ||
               (ordem==-1 && v[j]>v[pos])){
                pos=j;
            }
        }

        temp=v[i];
        v[i]=v[pos];
        v[pos]=temp;
    }
}

// =====================================================
// QUESTÃO 11 – Insertion Sort
// =====================================================

void insertionSort(int v[], int n){

    int chave,j;

    for(int i=1;i<n;i++){

        chave=v[i];
        j=i;

        while(j>0 && chave<v[j-1]){

            v[j]=v[j-1];
            j--;
        }

        v[j]=chave;
    }
}

// =====================================================
// QUESTÃO 13 – Insertion Sort instrumentado
// =====================================================

void insertionSortInstrumentado(int v[], int n){

    int comparacoes=0;
    int movimentacoes=0;
    int chave,j;

    for(int i=1;i<n;i++){

        chave=v[i];
        j=i;

        while(j>0){

            comparacoes++;

            if(chave<v[j-1]){

                v[j]=v[j-1];
                movimentacoes++;
                j--;

            }else break;
        }

        v[j]=chave;
        movimentacoes++;
    }

    printf("Comparacoes: %d\n",comparacoes);
    printf("Movimentacoes: %d\n",movimentacoes);
}


int main(){

    int ordenado[N];
    int reverso[N];
    int aleatorio[N];

    srand(time(NULL));

    for(int i=0;i<N;i++){
        ordenado[i]=i+1;
        reverso[i]=N-i;
        aleatorio[i]=rand()%100;
    }

    int v[N];

    printf("\nQUESTAO 1 - Bubble Sort\n");
    copiarVetor(aleatorio,v,N);
    bubbleSort(v,N);
    imprimirVetor(v,N);


    printf("\nQUESTAO 2 - Bubble Sort Instrumentado\n");
    copiarVetor(aleatorio,v,N);
    bubbleSortInstrumentado(v,N);


    printf("\nQUESTAO 3 - Bubble Sort Early Stop\n");
    copiarVetor(aleatorio,v,N);
    bubbleSortOptimizado(v,N);
    imprimirVetor(v,N);


    printf("\nQUESTAO 4 - Comparacao experimental\n");
    printf("O caso que mais reduz operacoes com early stop é o vetor ja ordenado.\n");
    printf("Pois nenhuma troca ocorre e o algoritmo encerra apos a primeira passada.\n");


    printf("\nQUESTAO 5 - Bubble Sort com ordem\n");
    copiarVetor(aleatorio,v,N);
    bubbleSortOrdem(v,N,1);
    printf("Crescente: ");
    imprimirVetor(v,N);

    copiarVetor(aleatorio,v,N);
    bubbleSortOrdem(v,N,-1);
    printf("Decrescente: ");
    imprimirVetor(v,N);


    printf("\nQUESTAO 6 - Selection Sort\n");
    copiarVetor(aleatorio,v,N);
    selectionSort(v,N);
    imprimirVetor(v,N);


    printf("\nQUESTAO 7 - Tracado Selection Sort\n");
    printf("Vetor inicial: [64 25 12 22 11]\n");
    printf("i=0 -> [11 25 12 22 64]\n");
    printf("i=1 -> [11 12 25 22 64]\n");
    printf("i=2 -> [11 12 22 25 64]\n");
    printf("i=3 -> [11 12 22 25 64]\n");


    printf("\nQUESTAO 8 - Selection Sort Instrumentado\n");
    copiarVetor(aleatorio,v,N);
    selectionSortInstrumentado(v,N);


    printf("\nQUESTAO 9 - Ordem inicial influencia?\n");
    printf("Nao influencia muito o numero de comparacoes porque o Selection Sort\n");
    printf("sempre percorre todos os elementos restantes procurando o menor.\n");


    printf("\nQUESTAO 10 - Selection Sort com ordem\n");
    copiarVetor(aleatorio,v,N);
    selectionSortOrdem(v,N,-1);
    imprimirVetor(v,N);


    printf("\nQUESTAO 11 - Insertion Sort\n");
    copiarVetor(aleatorio,v,N);
    insertionSort(v,N);
    imprimirVetor(v,N);


    printf("\nQUESTAO 12 - Tracado Insertion Sort\n");
    printf("Vetor inicial: [5 3 4 1 2]\n");
    printf("i=1 -> [3 5 4 1 2]\n");
    printf("i=2 -> [3 4 5 1 2]\n");
    printf("i=3 -> [1 3 4 5 2]\n");
    printf("i=4 -> [1 2 3 4 5]\n");


    printf("\nQUESTAO 13 - Insertion Sort Instrumentado\n");
    copiarVetor(aleatorio,v,N);
    insertionSortInstrumentado(v,N);

    return 0;
}