#include <stdio.h>

int main(){
    int num, i;
    int soma = 0;

    printf("Numero:\n");
    scanf("%d", &num);

    for(i = 1; num > i; i += 1){
        if(num % i == 0){
            soma += i;
        }
    }

    if(soma == num){
        printf("%d é um número perfeito\nSoma: %d", num, soma);

    }else{
        printf("%d não é um número perfeito\nSoma: %d", num, soma);
    }

    return 0;
}