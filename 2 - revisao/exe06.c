#include <stdio.h>

int main(){
    int num1;
    int num2;

    printf("Informe o 1º número:\n");
    scanf("%d", &num1);

    printf("Informe 2º número:\n");
    scanf("%d", &num2);

    if(num1 == num2){
        printf("Numeros são iguais\n");
        
    }else{
        printf("Numeros são diferente\n");
    }

    return 0;
}