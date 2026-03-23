#include <stdio.h>

void bubbleSort(int v[], int tam){
    int i, j, aux;
    int troca = 1;

    while(troca){
        troca = 0;
        for(j = 0; j < tam - 1; j += 1){
            if(v[j] > v[j + 1]){
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                troca = 1;
            }
        }
        tam -= 1;
    }
}