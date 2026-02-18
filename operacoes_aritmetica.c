#include <stdio.h>

int main(){
    int num1, num2, soma, subtracao, multi, divisao;

    printf("Digite o primeiro valor:\n");
    scanf("%d", &num1);

    printf("Digite o segundo valor:\n");
    scanf("%d", &num2);

    soma = num1 + num2;
    subtracao = num1 - num2;
    multi = num1 * num2;
    divisao = num1 / num2;

    printf("Resultados:\n");
    printf("Soma: %d\n", soma);
    printf("Subtracao: %d\n", subtracao);
    printf("Multiplicacao: %d\n", multi);
    printf("Divisao: %d\n", divisao);

    return 0;
}