#include <stdio.h>

#define TAMANHO 3

int main(){
    int vetor[TAMANHO];
    

    return 0;
}

int atualizarValor(int v[], int tam, int valor, int novo_valor){
    int i;

    for(i = 0; i < tam; i += 1){
        if(v[i] == valor){
            v[i] = novo_valor;
            return 1;
        }
    }
    return -1;

}