#include <stdio.h>

int main(){
    int num1, num2, num3;

    printf("Digite o 1º número:\n");
    scanf("%d", &num1);

    printf("Digite o 2º número:\n");
    scanf("%d", &num2);

    printf("Digite o 3º número:\n");
    scanf("%d", &num3);


    if(num1 == num2 && num2 == num3){
        printf("%d = %d = %d\nSão Iguais\n", num1, num2, num3);
    }else if(num1 > num2 && num2 > num3){
        printf("%d > %d > %d\nOrdem decrescente\n", num1, num2, num3);
    }else if(num1 < num2 && num2 < num3){
        printf("%d < %d < %d\nOrdem crescente\n", num1, num2, num3);

    }else{
        printf("%d - %d - %d\nSem ornedm entre eles\n", num1, num2, num3);
    }

    return 0;
}