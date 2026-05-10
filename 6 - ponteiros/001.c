#include <stdio.h>
#include <string.h>


#define TAM 5


int main(){
    int i;

    int inteiro = 10;
    double real = 2.5;
    char caracteres[20] = "Francis";
    int vetor[TAM] = {1, 2, 3, 4, 5};

    int *p_inteiro;
    double *p_real;
    char *p_caracteres;
    int *p_vetor;

    p_inteiro = &inteiro;
    p_real = &real;
    p_caracteres = caracteres;
    p_vetor = vetor;
   

    printf("ANTES:\n");
    printf("inteiro: %d\n", inteiro);
    printf("real: %.2lf\n", real);
    printf("caracteres: %s\n", caracteres);
    printf("vetor: ");
    for(i = 0; i < TAM; i += 1){
        printf("%d ", vetor[i]);
    }
    
    printf("\n");


    printf("p_inteiro: %d\n", *p_inteiro);
    printf("p_real: %.2lf\n", *p_real);
    printf("p_caracteres: %s\n", p_caracteres);
    printf("p_vetor: ");
    for(i = 0; i < TAM; i += 1){
        printf("%d ", p_vetor[i]);

    }
    
    printf("\n");

    printf("\n------------------------------------------------\n");

    printf("DEPOIS:\n");

    *p_inteiro = 20;
    *p_real = 7.8;
    strcpy(p_caracteres, "Lauriano");
    for(i = 0; i < TAM; i += 1){
        p_vetor[i] = i + 6;
    }

    printf("inteiro: %d\n", inteiro);
    printf("real: %.2lf\n", real);
    printf("caracteres: %s\n", caracteres);
    printf("vetor: ");
    for(i = 0; i < TAM; i += 1){
        printf("%d ", vetor[i]);
    }
    
    printf("\n");

    printf("p_inteiro: %d\n", *p_inteiro);
    printf("p_real: %.2lf\n", *p_real);
    printf("p_caracteres: %s\n", p_caracteres);
    printf("p_vetor: ");
    for(i = 0; i < TAM; i += 1){
        printf("%d ", p_vetor[i]);
    }

    printf("\n");

    return 0;
}


