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
void receber(char frase[], int t){

    prinft("Digite sua frase:\n");
    fgets(frase, t, stdin);
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


// Faca um programa que  imprima string
void imprimir(char frase[]){
    printf("%s\n", frase);
}




// Primeira letra de cada palavra na string em maiusculo
void primeiraLetraCadaPalavraMaiusculo(char frase[]){
    int i;
    removerEnter(frase);

    for(i = 0; frase[i] != '\0'; i += 1){
        if((frase[i] >= 'a' && frase[i] <= 'z') && (i == 0 || frase[i - 1] == ' ') ){
            frase[i] = frase[i] - 32;
        }
    }
}



// Crie um programa que calcula o comprimento de uma string (nao use a funcao strlen).
int stringLen(char frase[]){
    int i;
    int tam = 0;

    removerEnter(frase);

    for(i = 0; frase[i] != '\0'; i += 1){
        tam += 1;
    }

    return tam;
}


// Entre com um nome e imprima o nome somente se a primeira letra do nome for ‘a’
// (maiuscula ou minuscula)




// faca um programa que leia um nome e imprima as 4 primeiras letras do nome.
void quatroPrimeirasLetras(char frase[]){
    int i;

    removerEnter(frase);

    for(i = 0; i < 4 && frase[i] != '\0'; i += 1){
        printf("%c", frase[i]);

    }

    printf("\n");

}


// Receber nome e contar quantas letras tem esse nome.
int qtdletrasNoNome(char frase[]){
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
void compararString(char fraseA[], char fraseB[]){
    int i;
    int igual = 1;

    removerEnter(fraseA);
    removerEnter(fraseB);

    for(i = 0; fraseA != '\0' && fraseB != '\0'; i += 1){
        if(fraseA[i] != fraseB[i]){
            igual = 0;
            break;
        }
    }

    if(fraseA[i] != '\0' || fraseB[i] != '\0'){
        igual = 0;

    }

    if(igual){
        printf("Iguais\n");

    }else{
        printf("Diferentes\n");
    }

}


// Escreva um programa que substitui as ocorrencias de um caractere ‘0’ em uma string por
// outro caractere ‘1’.



// Faca um programa que receba uma palavra e a imprima de tras-para-frente
void stringInvertida(char frase[]){
    int i;
    int tam = 0;

    removerEnter(frase);

    for(i = 0; frase[i] != '\0'; i += 1){
        tam += 1;
    }

    for(i = tam - 1; i >= 0; i -= 1){
        printf("%c", frase[i]);
    }

    printf("\n");

}



// Faca um programa que receba uma string e a imprima de tras-para-frente as palavras, mas mantenha a a ordem das palavras
void inverterCadaPalavraDaString(char frase[]){
    int i = 0;
    int inicio, fim, j;

    removerEnter(frase);


    while(frase[i] != '\0'){

        while(frase[i] == ' '){
            printf(" ");
            i += 1;
        }

        inicio = i;

        while(frase[i] != ' ' && frase[i] != '\0'){
            i += 1;
        }

        fim = i - 1;

        for(j = fim; j >= inicio; j -= 1){
            printf("%c", frase[i]);

        }
    }

    printf("\n");
    
}


// quantidades de cada letra de uma string
void qtdLetraCadaPalavra(char frase[]){
    int i;
    int cont[26] = {0};

    removerEnter(frase);

    for(i = 0; frase[i] != '\0'; i += 1){
        if(frase[i] >= 'A' && frase[i] <= 'Z'){
            frase[i] = frase[i] + 32;
        }

        if(frase[i] >= 'a' && frase[i] <= 'z'){
            cont[frase[i] - 'a'] += 1;
        }
    }

    for(i = 0; i < 26; i += 1){
        if(cont[i] > 0){
            printf("%c: %d\n", i + 'a', cont[i]);
        }

    }

}




// Faca um programa que receba do usuario uma string. O programa imprime a string sem
// suas vogais




// Faca um programa que receba uma palavra e calcule quantas vogais (a, e, i, o, u) possui
// essa palavra.


// copiar uma string
void copiarString(char frase[], char fraseCopy[]){
    int i, tam;

    tam = stringLen(frase);

    for(i = 0; i < tam; i += 1){
        fraseCopy[i] = frase[i];

    }

    fraseCopy[tam] = '\0';
    
}

