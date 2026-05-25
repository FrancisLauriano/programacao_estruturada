#include <stdio.h>
#include <string.h>

#define TAM 100


void lerStr(char p[], int t);

int main(){

    FILE *arq;
    char nomeArq = "teste.txt";
    char palavra[TAM];
    int status, tamStr;


    arq = fopen(nomeArq, "wt");

    if(arq == NULL){
        printf("Erro ao abrir arquivo %s\n", nomeArq);
        return 1;
    }

    printf("Arquivo %s aberto com sucesso\n", nomeArq);


    printf("Digite seu texto:\n");

    lerStr(palavra, TAM);
    tamStr = strlen(palavra);
    status = fprintf(arq, "%s\n", palavra);

    while(tamStr > 0 && status == tamStr + 1){

        lerStr(palavra, TAM);
        tamStr = strlen(palavra);
        status = fprintf(arq, "%s\n", palavra);
    }

    status = fclose(arq);

    if(status != 0){
        printf("Erro ao fechar o arquivo %s\n", nomeArq);
        return 2;
    }

    printf("Arquivo %s fechado com sucesso\n", nomeArq);


    return 0;
}



void lerStr(char p[], int t){
    int tam; 
    fgets(p, t, stdin);

    tam = strlen(p);

    if(tam > 0 && p[tam - 1] == '\n'){
        p[tam - 1] = '\0';

    }
}