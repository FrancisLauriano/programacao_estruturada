#include <stdio.h>

int deletarValor(int v[], int tam, int valor){
    int i, j;


    for(i = 0; i < tam; i += 1){
        if(v[i] == valor){
            
            for(j = i; j < tam - 1; i += 1){
                v[j] = v[j + 1];
            }
            tam -= 1;
        }
    }
    return tam;

}