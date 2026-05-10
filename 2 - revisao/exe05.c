#include <stdio.h>

int main(){
    int num;
    float valor_total = 0;

    printf("Informe qtd maças:\n");
    scanf("%d", &num);

    if(num > 15){
        valor_total = num * 0.25;
        printf("Valor R$: %.2f\n", valor_total); 
    }else{
        valor_total = num * 0.30;
        printf("Valor R$: %.2f\n", valor_total); 
    }

    return 0;
}