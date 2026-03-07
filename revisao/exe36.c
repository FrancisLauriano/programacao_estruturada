#include <stdio.h>

int fatorial_numero(int n);

int main(){
    int num;
    int fatorial;

    printf("Fatorial no numero:\n");
    scanf("%d", &num);

    fatorial = fatorial_numero(num);

    printf("Fatorial do número %d é: %d\n", num, fatorial);

    return 0;
}

int fatorial_numero(int n){
    int fatorial = 1;
    int i;

    for(i = n; i >= 1; i -= 1){
        fatorial *= i;
    }
    return fatorial;
}