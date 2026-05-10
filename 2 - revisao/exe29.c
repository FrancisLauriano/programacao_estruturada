#include <stdio.h>

int main(){
    int num1, num2, maior, menor, i, c, soma;
    int qtd_perfeito = 0;

    printf("Numero 1:\n");
    scanf("%d", &num1);

    printf("Numero 2:\n");
    scanf("%d", &num2);

    if(num1 >= num2){
        maior = num1;
        menor = num2;
    }else{
        maior = num2;
        menor = num1;
    }

    if(menor == 0){
        menor = 1;
    }

    for(i = menor; maior >= i; i += 1){
        soma = 0;
        for(c = 1; (i > c ); c += 1){
            if(i % c == 0){
                soma += c;
            }
        }

        if(soma == i){
            qtd_perfeito += 1;
        }
    }

    printf("Entre %d e %d tem %d perfeitos\n", menor, maior, qtd_perfeito);


    return 0;
}