#include <stdio.h>
#include <string.h>

#define TAM 10


int tamanhoString(char p[]);
void receberString(char p[]);
void alfabeticaCrescente(char p1[], char p2[]);
void codigoASCII(char p[]);
void maiuscula(char p[]);


int main(){
    char pal1[TAM];
    char pal2[TAM];

    printf("1° Frase:\n");
    receberString(pal1);

    codigoASCII(pal1);

    maiuscula(pal1);

    // printf("2° frase:\n");
    // receberString(pal2);

    // alfabeticaCrescente(pal1, pal2);

    return 0;
}



int tamanhoString(char p[]){
    int i = 0;

    while(p[i] != '\0'){
        i += 1;
    }

    return i;

}

void receberString(char p[]){
    int i;
    int tamanho;

    fgets(p, TAM, stdin);

    tamanho = tamanhoString(p);

    for(i = 0; i < tamanho; i += 1){
        if(i > 0 && p[tamanho - 1] == '\n'){
            p[tamanho - 1] = '\0';
        }
    }
}


void alfabeticaCrescente(char p1[], char p2[]){
   
    if(strcmp(p1, p2) < 0){
        printf("%s\n", p1);
        printf("%s\n", p2);
    }else{
        printf("%s\n", p2);
        printf("%s\n", p1);
    }
}


void ordemReversa(char p[]){
    int i, t;

    t = tamanhoString(p);

    for(i = t - 1; i >= 0; i -= 1){
        printf("%c", p[i]);
    }

    printf("\n");

}



void codigoASCII(char p[]){
    int i, t;

    t = tamanhoString(p);

    for(i = 0; i < t; i += 1){
        printf("Letra '%c' - ASCII '%d'\n", p[i], p[i]);

    }

}


void maiuscula(char p[]){
    int i, t;

    t = tamanhoString(p);

    for(i = 0; i < t; i += 1){
        if(p[i] >= 'a' && p[i] <= 'z'){
           p[i] = p[i] - 32;
        }
        printf("%c", p[i]);
    }
    printf("\n");
}