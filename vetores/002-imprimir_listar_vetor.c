#include <stdio.h>

void imprimirValores(int v[], int tam){
    int i;

    for(i = 0; i < tam; i += 1){
        printf("%d\t", v[i]);
    }
    printf("\n");
}