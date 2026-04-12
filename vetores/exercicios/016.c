#include <stdio.h>

#define TAM 5

void receber(double v[], int t);
void imprimir(double v[], int t);
void imprimirInverso(double v[], int t);

int main(){
    double vetor[TAM];
    int opcao = 1;
    

    receber(vetor, TAM);
    

    do{
        printf("Informe opcao:\n0. Encerrar\n1.Imprimir vetor\n2. Vetor inverso\n");
        scanf("%d", &opcao);

        if(opcao == 0){
            printf("Encerrar");
            break;
        }else if(opcao == 1){
            imprimir(vetor, TAM);
            continue;
        }else if(opcao == 2){
            imprimirInverso(vetor, TAM);
            continue;
        }else{
            printf("Codigo invalido\n");
            continue;
        }

    }while(opcao != 0);


    return 0;
}


void receber(double v[], int t){
    int i;

    for(i = 0; i < t; i +=1 ){
        printf("%d° valors:\n", i+1);
        scanf("%lf", &v[i]);
    }
}

void imprimir(double v[], int t){
    int i;

    for(i = 0; i < t; i +=1 ){
        printf("%.2lf ", v[i]);
    }
    printf("\n");

}

void imprimirInverso(double v[], int t){
    int i;

    for(i = t - 1; i >= 0; i-= 1){
        printf("%.2lf ", v[i]);
    }
    printf("\n");

}