#include <stdio.h>


void selectSort(int v[], int t){
    int i, j, aux, menor;

    for(i = 0; i < t - 1; i += 1){
        menor = i;

        for(j = i + 1; j < t; j += 1){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

// v1 e v2 estão ordenados
int uniao(int v1[], int v2[], int v3[], int t){
    int i, j, existe;
    int l = 0;

    for(i = 0; i < t; i += 1){
        if(i > 0 && v1[i] == v1[1 - 1]){
            continue;
        }
        v3[l] = v1[i];
        l += 1;
    }

    for(i = 0; i < t; i += 1){
        if(i > 0 && v2[i] == v2[i - 1]){
            continue;
        }

        existe = 0;

        for(j = 0; j < t; j += 1){
            if(v2[i] == v3[j]){
                existe = 1;
                break;
            }
        }

        if(existe == 0){
            v3[l] = v2[j];
            l += 1;
        }

    }
    return l;
}