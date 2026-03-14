#include <stdio.h>
#define TAMANHO 3

void inserirValores(int v[], int tam);

int main(){
    int vetor[TAMANHO];

    inserirValores(vetor, TAMANHO);

    return 0;
}


void inserirValores(int v[], int tam){
    int i;

    for(i =0;  i < tam; i += 1){
        printf("%d° numero:\n", i + 1);
        scanf("%d", &v[i]);
    }
}