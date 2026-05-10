#include <stdio.h>

#define TAM 21
#define LETRAS 4

void receberString(char f[], int t);
void imprimirPrimeirasLetras(char f[], int l);

int main(){
char frase[TAM];

receberString(frase, TAM);
imprimirPrimeirasLetras(frase, TAM);


    return 0;
}



void receberString(char f[], int t){
    int i;

    printf("Informe sua frase:\n");
    fgets(f, t, stdin);

    for(i = 0; f[i] != '\0'; i += 1){
        if(f[i] == '\n'){
            f[i] = '\0';
            break;
        }
    }
}

void imprimirPrimeirasLetras(char f[], int l){
    int i;

    for(i = 0; i < 4; i += 1){
        printf("%c", f[i]);

    }
    printf("\n");
}