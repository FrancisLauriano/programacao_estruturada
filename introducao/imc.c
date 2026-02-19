#include <stdio.h>

float calcularImc(float p, float a);

int main(){
    float peso, altura, imc;

    printf("Digite o peso:\n");
    scanf("%f", &peso);

    printf("Digite altura:\n");
    scanf("%f", &altura);

    imc = calcularImc(peso, altura);

    printf("Seu IMC: %.2f.\n", imc);

    return 0;
}


float calcularImc(float p, float a) {
    return p / (a*a);
}


// float calcularImc(float p, float a) {
//     return p / (a*a);
// }

// int main(){
//     float peso, altura, imc;

//     printf("Digite o peso:\n");
//     scanf("%f", &peso);

//     printf("Digite altura:\n");
//     scanf("%f", &altura);

//     imc = calcularImc(peso, altura);

//     printf("Seu IMC: %.2f.\n", imc);

//     return 0;
// }