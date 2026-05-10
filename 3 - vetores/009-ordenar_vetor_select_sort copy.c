#include <stdio.h>


void selectSort(int v[], int tam){
    int i, j, menor, aux;

    for(i = 0; i < tam; i += 1){
        menor = i;
        for(j = i + 1; j < tam; j += 1){

            if(v[j] < v[menor]){
                menor = j;
            }
        }

        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }

}