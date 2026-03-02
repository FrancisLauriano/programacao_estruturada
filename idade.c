#include <stdio.h>

int main(){
    int idade, qtdPessoas = 0, soma = 0;
    double media;
    printf("Digite sua idade:\n");
    scanf("%d", &idade);

    while (idade >= 0) {
        qtdPessoas += 1;
        soma += idade;
        printf("Digite sua idade (<0 para finalizar):");
        scanf("%d", &idade);
    }
    if (qtdPessoas != 0) {
        media = (double) soma / (double) qtdPessoas;
        printf("A media de idade dos participantes: %.2lf anos.\n", media);
    } else {
        printf("Nenehuma idade valida foi digitada!\n");
    }
    return 0;
}