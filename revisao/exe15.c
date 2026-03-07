#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main(){
    int num1;
    int i = 0;

    do{
        printf("Digite o 1º numero:\n");
        scanf("%d", &num1);
        i += 1;

        if(num1 == 0){
            printf("Quantidade de execuções: %d\n", i);
            break;       
        }else if(num1 % 2 == 0){
            printf("Numero %d é par.\n", num1);
        }else{
            printf("Numero %d é impar.\n", num1);
        }
    }while(TRUE);

    return 0;
}