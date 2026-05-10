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

int interSeccao(int v1[], int v2[], int v3[], int t){
    int i, j;
    int l = 0;

    for(i = 0; i < t; i += 1){
        if(i > 0 && v1[i] == v1[i - 1]){
            continue;
        }

        for(j = 0; j < t; j += 1){
            if(v1[i] == v2[j]){
                v3[l] = v1[i];
                l += 1;
                break;
            }

        }
    }

    return l;

}