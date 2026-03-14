#include <stdio.h>

#define TAMANHO 3

void imprimirValores(int v[], int tam);

int main(){
    int vetor[TAMANHO];

    imprimirValores(vetor, TAMANHO);

    return 0;
}


void imprimirValores(int v[], int tam){
    int i;

    for(i = 0; i < tam; i += 1){
        printf("%d\t", v[i]);

    }

    printf("\n");
}