#include <stdio.h>

#define TAM 5

void receber(int v[], int t);
void devioPadrao(int v[], int t);


int main(){
    int vetor[TAM];

    receber(vetor, TAM);
    devioPadrao(vetor, TAM);

    
    
    return 0;
}


void receber(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digite %dº valor:\n", i+1);
        scanf("%d", &v[i]);
    }
}

void devioPadrao(int v[], int t){
    int i;
    double media, desvio_sem_raiz, desvio;
    int soma = 0;
    double soma_quadrados = 0.00;

    for(i = 0; i < t; i += 1){
        soma += v[i];
    }

    media = soma / t;

    for(i = 0; i < t; i += 1){
        soma_quadrados += ((v[i] - media) * (v[i] - media));
    }

    desvio_sem_raiz = soma_quadrados / (t - 1);
    
    desvio = desvio_sem_raiz;

    for(i = 0; i < 20; i += 1){
        desvio = ((desvio + desvio_sem_raiz) / desvio) / 2;

    }

    printf("Media: %.2lf\n", media);
    printf("Devio Padrao: %.5lf\n", desvio);

}
    


