#include <stdio.h>

int main(){
    int num1, num2;
    int mmc = 1;
    int fator = 2;

    printf("Numero 1:\n");
    scanf("%d", &num1);

    printf("Numero 2:\n");
    scanf("%d", &num2);


    while(num1 > 1 || num2 > 1){
        if(num1 % fator == 0 && num2 % fator == 0){
            printf("%d, %d | %d\n", num1, num2, fator);
            mmc *= fator;
            num1 /= fator;
            num2 /= fator;
        }else if(num1 % fator == 0){
            printf("%d, %d | %d\n", num1, num2, fator);
            mmc *= fator;
            num1 /= fator;
        }else if(num2 % fator == 0){
            printf("%d, %d | %d\n", num1, num2, fator);
            mmc *= fator;
            num2 /= fator;
        }else{
            fator += 1;
        }
        
    }

    printf("%d, %d | \n", num1, num2);
    printf("_____| %d\n", mmc);
   
    return 0;
}