#include <stdio.h>

int main(){
    float nota;

    printf("Insira a nota:\n");
    scanf("%f", &nota);

    if(nota >= 7.0){
        printf("Aprovado(a)!\n");
    } else if(nota < 7.0 && nota >= 4.0){
        printf("Tem direito a exame final!\n");
    } else{
        printf("Reprovado(a)!\n");
    }

    return 0;
}