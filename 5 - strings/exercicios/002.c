#include <stdio.h>

#define TAM 11

void receber(char t[], int tam);
int contadorString(char t[]);

int main(){
    char texto[TAM];
    int qtd;

    receber(texto, TAM);

    qtd = contadorString(texto);

    printf("O texto '%s' tem comprimento: %d.\n", texto, qtd);

    return 0;
}

void receber(char t[], int tam){
    int i;

    printf("Digitar texto:\n");
    fgets(t, tam, stdin);

    for(i = 0; t[i] != '\0'; i += 1){
        if(i != 0 && t[i] == '\n'){
            t[i] = '\0';
            break;
        }
    }
}

int contadorString(char t[]){
    int i;
    int qtd = 0;

    for(i = 0; t[i] != '\0'; i += 1){
        qtd += 1;
    }
    return qtd;
}