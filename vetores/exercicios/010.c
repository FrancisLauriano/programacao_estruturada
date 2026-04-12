#include <stdio.h>

#define TAM 3

void receber(double v[], int t);
void imprimir(double v[], int t);
double mediaTurma(double v[], int t);

int main(){
    double vetor[TAM];
    double media;

    receber(vetor, TAM);

    printf("Vetor:\n");
    imprimir(vetor, TAM);

    
    media = mediaTurma(vetor, TAM);
    printf("Media turma %.2lf:\n", media);

    return 0;
}


void receber(double v[], int t){
    int i;
    double nota;

    for(i = 0; i < t; i += 1){

        do{
            printf("Nota - %dº aluno [0.00 - 10.00]:\n", i + 1);
            scanf("%lf", &nota);
            if(nota < 0.00 || nota > 10.00){
                printf("Nota invalida.\n");
                continue;
            }else{
                v[i] = nota;
                break;

            }
        }while(nota < 0.00 || nota > 10.00);
    }
}

double mediaTurma(double v[], int t){
    int i;
    double soma = 0.00;

    for(i = 0; i < t; i += 1){
        soma += v[i];
    }
    return soma / t;
}


void imprimir(double v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("%.2lf\t", v[i]);
    }
    printf("\n");
}