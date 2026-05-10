#include <stdio.h>

#define TAM 5

void receber(int v[], int t);
void subtracao(int v[], int v1[], int v2[], int t);
void imprimir(int v[], int t);

int main(){
    int vetor[TAM];
    int vetor2[TAM];
    int vetor3[TAM];

    printf("=== VETOR 1 ===\n");
    receber(vetor, TAM);

    printf("=== VETOR 2 ===\n");
    receber(vetor2, TAM);
    
    subtracao(vetor, vetor2, vetor3, TAM);

    printf("Vetor completo:\n");
    imprimir(vetor3, TAM);


    return 0;
}



void receber(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digite %dº valor:\n", i+1);
        scanf("%d", &v[i]);
    }
}

void subtracao(int v[], int v1[], int v2[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        v2[i] = v[i] - v1[i];
    }
}


void imprimir(int v[], int t){
    int i;

    for(i = 0; i < t; i +=1 ){
        printf("%d ", v[i]);
    }
    printf("\n");
}