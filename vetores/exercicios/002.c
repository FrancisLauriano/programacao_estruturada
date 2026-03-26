#include <stdio.h>
#define TAMANHO 6

void inserir(int v[], int tam);
void imprimir(int v[], int tam);

int main(){
    int vetor[TAMANHO];

    inserir(vetor, TAMANHO);
    imprimir(vetor, TAMANHO);

    return 0;
}

void inserir(int v[], int tam){
    int i;

    for(i = 0; i < tam; i += 1){
        printf("Insirir o %d° valor:\n", i + 1);
        scanf("%d", &v[i]);
    }
}

void imprimir(int v[], int tam){
    int i;

    for(i = 0; i < tam; i += 1){
        printf("%d\t", v[i]);
    }
    printf("\n");
}