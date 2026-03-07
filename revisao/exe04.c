#include <stdio.h>

int main(){
    int num1;
    int num2;

    printf("Informe o 1º número:\n");
    scanf("%d", &num1);

    printf("Informe 2º número:\n");
    scanf("%d", &num2);

    if(num1 >= num2){
        printf("%d é o maior\n", num1);
    }else{
        printf("%d é o maior\n", num2);
    }


    return 0;
}