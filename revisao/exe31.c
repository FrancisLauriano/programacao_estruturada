#include <stdio.h>

int main(){
    int num, i;
    int qtd_divisores = 0;

    printf("Numero:\n");
    scanf("%d", &num);

    for(i = 1; num >= i; i += 1){
        if(num % i == 0){
            qtd_divisores += 1;
        }
    }

    if(qtd_divisores == 2){
        printf("%d é um número primo\n", num);
    }else{
        printf("%d não é um número primo\n", num);

    }

    return 0;
}