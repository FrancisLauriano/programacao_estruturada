#include <stdio.h>

#define TAM 20


int main(){
    FILE *arq;
    char nomeArq[TAM] = "teste.bin";
    int status, num;

    arq = fopen(nomeArq, "rb");

    if(arq == NULL){
        printf("Erro ao abrir arquivo %s\n", nomeArq);
        return 1;
    }

    printf("Arquivo aberto com sucesso\n");

    
    status = fread(&num, sizeof(int), 1, arq);

    if(status == 1){
        printf("Arquivo %s lido com sucesso: %d\n", nomeArq, num);

    }else{
        printf("Erro ao ler arquivo\n");
    }


    status = fclose(arq);

    if(status == 0){
        printf("Arquivo %s fechado com sucesso\n", nomeArq);
    }else{
        printf("Erro ao fechar arquivo\n");
        return 2;
    }


    return 0;
}