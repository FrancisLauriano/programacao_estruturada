#include <stdio.h>

#define TAM 10

void inserir(int v[], int t);
void menorMaior(int v[], int t);
void imprimir(int v[], int t);

int main(){
    int vetor[TAM];

    inserir(vetor, TAM);
    printf("Vetor:\n");
    imprimir(vetor, TAM);
    menorMaior(vetor, TAM);


    return 0;
}


void inserir(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Inserir %d° valor:\n", i + 1);
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

void menorMaior(int v[], int t){
    int i, menor, maior;

    menor = 0;
    maior = 0;

    for(i = 0; i < t; i += 1){
        if(v[i] < v[menor]){
            menor = i;
        }

        if(v[i] > v[maior]){
            maior = i;
        }
    }

    printf("Maior: %d\nMenor: %d", v[maior], v[menor]);
}