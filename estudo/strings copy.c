#include <stdio.h>

#define TAM 15
#define TAM2 20



int main(){

    char texto[TAM];
    char texto2[TAM];
    char copia[TAM2];
    char nova[TAM2];
    char nova2[TAM2];



  

    return 0;
}


// Faca um programa que entao leia uma string
void receberString(char frase[], int t){
    int i;

    printf("Informe sua frase:\n");

    fgets(frase, t, stdin);

    for(i = 0; frase[i] != '\0'; i += 1){
        if(frase[i] == '\n'){
            frase[i] = '\0';
            break;
        }
    }
}

// remover enter da string
void removerEnter(char frase[]){
    int i;

    for(i = 0; frase[i] != '\0'; i += 1){
        if(frase[i] == '\n'){
            frase[i] = '\0';
            break;
        }
    }
}


// Faca um programa que entao  imprima
void imprimir(char frase[]){
    printf("Frase digitada: %s\n", frase);

}


// Primeira letra de cada palavra na string em maiusculo
void capitalize(char frase[]){
    int i;

    for(i = 0; frase[i] != '\0'; i += 1){
    
        if((frase[i] >= 'a' && frase[i] <= 'z') && (i == 0 || frase[i - 1] == ' ')){
            frase[i] = frase[i] - 32;
        }
    }
}

// Crie um programa que calcula o comprimento de uma string (nao use a funcao strlen).
int stringLen(char frase[]){
    int i;
    int qtd = 0;

    for(i = 0; frase[i] != '\0'; i += 1){
        qtd += 1;
    }
    return qtd;
}


// Entre com um nome e imprima o nome somente se a primeira letra do nome for ‘a’
// (maiuscula ou minuscula)
void imprimirSeIniciarEmA(char frase[]){
    int i;

    if(frase[0] == 'a' || frase[0] == 'A'){
        printf("Sua string: %s\n", frase);

    }else{
        printf("Nao e possivel imprimir. Nao comeca com 'a'\n");
    }
}


// faca um programa que leia um nome e imprima as 4 primeiras letras do nome.
void imprimirQuatroPrimeirasLetras(char frase[]){
    int i;

    printf("Quatro primeiras letras:\n");

    for(i = 0; i < 4 && frase[i] != '\0'; i += 1){
        printf("%c", frase[i]);
    }
}


// Receber nome e contar quantas letras tem esse nome.
int qtdLetrasNome(char frase[]){
    int i;
    int qtd = 0;

    removerEnter(frase);

    for(i = 0; frase[i] != '\0'; i += 1){
        if(frase[i] != ' '){
            qtd += 1;
        }
    }
    return qtd;
}


// Crie um programa que compara duas strings (nao use a funcao strcmp).
void compararDuasStrings(char fraseA[], char fraseB[]){
    int i;
    int igual = 1;

    for(i = 0; fraseA[i] != '\0' && fraseB[i] != '\0'; i += 1){
        if(fraseA[i] != fraseB[i]){
            igual = 0;
            break;
        }
    }


    if(fraseA[i] != '\0' || fraseB[i] != '\0'){
        igual = 0;
    }


    if(igual){
        printf("Strings '%s' e '%s' sao iguais\n", fraseA, fraseB);
    }else{
        printf("Strings '%s' e '%s' sao diferentes\n", fraseA, fraseB);
    }
}


// Escreva um programa que substitui as ocorrencias de um caractere ‘0’ em uma string por
// outro caractere ‘1’.
void substituirCaractere(char frase[]){
    int i;

    for(i = 0; frase[i] != '\0'; i += 1){
        if(frase[i] == '0'){
            frase[i] = '1';
        }
    }
}


// Faca um programa que receba uma palavra e a imprima de tras-para-frente
void inverterString(char frase[]){
    int i;
    int tam = 0;

    printf("Sua string de tras-para-frente:\n");

    for(i = 0; frase[i] != '\0'; i += 1){
        tam += 1;
    }

    for(i = tam - 1; i >= 0; i -= 1){
        printf("%c", frase[i]);
    }
}

// Faca um programa que receba uma string e a imprima de tras-para-frente as palavras, mas mantenha a a ordem das palavras
void inverterApenasPalavra(char frase[]){
    int i = 0;
    int inicio, fim, j;

    while(frase[i] != '\0'){

        while(frase[i] != '\0' && frase[i] == ' '){
            printf(" ");
            i += 1;
        }

        inicio = i;

        while(frase[i] != '\0' && frase[i] != ' '){
            i += 1;
        }

        fim = i - 1;

        for(j = fim; j >= inicio; j -= 1){
            printf("%c", frase[j]);

        }
    }

    printf("\n");
}


// Faca um programa que receba do usuario uma string. O programa imprime a string sem
// suas vogais
void semVogais(char frase[]){
    int i, j, igual;

    char vogais[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    printf("Sua string sem vogais:\n");

    for(i = 0; frase[i] != '\0'; i += 1){
        igual = 0;

        for(j = 0; j < 10 ; j += 1){
            if(frase[i] == vogais[j]){
                igual = 1;
                break;
            }
        }

        if(igual == 0){
            printf("%c", frase[i]);
        }
    }
}

// Faca um programa que receba uma palavra e calcule quantas vogais (a, e, i, o, u) possui
// essa palavra.
void qtdDeCadaVogal(char frase[]){
    int i;
    int qtdA = 0, qtdE = 0, qtdI = 0, qtdO = 0, qtdU = 0;

    for(i = 0; frase[i] != '\0'; i += 1){
        if(frase[i] == 'a' || frase[i] == 'A'){
            qtdA += 1;
        }

        if(frase[i] == 'e' || frase[i] == 'E'){
            qtdE += 1;
        }

        if(frase[i] == 'i' || frase[i] == 'I'){
            qtdI += 1;
        }

        if(frase[i] == 'o' || frase[i] == 'O'){
            qtdO += 1;
        }

        if(frase[i] == 'u' || frase[i] == 'U'){
            qtdU += 1;
        }
    }

    printf("Letra 'A': %d\n", qtdA);
    printf("Letra 'E': %d\n", qtdE);
    printf("Letra 'I': %d\n", qtdI);
    printf("Letra 'O': %d\n", qtdO);
    printf("Letra 'U': %d\n", qtdU);
}


// quantidades de cada letra de uma string
void qtdDeCadaLetraNaString(char frase[]){
    int i;

    int cont[26] = {0};

    removerEnter(frase);


    for(i = 0; frase[i] != '\0'; i += 1){
        if(frase[i] >= 'A' && frase[i] <= 'Z'){
            frase[i] = frase[i] + 32;
        }

        if(frase[i] >= 'a' &&  frase[i] <= 'z'){
            cont[frase[i] - 'a'] += 1;
        }
    }

    for(i = 0; i < 26; i += 1){
        if(cont[i] > 0){
            printf("%c: %d\n", i + 'a', cont[i]);

        }
        
    }

}


// copiar uma string
void copiarUmaString(char frase[], char fraseCopy[]){
    int i, tam;

    removerEnter(frase);
    tam = stringLen(frase);


    for(i = 0; i < tam; i += 1){
        fraseCopy[i] = frase[i];
       
    }

   
    fraseCopy[tam] = '\0';

}
