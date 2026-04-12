#include <stdio.h>

#define TAM 5

void receber(int v[], int t);
int verificar(int v1[], int v2[], int t);
void imprimir(int v[], int t);

int main(){
    int vetor1[TAM];
    int vetor2[TAM];
    int tam2;

    receber(vetor1, TAM);
    tam2 = verificar(vetor1, vetor2, TAM);

    printf("Vetor completo:\n");
    imprimir(vetor1, TAM);

    printf("Vetor impares:\n");
    imprimir(vetor2, tam2);

    return 0;
}


void receber(int v[], int t){
    int i = 0;
    int valor;


    do{
        printf("%d° valor[0-5]:\n", i+1);
        scanf("%d", &valor);

        if(valor < 0 || valor > 50){
            printf("Valor invalido\n");
            continue;
        }else{
            v[i] = valor;
            i += 1; 
        }

    }while(i < t);
}

int verificar(int v1[], int v2[], int t){
    int i;
    int j = 0;

    for(i = 0; i < t; i +=1 ){
        if(v1[i] % 2 != 0){
            v2[j] = v1[i];
            j += 1;
        }

    }
    return j;
}


void imprimir(int v[], int t){
    int i;

    for(i = 0; i < t; i +=1 ){
        printf("%d ", v[i]);

        if((i + 1) % 2 == 0){
            printf("\n");

        }
    }
    printf("\n");
}
