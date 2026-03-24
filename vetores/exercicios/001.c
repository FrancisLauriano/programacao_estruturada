#include <stdio.h>
#define TAM 6

void somatorio(int v[], int tam);
void atualizar(int v[], int tam);
void imprimir(int v[], int tam);


int main(){

    int A[TAM]= {1, 0, 5, -2, -5, 7};

    printf("Imprimir antes:\n");
    imprimir(A, TAM);

    somatorio(A, TAM);

    atualizar(A, TAM);

    printf("Imprimir apos:\n");
    imprimir(A, TAM);

    return 0;
}


void somatorio(int v[], int tam){
    int i;
    int soma = 0;

    for(i = 0; i < tam; i += 1){
        if(i == 0 || i == 1 || i == 5){
            soma += v[i];

        }
    }

    printf("Soma: %d", soma);
}

void atualizar(int v[], int tam){
    int i;
    int pos = 4;
    int valor;

    printf("Inserir novo valor na posicao 4:\n");
    scanf("%d", &valor);

    v[pos] = valor;

}


void imprimir(int v[], int tam){
    int i;

    for(i = 0; i < tam; i += 1){
        printf("%d\t", &v[i]);
    }

    printf("\n");

}