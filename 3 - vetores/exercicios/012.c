#include <stdio.h>

#define TAM 5

void receber(int v[], int t);
int maiorV(int v[], int t);
int menorV(int v[], int t);
double mediaV(int ma, int me);

int main(){
    int vetor[TAM];
    int maior, menor;
    double media;

    receber(vetor, TAM);

    maior = maiorV(vetor, TAM);
    menor = menorV(vetor, TAM);
    media = mediaV(maior, menor);

    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    printf("Media: %.2lf\n", media);


    return 0;
}


void receber(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digite %dº valor:\n", i+1);
        scanf("%d", &v[i]);
    }
}

int maiorV(int v[], int t){
    int i;
    int maior = 0;

    for(i = 0; i < t; i += 1){
        if(v[i] > v[maior]){
            maior = i;
        }
    }
    return v[maior];
}

int menorV(int v[], int t){
    int i;
    int menor = 0;

    for(i = 0; i < t; i += 1){
        if(v[i] < v[menor]){
            menor = i;
        }
    }
    return v[menor];
}


double mediaV(int ma, int me){
    return (ma + me)/2;
}
