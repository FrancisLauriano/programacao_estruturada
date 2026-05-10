#include <stdio.h>

float calcularImc(float p, float a);

char* clasificacaoImc(float i);

int main(){
    float peso, altura, imc;
    char* classificacao;

    printf("Digite o peso:\n");
    scanf("%f", &peso);

    if (peso <= 0.0){
        printf("Peso Inválido!\n");
        return 1;
    }

    printf("Digite altura:\n");
    scanf("%f", &altura);

    if (altura <= 0.0){
        printf("Altura Inválida!\n");
        return 1;
    }

    imc = calcularImc(peso, altura);

    classificacao = clasificacaoImc(imc); 
    printf("Seu IMC: %.2f.\n", imc);
    printf("Classificacao: %s.\n", classificacao);

    return 0;
}

char* clasificacaoImc(float i){
    if(i < 18.5) {
        return "Baixo Peso";
    }else if(i <= 24.9) {
        return "Eutrofico";
    }else if(i <= 29.9) {
        return "Sobrepeso";
    }else if(i <= 39.9) {
        return "Obesidade";
    }else{
        return "Obesidade Grave";
    }
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