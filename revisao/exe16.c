#include <stdio.h>

int main(){
    int num1, num2, maior, menor, i;

    printf("Digite o 1ª numero:\n");
    scanf("%d", &num1);

    printf("Digite o 2ª numero:\n");
    scanf("%d", &num2);

    if(num1 >= num2 ){
        maior = num1;
        menor = num2;
    }else{
        maior = num2;
        menor = num1;
    }


    for(i = menor; maior >= i; i += 1){
        if(i % 2 == 0){
            if (i % 6 == 0){
                continue;
            }
            printf("%d\n", i);
        }
    }

    return 0;
}