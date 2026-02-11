#include <stdio.h>

int main(){
    int idade;
    int anoNascimento;
    int anoAtual;

    printf("Informe o ano de seu nascimento: ");
    scanf("%d", &anoNascimento);

    printf("Informe o ano atual: ");
    scanf("%d", &anoAtual);

    idade = anoAtual - anoNascimento;
    printf("Sua idade é: %d\n", idade);

    return 0;
}