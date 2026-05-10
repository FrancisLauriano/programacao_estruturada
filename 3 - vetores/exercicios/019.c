#include <stdio.h>

#define TAM 50

void preencher(int v[], int t);
void imprimir(int v[], int t);

int main(){
    int vetor[TAM];

    preencher(vetor, TAM);
    imprimir(vetor, TAM);

    return 0;
}


void preencher(int v[], int t){
    int i, num;

    for(i = 0; i < t; i +=1 ){
        num = (i + (5*i)) % (i + 1);
        v[i] = num;
    }
}


void imprimir(int v[], int t){
    int i;

    for(i = 0; i < t; i +=1 ){
        printf("%d\n", v[i]);
    }
    printf("\n");
}
