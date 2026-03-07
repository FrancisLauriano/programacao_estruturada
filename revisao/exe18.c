#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main(){
    int num;
    float media;
    int soma = 0;
    int qtd_pares = 0;

    do{
        printf("Infome um número:\n");
        scanf("%d", &num);

        if(num % 2 == 0){
            soma += num;
            qtd_pares += 1;
        }

        if(qtd_pares == 5){
            media = soma / qtd_pares;
            printf("Soma: %d.\nMedia: %.2f\n", soma, media);

            break;
        }

    }while(TRUE);

    return 0;
}