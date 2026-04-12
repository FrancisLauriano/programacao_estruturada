#include <stdio.h>

#define TAM 5

void receber(int v[], int t);
void maiorMenor(int v[], int t);

int main(){
    int vetor[TAM];

    receber(vetor, TAM);
    maiorMenor(vetor, TAM);

    return 0;
}

void receber(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digite %dº valor:\n", i+1);
        scanf("%d", &v[i]);
    }
}

void maiorMenor(int v[], int t){
    int i;
    int maior = 0;
    int menor = 0;

    for(i = 0; i < t; i += 1){
        if(v[i] > v[maior]){
            maior = i;
        }
        
        if(v[i] < v[menor]){
            menor = i;
        }
    }
    printf("Maior: %d\nMenor: %d", v[maior], v[menor]);
}

