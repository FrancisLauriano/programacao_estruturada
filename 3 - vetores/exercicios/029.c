#include <stdio.h>

#define TAM 5

void receber(int v[], int t);
void parImpar(int v[], int t);


int main(){
    int vetor[TAM];


    receber(vetor, TAM);
    parImpar(vetor, TAM);


    return 0;
}


void receber(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digite %dº valor:\n", i+1);
        scanf("%d", &v[i]);
    }
}


void parImpar(int v[], int t){
    int i = 0;
    int somaPares = 0;
    int qtdImpares = 0;

    printf("\nNumeros pares:\n");
    for(i = 0; i < t; i += 1){
        if(v[i] % 2 == 0){
            printf("%d\n", v[i]);
            somaPares += v[i];
        }
    }

    printf("\n");
    
    printf("\nNumeros impares:\n");
    for(i = 0; i < t; i += 1){
        if(v[i] % 2 != 0){
            printf("%d\n", v[i]);
            qtdImpares += 1;
        }
    }

    printf("\n");
    printf("Soma pares: %d\n", somaPares);
    printf("Qtd impares: %d\n", qtdImpares);
   
}