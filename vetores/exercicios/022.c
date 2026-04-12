#include <stdio.h>

#define TAM 5

void receber(int v[], int t);
void novoVetor(int v1[], int v2[], int v3[], int t);
void imprimir(int v[], int t);

int main(){
    int tam2 = TAM *2;
    int vetor1[TAM];
    int vetor2[TAM];
    int vetor3[tam2];

    printf("=== VETOR 1 ===\n");
    receber(vetor1, TAM);

    printf("=== VETOR 2 ===\n");
    receber(vetor2, TAM);
    
    novoVetor(vetor1, vetor2, vetor3, tam2);
    

    printf("Vetor completo:\n");
    imprimir(vetor3, tam2);


    return 0;
}



void receber(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digite %dº valor:\n", i+1);
        scanf("%d", &v[i]);
    }
}

void novoVetor(int v1[], int v2[], int v3[], int t){
    int j;
    int i = 0;

    for(j = 0; j < t; j += 2){
        v3[j] = v1[i];
        i += 1;
    }

    i = 0;
    for(j = 1; j < t; j += 2){
        v3[j] = v2[i];
        i += 1;
    }

}


void imprimir(int v[], int t){
    int i;

    for(i = 0; i < t; i +=1 ){
        printf("%d\t", v[i]);
    }
    printf("\n");
}