#include <stdio.h>

double somatorio(double n);

int main(){
    double num, soma;

    printf("Numero:\n");
    scanf("%lf", &num);

    soma = somatorio(num);
    printf("Somatorio de 1 ate %.2lf: %.2lf\n", num, soma);

    return 0;
}


double somatorio(double n){
    double soma = 0.00;

    for(double i = 1.00; n >= i; i += 1.00){
        soma += i;
    }

    return soma;
}