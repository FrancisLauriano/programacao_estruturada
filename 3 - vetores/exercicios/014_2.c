#include <stdio.h>

#define TAM 5

void receber(int v[], int t);





int main(){
    int vetor[TAM];

   

    return 0;
}

void receber(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digite %dº valor:\n", i+1);
        scanf("%d", &v[i]);
    }
}

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

void selectSort(int v[], int t){
    int i, j, aux, menor;

    for(i = 0; i < t; i += 1){
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

void valoresIguais(int v[], int t){
    int i, j;
    int repeticao;
    int encontrado = 0;

    for(i = 0; i < t; i += 1){
        repeticao = 0;

        if(i > 0 && v[i] == v[i - 1]){
            continue;
        }

        for(j = i + 1; j < t; j += 1){
            if(v[i] == v[j]){
                repeticao = 1;
                break;
            }
        }

        if(repeticao > 0){
            printf("%d ", v[i]);
            encontrado = 1;
        }
    }

    if(encontrado != 0){
        printf("Nenhum valor repetio encontrado.\n");
    }



}

