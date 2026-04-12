#include <stdio.h>

void insertSort(int v[], int tam){
    int i, j, aux;

    for(i = 1; i < tam; i += 1){
        j = i;
        aux = v[j];

        while(j > 0 && aux < v[j - 1]){
            v[j] = v[j - 1];
            j -= 1;

        }
        v[j] = aux;

    }

}