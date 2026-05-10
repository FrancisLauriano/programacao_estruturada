#include <stdio.h>

#define IDADE_MINIMA 0
#define IDADE_MAXIMA 130

void inserirNumeros(int nums[], int tam, int min, int max);
double calcularMedia(int nums[], int tam);
void maiorIgualMedia(int nums[], int tam, double media);


int main(){
    int tamanho;
    double media;

    printf("Inserir quantas idades?\n");
    scanf("%d", &tamanho);

    int idades[tamanho];

    inserirNumeros(idades, tamanho, IDADE_MINIMA, IDADE_MAXIMA);

    media = calcularMedia(idades, tamanho);
    printf("Media: %.2lf\n", media); 

    printf("Idades maiores e iguais a média:\n");
    maiorIgualMedia(idades, tamanho, media);

    return 0;
}


void inserirNumeros(int nums[], int tam, int min, int max){
    int i;

    for(i = 0; tam > i; i += 1){
        do{
            printf("%d° idade:\n", i + 1);
            scanf("%d", &nums[i]);
        }while(nums[i] < min || nums[i] > max);
    }
}

double calcularMedia(int nums[], int tam){
    int i;
    int soma = 0;

    for(i = 0; tam > i; i += 1){
        soma += nums[i];
    }
    
    return soma / tam;
}

void maiorIgualMedia(int nums[], int tam, double media){
    int i;

    for(i = 0; tam > i; i += 1){
        if(nums[i] >= media){
            printf("%d  ", nums[i]);
        }
    }
    printf("\n");
}