#include <stdio.h>
#define TAMANHO 3

void inserir(int v[], int tam);
void calcularQuadrado(int v[], int v_quadrado[], int tam);
void imprimir(int v[], int tam);


int main(){
    int vetor[TAMANHO];
    int vetor_quadrado[TAMANHO];

    inserir(vetor, TAMANHO);

    printf("Antes de calcular ao quadrado:\n");
    imprimir(vetor, TAMANHO);

    calcularQuadrado(vetor, vetor_quadrado, TAMANHO);

    printf("Apos de calcular ao quadrado:\n");
    imprimir(vetor_quadrado, TAMANHO);


    return 0;
}


void inserir(int v[], int tam){
    int i;

    for(i = 0; i < tam; i += 1){
        printf("Inserir %d° numero:\n", i + 1);
        scanf("%d", &v[i]);
    }
}


void calcularQuadrado(int v[], int v_quadrado[], int tam){
    int i, num_quadrado;

    for(i = 0; i < tam; i += 1){
        num_quadrado = v[i] * v[i];
        v_quadrado[i] = num_quadrado;
    }
}


void imprimir(int v[], int tam){
    int i;

    for(i = 0; i < tam; i += 1){
        printf("%d ", v[i]);
    }

    printf("\n");
}