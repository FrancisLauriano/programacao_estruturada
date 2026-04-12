#include <stdio.h>

#define TAM 5

void receber(int v[], int t);
void novoVetor(int v1[], int v2[], int v3[], int t);
void imprimir(int v[], int t);


int main(){
    int vetor1[TAM];
    int vetor2[TAM];
    int vetor3[TAM];
   

    printf("=== VETOR 1 ===\n");
    receber(vetor1, TAM);

    printf("=== VETOR 2 ===\n");
    receber(vetor2, TAM);
    
    novoVetor(vetor1, vetor2, vetor3, TAM);
    
    printf("Produto:\n");
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

void novoVetor(int v1[], int v2[], int v3[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        v3[i] = v1[i] * v2[i];
    }
}


void imprimir(int v[], int t){
    int i;

    for(i = 0; i < t; i +=1 ){
        printf("%d\t", v[i]);
    }
    printf("\n");
}