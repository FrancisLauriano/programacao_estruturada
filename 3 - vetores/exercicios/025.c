#include <stdio.h>

#define TAM 100

int multiploSete(int v1[], int t);
void imprimir(int v[], int t);

int main(){
    int vetor[TAM];
    int tamanho;

    tamanho = multiploSete(vetor, TAM);

    imprimir(vetor, tamanho);

    return 0;
}




int multiploSete(int v1[], int t){
    int i  = 0;
    int j = 0;
    int ultimo;

   
    while(j < 100){

        ultimo = i % 10;

        if(i % 7 == 0 && ultimo != 7){
            v1[j] = i;
            j += 1;
        }

        i += 7;
    }
    return j;
}

void imprimir(int v[], int t){
    int i;

    for(i = 0; i < t; i +=1 ){
        printf("%d\t", v[i]);
    }
    printf("\n");
}