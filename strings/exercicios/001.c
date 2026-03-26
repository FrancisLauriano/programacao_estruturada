#include <stdio.h>

#define TAM 11

void receber(char t[], int tam);
void maisculo(char t[]);

int main(){

    char texto[TAM];

    receber(texto, TAM);

    printf("\nTexto original: %s\n", texto);

    maisculo(texto);

    return 0;
}


void receber(char t[], int tam){
    int i;

    printf("Informe texto[ate 10 letras]:\n");
    fgets(t, tam, stdin);

    for(i = 0; t[i] != '\0'; i += 1){
        if(i != 0 && (t[i]) == '\n'){
            t[i] = '\0';
            break;
        }

    }
}


void maisculo(char t[]){
    int i;

    for(i = 0; t[i] != '\0'; i += 1){

        if((t[i] >= 'a' && t[i] <= 'z') && (i == 0 || t[i - 1] == ' ')){
            t[i] = t[i] - 32;
        }
    }
    printf("Maisculo: %s\n", t);
}
