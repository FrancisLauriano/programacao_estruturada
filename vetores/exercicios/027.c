#include <stdio.h>

#define TAM 5

void receber(int v[], int t);
void numPrimois(int v[], int t);


int main(){
    int vetor[TAM];

    receber(vetor, TAM);
    numPrimois(vetor, TAM);

    return 0;
}


void receber(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digite %dº valor:\n", i+1);
        scanf("%d", &v[i]);
    }
}


void numPrimois(int v[], int t){
    int i, j;
    int qtd_divisores;
    int qtd_primos = 0;

    for(i = 0; i < t; i += 1){
        qtd_divisores = 0;

        for(j = 1; j <= v[i]; j += 1){
            if(v[i] % j == 0){
                qtd_divisores += 1;
            }
        }

        if(qtd_divisores == 2){
            printf("Numero: %d\n", v[i]);
            printf("Posicao: %d\n", i);
            qtd_primos += 1;
        }
    }

    if(qtd_primos == 0){
        printf("Nenhum primo encontrado\n");
    }
}