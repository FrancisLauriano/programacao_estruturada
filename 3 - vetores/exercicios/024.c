#include <stdio.h>

#define TAM 5

void receber(int v1[], double v2[], int t);

void verificarAlturas(int v1[], double v2[], int t);


int main(){
    int numero[TAM];
    double altura[TAM];

    receber(numero, altura, TAM);
    verificarAlturas(numero, altura, TAM);

    return 0;
}


void receber(int v1[], double v2[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digite num %dº aluno:\n", i+1);
        scanf("%d", &v1[i]);
        printf("Digite altura %dº aluno:\n", i+1);
        scanf("%lf", &v2[i]);
    }
}

void verificarAlturas(int v1[], double v2[], int t){
    int i;
    int menor = 0;
    int maior = 0;
    

    for(i = 0; i < t; i += 1){
        if(v2[i] < v2[menor]){
            menor = i;
        }

        if(v2[i] > v2[maior]){
            maior = i;
        }
    }

    printf("Aluno mais alto:\nNum: %d\nAltura: %.2lf\n", v1[maior], v2[maior]);
    printf("Aluno mais alto:\nNum: %d\nAltura: %.2lf\n", v1[menor], v2[menor]);
    
   
}

