#include <stdio.h>

#define TAM 8

void receber(int v[], int t);
void pares(int v[], int t);

int main(){
    int vetor[TAM];

    receber(vetor, TAM);

    printf("Numeros pares:\n");
    pares(vetor, TAM);

    return 0;
}



void receber(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digitar %d° valor:\n", i + 1);
        scanf("%d", &v[i]);
    }
}

void pares(int v[], int t){
    int i;
    int qtd = 0;

    for(i = 0; i < t; i += 1){
        if(v[i] % 2 == 0){
            printf("%d ", v[i]);
            qtd += v[i];
        }
    }

    printf("\nQuantidade de pares: %d\n", qtd);
}