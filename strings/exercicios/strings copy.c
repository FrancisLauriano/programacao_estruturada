#include <stdio.h>

#define TAM 15
#define TAM2 20

// void lerTexto(char frase[], int t);
// void tamanhoString(char texto[]);
// void maiusculoPrimeiraLetra(char texto[], int t);
// void imprimirSeComecarcomA(char texto[]);
// void quatroPrimeirasLetras(char texto[]);
// void qtdLetras(char frase[], int t);
// void copyTexto(char ori[], char nov[], int t);
// void comparar(char pal1[], char pal2[]);
// void fraseInversa(char texto[], char texto2[], int t);
// void semVogais(char pal[], int t);
// void qtdCadaVogal(char pal[], int t);
void qtdCadaLetra(char pal[], int t);

int main(){

    // char texto[TAM];
    // char texto2[TAM];
    // char copia[TAM2];
    char nova[TAM2];
    char nova2[TAM2];



    // lerTexto(texto, TAM);

    // // printf("Nome digitado:'%s'\n", texto);

    // maiusculoPrimeiraLetra(texto, TAM);

    // tamanhoString(texto);

    // imprimirSeComecarcomA(texto);

    // quatroPrimeirasLetras(texto);

    // qtdLetras(texto2, TAM);

    // copyTexto(texto, copia, TAM);


    // char palavra1[4] = "ana";
    // char palavra2[8] = "anabela";

    // comparar(palavra1, palavra2);

    // fraseInversa(nova, nova2, TAM2);
    
    // semVogais(nova, TAM2);

    // qtdCadaVogal(nova, TAM2);

    qtdCadaLetra(nova, TAM2);

    return 0;
}



void lerTexto(char frase[], int t){
    int i;

    printf("Informe seu nome:\n");
    fgets(frase, t, stdin);

    for(i = 0; frase[i] != '\0'; i += 1){
        if(frase[i] == '\n'){
            frase[i] = '\0';
            break;

        }
    }
}


void tamanhoString(char texto[]){
    int i;
    int qtd = 0;

    for(i = 0; texto[i] != '\0'; i += 1){
        if(texto[i] == '\n'){
            texto[i] == '\0';
            break;
        }
    }

    while(texto[qtd] != '\0'){
        qtd += 1;

    }

    printf("Tamanho da string: %d\n", qtd);

}

// imprimir string com a primeira de cada palavra em maiusculo
void maiusculoPrimeiraLetra(char texto[], int t){
    int i;

    for(i = 0; texto[i] != '\0'; i += 1){
        if((texto[i] >= 'a' && texto[i] <= 'z') && (i == 0 || texto[i - 1] == ' ')){
            texto[i] = texto[i] - 32;
        }
    }
    printf("Primeiras letras em maiusculos: %s\n", texto);
}

void imprimirSeComecarcomA(char texto[]){
   
    if(texto[0] == 'a' || texto[0] == 'A'){
        printf("Nome tem letra 'a' no inicio: %s\n", texto);
    }else{
        printf("nao comeca com a letra'a'\n");
    }
}

void quatroPrimeirasLetras(char texto[]){
    int i;

    printf("Quatro primeiras letras:\n");
    for(i = 0; i < 4; i += 1){
        printf("%c", texto[i]);
    }
    printf("\n");
}

void qtdLetras(char frase[], int t){
    int i;
    int qtd = 0;

    printf("Digite seu nome:\n");
    fgets(frase, t, stdin);

    for(i = 0; frase[i] != '\0'; i += 1){
        if(frase[i] == '\n'){
            frase[i] = '\0';
            break;
        }

        if(frase[i] != ' '){
            qtd += 1;
        }
    }


    printf("Qtd letras: %d\n", qtd);

}

void copyTexto(char ori[], char nov[], int t){
    int i;
    int tam = 0;

    printf("Informe frase:\n");
    fgets(ori, t, stdin);

    for(i = 0; ori[i] != '\0'; i += 1){

        if(ori[i] == '\n'){
            ori[i] = '\0';
            break;
        }

        tam += 1;
    }

    for(i = 0; i < tam; i += 1){
        nov[i] = ori[i];
    }

    nov[tam] = '\0';

    printf("Copia do texto: '%s'\n", ori);
    printf("'%s'\n", nov);

}

void comparar(char pal1[], char pal2[]){
    int i;
    int igual = 1;

    for(i = 0; pal1[i] != '\0' || pal2[i] != '\0'; i += 1){
        if(pal1[i] != pal2[i]){
            igual = 0;
            break;
        }
    }

    if(igual == 0){
        printf("Palavra '%s' e '%s' sao diferentes\n", pal1, pal2);

    }else{
        printf("Palavra '%s' e '%s' sao iguais\n", pal1, pal2);
    }
}


void fraseInversa(char texto[], char texto2[], int t){
    int i;
    int tam = 0;
    int qtd = 0;

    printf("Digite texto 1:\n");
    fgets(texto, t, stdin);

    for(i = 0; texto[i] != '\0'; i += 1){
        if(texto[i] == '\n'){
            texto[i] = '\0';
            break;
        }

        if(texto[i] != ' '){
            qtd += 1;
        }

        tam += 1;
    }

    for(i = 0; i < tam; i += 1){
        texto2[i] = texto[i];
    }

    texto2[tam] = '\0';

    printf("Tamanho string: %d\n", tam);
    printf("Qtd letras: %d\n", qtd);

    printf("Texto 1: %s\n", texto);
    printf("Texto 2: %s\n", texto2);

    printf("Inverso texto 1:\n");
    for(i = tam - 1; i >= 0; i -= 1){
        printf("%c", texto[i]);
    }
    printf("\n");

    
    printf("Inverso texto 1:\n");
    for(i = tam - 1; i >= 0; i -= 1){
        printf("%c", texto2[i]);
    }
    printf("\n");
}


void semVogais(char pal[], int t){
    int i;

    printf("Frase:\n");
    fgets(pal, t, stdin);
    

    for(i = 0; pal[i] != '\0'; i += 1){
        if(pal[i] == '\n'){
            pal[i] = '\0';
            break;
        }
    }

    printf("Palavra completa:\n");
    printf("%s\n", pal);

    printf("Palavra sem vogais:\n");
    for(i = 0; pal[i] != '\0'; i += 1){
        if(pal[i] != 'a' && pal[i] != 'e' && pal[i] != 'i' && pal[i] != 'o' && pal[i] != 'u' 
        && pal[i] != 'A' && pal[i] != 'E' && pal[i] != 'I' && pal[i] != 'O' && pal[i] != 'U'){
            printf("%c", pal[i]);

        }
    }

    printf("\n");
}

void qtdCadaVogal(char pal[], int t){
    int i;
    int qA = 0, qE = 0, qI = 0, qO = 0, qU = 0;

    printf("Palavra:\n");
    fgets(pal, t, stdin);

    for(i = 0; pal[i] != '\0'; i += 1){
        if(pal[i] == '\n'){
            pal[i] = '\0';
            break;
        }

        if(pal[i] == 'a' || pal[i] == 'A'){
            qA += 1;

        }

        if(pal[i] == 'e' || pal[i] == 'E'){
            qE += 1;

        }

        if(pal[i] == 'i' || pal[i] == 'I'){
            qI += 1;

        }

        if(pal[i] == 'o' || pal[i] == 'O'){
            qO += 1;

        }

        if(pal[i] == 'u' || pal[i] == 'U'){
            qU += 1;

        }
    }

    printf("Qtd letra a: %d\n", qA);
    printf("Qtd letra e: %d\n", qE);
    printf("Qtd letra i: %d\n", qI);
    printf("Qtd letra o: %d\n", qO);
    printf("Qtd letra u: %d\n", qU);

}


void qtdCadaLetra(char pal[], int t){
    int i, j;
    int cont[26] = {0};

    printf("Texto:\n");
    fgets(pal, t, stdin);

    for(i = 0; pal[i] != '\0'; i += 1){
        if(pal[i] == '\n'){
            pal[i] = '\0';
            break;
        }

        if(pal[i] >= 'A' && pal[i] <= 'Z'){
            pal[i] = pal[i] + 32;
        }

        if(pal[i] >= 'a' && pal[i] <= 'z'){
            cont[pal[i] - 'a'] += 1;
        }
    }

    printf("Quantidade de letras:\n");

    for(i = 0; i < 26; i += 1){
        if(cont[i] > 0){
            printf("%c: %d\n", 'a' + i, cont[i]);
        }
    }
}