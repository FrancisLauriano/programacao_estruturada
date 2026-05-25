#include <stdio.h>
#include <string.h>

#define TAM 100


char *fLerStr(char p[], int t, FILE *arq);
void lerStr(char p[], int t);


int main(){
    FILE *arq;
    char nomeArq[] = "teste.txt";
    char palavra[TAM], *statusFr;
    int status;

    arq = fopen(nomeArq, "rt");

    if(arq == NULL){
        printf("Erro ao abrir arquivo %s\n", nomeArq);
        return 1;
    }

    printf("Arquivo %s aberto com sucesso\n", nomeArq);

    statusFr = fLerStr(palavra, TAM, arq);
    
    while(statusFr != NULL && !feof(arq)){
        printf("%s\n", palavra);

        statusFr = fLerStr(palavra, TAM, arq);

    }


    status = fclose(arq);

    if(status != 0){
        printf("Erro ao fechar arquivo %s\n", nomeArq);
        return 2;
    }
    

    return 0;
}



char *fLerStr(char p[], int t, FILE *arq){

    char res = fgets(p, t, arq);

    int tam = strlen(p);

    if(tam > 0 && p[tam - 1] == '\n'){
        p[tam - 1] = '\0';

    }
    return res;
}


void lerStr(char p[], int t){
    fLerStr(p, t, stdin);

}