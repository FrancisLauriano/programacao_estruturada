#include <stdio.h>

int main(){
    int soma = 0;
    int num1, num2, maior, menor, i;

    printf("Digite 1º numero:\n");
    scanf("%d", &num1);

    printf("Digite 2º numero:\n");
    scanf("%d", &num2);

    if(num1 >= num2){
        maior = num1;
        menor = num2;
    }else{
        maior = num2;
        menor = num1;
    }

    for(i = menor; maior >= i; i += 1){
        soma += i;
    }

    printf("Soma: %d\n", soma);

    return 0;
}