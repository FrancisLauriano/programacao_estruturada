#include <stdio.h>
#include <string.h>

#define TAMANHO 21


int main(){
    char frase[TAMANHO];

    int i;

    printf("Insira uma frase:\n");
    fgets(frase, TAMANHO, stdin);

    for(i = 0; frase[i] != '\0'; i += 1){

        if((frase[i] >= 'a' && frase[i] <= 'z' ) && (i == 0 || frase[i-1] == ' ')){
            frase[i] = frase[i] - 32;
        }
    
    }
    printf("%s", frase);

    return 0;
}