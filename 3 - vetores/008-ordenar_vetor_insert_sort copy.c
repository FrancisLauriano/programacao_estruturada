#include <stdio.h>

#define TAMANHO 5

void digitarValores(int v[], int tam);
void insertSort(int v[], int tam);
void imprimir(int v[], int tam);


int main(){
    int vetor[TAMANHO];
    digitarValores(vetor, TAMANHO);

    printf("Antes da Ordenação:\n");
    imprimir(vetor, TAMANHO);

    insertSort(vetor, TAMANHO);
    
    printf("Apos Ordenação:\n");
    imprimir(vetor, TAMANHO);

    return 0;
}

void digitarValores(int v[], int tam){
    int i;

    for(i = 0; i < tam; i += 1){
        printf("%d° Numero:\n", i + 1);
        scanf("%d", &v[i]);
    }
}

void imprimir(int v[], int tam){
    int i;

    for(i = 0; i < tam; i += 1){
        printf("%d\t", v[i]);
    }
    printf("\n");

}






void insertSort(int v[], int tam){
    int i;

    for(i = 1; i < tam; i += 1){
        int aux;
        int j = i;
        aux = v[j];

        while(j > 0 && aux < v[j - 1]){
            v[j] = v[j - 1];
            j -= 1;
        }
        v[j] = aux;
    }
}

