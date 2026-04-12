#include <stdio.h>

#define TAM 5

void receber(double v[], int t);
void mudar(double v[], int t);
void imprimir(double v[], int t);

int main(){
    double vetor[TAM];

    receber(vetor, TAM);
    mudar(vetor, TAM);
    imprimir(vetor, TAM);

    return 0;
}


void receber(double v[], int t){
    int i;

    for(i = 0; i < t; i +=1 ){
        printf("%d° valors:\n", i+1);
        scanf("%lf", &v[i]);
    }
}

void mudar(double v[], int t){
    int i;

    for(i = 0; i < t; i +=1 ){
        if(v[i] < 0){
            v[i] = 0;

        }
    }



}

void imprimir(double v[], int t){
    int i;

    for(i = 0; i < t; i +=1 ){
        printf("%.2lf ", v[i]);
    }
    printf("\n");
}