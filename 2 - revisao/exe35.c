#include <stdio.h>

int maiorNumero(int nums[], int tam);
int menorNumero(int nums[], int tam);
void inserirNumeros(int nums[], int tam);
double mediaNumeros(int nums[], int tam);

int main(){
    int tamanho, maior, menor;
    double media;

    printf("Quantos numeros?\n");
    scanf("%d", &tamanho);

    int numeros[tamanho];

    inserirNumeros(numeros, tamanho);

    maior = maiorNumero(numeros, tamanho);
    printf("Maior numero: %d\n", maior);
   
    menor = menorNumero(numeros, tamanho);
    printf("Menor numeros: %d\n", menor);

    media = mediaNumeros(numeros, tamanho);
    printf("Media dos numeros: %.2lf\n", media);
    return 0;
}

int maiorNumero(int nums[], int tam){
    int i;
    int maior = nums[0];

    for(i = 0; tam > i; i += 1){
        if(nums[i] > maior){
            maior = nums[i];
        }
    }
    return maior;
}

int menorNumero(int nums[], int tam){
    int i;
    int menor = nums[0];

    for(i = 0; tam > i; i += 1){
        if(nums[i] < menor){
            menor = nums[i];
        }
    }
    return menor;
}

double mediaNumeros(int nums[], int tam){
    int soma = 0;
    int i;

    for(i = 0; tam > i; i += 1){
        soma += nums[i];
    }

    return soma / tam;
}

void inserirNumeros(int nums[], int tam){
    int i;

    for(i = 0; tam > i; i += 1){
        printf("Digite o %d° número:\n", i + 1);
        scanf("%d", &nums[i]);
    }
}