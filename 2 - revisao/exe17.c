#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main(){
    int num;
    float media;
    int soma = 0;
    int qtd = 0;

    do{
        printf("Digite um número:\n");
        scanf("%d", &num);

        if(num % 2 == 0){
            soma += num;
            qtd += 1;
        }else{
            media = soma / qtd;
            printf("Media: %.2f\n", media);
            break;
        }

    }while(TRUE);

    return 0;
}