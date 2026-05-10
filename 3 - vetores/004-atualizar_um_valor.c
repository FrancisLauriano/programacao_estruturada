#include <stdio.h>


int atualizarValor(int v[], int tam, int valor, int novo_valor){
    int i;

    for(i = 0; i < tam; i += 1){
        if(v[i] == valor){
            v[i] = novo_valor;
            return v[i];
        }else{
            return -1;
        }
    }

}