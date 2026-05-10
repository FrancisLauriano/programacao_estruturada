#include <stdio.h>

#define TAM 5

void receber(double v[], int t);
int qtdNegativos(double v[], int t);
double somaPositivos(double v[], int t);
void imprimir(double v[], int t);

int main(){
    double vetor[TAM];
    int qtd;
    double soma;

    receber(vetor, TAM);

    printf("Vetor:\n");
    imprimir(vetor, TAM);

    qtd = qtdNegativos(vetor, TAM);
    printf("Qtd negativos: %d\n", qtd);

    soma = somaPositivos(vetor, TAM);
    printf("Soma Positivos: %.2lf\n", soma);
    
    return 0;
}

void receber(double v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digite %dº valor:\n", i+1);
        scanf("%lf", &v[i]);
    }
}

int qtdNegativos(double v[], int t){
    int i;
    int qtd = 0;

    for(i = 0; i < t; i += 1){
        if(v[i] < 0){
            qtd +=1;
        }
    }

    return qtd;
}

double somaPositivos(double v[], int t){
    int i;
    double soma = 0.00;

    for(i = 0; i < t; i += 1){
        if(v[i] > 0.00){
            soma += v[i];
        } 
    }
    return soma;
}


void imprimir(double v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("%.2lf\t", v[i]);
    }
    printf("\n");
}