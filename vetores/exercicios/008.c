#include <stdio.h>

#define TAM 6

void receber(int v[], int t);
void imprimir(int v[], int t);
void imprimirInvserso(int v[], int t);


int main(){
    int vetor[TAM];

    receber(vetor, TAM);

    printf("Vetor na ordem da digitacao:\n");
    imprimir(vetor, TAM);

    printf("Vetor na ordem invertuda:\n");
    imprimirInvserso(vetor, TAM);


    return 0;
}


void receber(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digite o %d° valor:\n", i + 1);
        scanf("%d", &v[i]);
    }
}


void imprimir(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("%d ", v[i]);
    }
    printf("\n");

}

void imprimirInvserso(int v[], int t){
    int i;

    for(i = t -1; i >= 0; i -= 1){
        printf("%d ", v[i]);
    }
    printf("\n");

}