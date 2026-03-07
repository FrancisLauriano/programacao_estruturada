#include <stdio.h>

int main(){
    int num1, num2, maior, menor;
    

    printf("Digite o 1º numero:\n");
    scanf("%d", &num1);

    printf("Digite o 2º numero:\n");
    scanf("%d", &num2);

    if(num2 >= num1){
        maior = num2;
        menor = num1;
    }else{
        maior = num1;
        menor = num2;
    }

    printf("Valores entre %d e %d:\n", menor, maior);
    while(menor <= maior){
        printf("%d\n", menor);
        menor += 1;

    }

    return 0;
}