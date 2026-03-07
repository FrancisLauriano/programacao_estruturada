#include <stdio.h>

int main(){
    int num, i;
    int fatorial = 1;

    printf("Informe número:\n");
    scanf("%d", &num);

    for(i = 1; num >= i; i += 1){
        fatorial *= i;
        printf("%d! ", i);
    }

    printf("= %d\n", fatorial);

    return 0;
}