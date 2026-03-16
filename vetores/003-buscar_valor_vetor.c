#include <stdio.h>

int buscaSequencial(int v[], int tam, int valor){

    int i;

    for(i = 0; i < tam; i += 1){
        if(v[i] == valor){
            return v[i];
        }
    }
    return -1;
}

