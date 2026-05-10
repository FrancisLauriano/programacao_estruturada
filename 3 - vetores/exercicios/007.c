#include <stdio.h>

#define TAM 10

void receber(int v[], int t);
void imprimir(int v[], int t);
void menor(int v[], int t);


int main(){
    int vetor[TAM];

    receber(vetor, TAM);

    printf("Vetor:\n");
    imprimir(vetor, TAM);
    menor(vetor, TAM);

    return 0;
}

void receber(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digite %dº valor:\n", i + 1);
        scanf("%d", &v[i]);
    }
}

void imprimir(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("%d ", &v[i]);
    }
    printf("\n");

}

void menor(int v[], int t){
    int i, menor;
    menor = 0;

    for(i = 0; i < t; i += 1){
        if(v[i] < menor){
            menor = i;
        }
    }

    printf("Menor valor é %d e está na posicao %d\n", v[menor], menor);

}