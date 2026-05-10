#include <stdio.h>

#define TAM 5

void receber(int v[], int t);
void parImpar(int v1[], int v2[], int v3[],int t);


int main(){
    int vetor1[TAM];
    int vetor2[TAM];
    int vetor3[TAM];

    receber(vetor1, TAM);
    parImpar(vetor1, vetor2, vetor3, TAM);


    return 0;
}


void receber(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digite %dº valor:\n", i+1);
        scanf("%d", &v[i]);
    }
}


void parImpar(int v1[], int v2[], int v3[],int t){
    int i;
    int j = 0;
    int l = 0;

    for(i = 0; i < t; i += 1){
        if(v1[i] % 2 != 0){
            v2[j] = v1[i];
            j += 1;
        }else{
            v3[l] = v1[i];
            l += 1;
        }
    }

    printf("Elementos utilizados no V1: %d\n", j);
    printf("Elementos utilizados no V2: %d\n", l);
}