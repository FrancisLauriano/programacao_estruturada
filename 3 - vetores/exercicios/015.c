#include <stdio.h>


void insertSort(int v[], int t){
    int i, j, aux;

    for(i = 1; i < t; i += 1){
        j = i;
        aux = v[j];

        while(j > 0 && aux < v[j - 1]){
            v[j] = v[j - 1];
            j -= 1;
        }

        v[j] = aux;

    }
}

int excluirRepeticao(int v[], int t){
    int i, j, l;

    for(i = 0; i < t; i += 1){

        for(j = i + 1; j < t; j += 1){
            
            if(v[i] == v[j]){

                for(l = j; l < t - 1; l += 1){
                    v[j] = v[j + 1];
                }
                t -= 1;
                j -= 1;

            }

        }
    }
    return t;

}