#include <stdio.h>

void inseriNumero(int nums[], int tam);
int somaNumeros(int nums[], int tam);

int main(){
    int num1, num2, tamanho, soma;

    printf("Quantos numeros?\n");
    scanf("%d", &tamanho);

    int numeros[tamanho];

    inseriNumero(numeros, tamanho);
    soma = somaNumeros(numeros, tamanho);

    printf("Soma é: %d\n", soma);

    return 0;
}

int somaNumeros(int nums[], int tam){
    int soma = 0;
    int i;

    for(i = 0; tam > i; i += 1){
        soma += nums[i];
    }
    return soma;
}

void inseriNumero(int nums[], int tam){
    int i;

    for(i = 0; tam > i; i += 1){
        printf("Digite %d° número:\n", i+1);
        scanf("%d", &nums[i]);
    }

}