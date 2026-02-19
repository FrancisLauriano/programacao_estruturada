#include <stdio.h>

float calcularImc(float p, float a);
char clasificacaoImc(float i);

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

char classificacaoImc(float i){
    if (i >= 18.00 && i <= 24.99) {
        return "Eutrofico";
    }else if(i >=) 25 e < 30)
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