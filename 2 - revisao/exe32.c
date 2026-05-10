#include <stdio.h>

char* parImpar(int n);
char* ehPerfeito(int n);
char* ehPrimo(int n);

int main(){
    int num;
    char* par_impar;
    char* perfeito;
    char* primo;

    printf("Numero:\n");
    scanf("%d", &num);
    
    par_impar = parImpar(num);
    printf("O numero %d é %s\n", num, par_impar);

    perfeito = ehPerfeito(num);
    printf("O numero %d %s\n", num, perfeito);

    primo = ehPrimo(num);
    printf("O numero %d %s\n", num, primo);

    return 0;
}


char* parImpar(int n){
    if(n % 2 == 0){
        return "par";     
    }else{
        return "impar";   
    }
}


char* ehPerfeito(int n){
    int soma = 0;

    for(int i = 1; n > i; i += 1){
        if(n % i == 0){
            soma += i;
        }
    }

    if(n == soma){
        return "é perfeito";
    }else{
        return "não é perfeito";
    }
}


char* ehPrimo(int n){
    int qtd_divisores = 0;

    for(int i = 1; n >= i; i += 1){
        if(n % i == 0){
            qtd_divisores += 1;
        }
    }

    if(qtd_divisores == 2){
        return "é primo";
    }else{
        return "não é primo";
    }

}