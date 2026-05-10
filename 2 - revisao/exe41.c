#include <stdio.h>

int numerosImpares(int nums[], int tam);
void inserirNumeros(int nums[], int tam);

int main(){
    int tamanho;
    int impares;

    printf("Quantos números?\n");
    scanf("%d", &tamanho);

    int numeros[tamanho];

    inserirNumeros(numeros, tamanho);

    impares = numerosImpares(numeros, tamanho);
    printf("Quantidade de números impares: %d\n", impares);

    return 0;
}

int numerosImpares(int nums[], int tam){
    int i;
    int qtd_impares = 0;

    for(i = 0; tam > i; i += 1){
        if(nums[i] % 2 != 0){
            qtd_impares += 1;
        }
    }
    return qtd_impares;
}

void inserirNumeros(int nums[], int tam){
    int i;

    for(i = 0; tam > i; i += 1){
        printf("%d° número:\n", i + 1);
        scanf("%d", &nums[i]);
    }

}