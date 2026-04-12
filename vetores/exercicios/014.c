#include <stdio.h>



void bubbleSort(int v[], int t){
    int i, aux;
    int troca = 1;

    while(troca){
        troca = 0;

        for(i = 0; i < t - 1; i += 1){

            if(v[i] > v[i + 1]){
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                troca = 1;
            }
        }
        t -= 1;
    }
}

void qtdRepeticao(int v[], int t){
    int i, j, qtd;
    int tem_repeticao = 0;

    for(i = 0; i < t; i += 1){

        if(i > 0 && v[i] == v[i - 1]){
            continue;
        }


        for(j = i + 1; j < t; j += 1){
            if(v[i] == v[j]){
                printf("%d\n", v[i]);
                tem_repeticao = 1;
                break;
                
            }
        }
    }

    if(tem_repeticao == 0){
        printf("Sem repeticoes\n");

    }
}