#include <stdio.h>

int main(){
    int num1, num2, maior, menor, i;
    int soma = 0;
    int qtd = 0;
    double media;

    printf("numero 1:\n");
    scanf("%d", &num1);

    printf("numero 2:\n");
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
        qtd += 1;
    }

    media = soma / qtd;

    printf("Soma: %d\nA media dos %d número: %.2lf\n", soma, qtd, media);

    return 0;
}