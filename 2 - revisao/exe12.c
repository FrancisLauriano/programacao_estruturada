#include <stdio.h>

int main() {
    int num = 0;

    printf("Informe um numero inteiro:\n");
    scanf("%d", &num);

    printf("\nNumeros pares de 0 a %d:\n", num);
    for(int i = 0; i <= num; i+=1){
        if(i % 2 == 0) {
            printf("%d\n", i);
        }
    }   
    return 0;
}