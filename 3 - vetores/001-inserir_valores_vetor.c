#include <stdio.h>

void inserirValores(int v[], int tam){

    int i;
    for(i = 0; i < tam; i += 1){

        printf("%dº Valor:\n", i +1);
        scanf("%d", &v[i]);
    }
}