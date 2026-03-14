#include <stdio.h>

#define TAMANHO 3

int main(){
    int vetor[TAMANHO];
    

    return 0;
}

int buscaSquencial(int v[], int tam, int valor){
    int i;

    for(i = 0; i < tam; i += 1){
        if(v[i] == valor){
            return i;
        }
    }

    return -1;
}