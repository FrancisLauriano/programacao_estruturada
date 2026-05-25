#include <stdio.h>


int main(){

    FILE *arq;
    char nomeArq[] = "teste.bin";
    int num;
    int status, i;


    arq = fopen(nomeArq, "r+b");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo %s\n", nomeArq);
        return 1;
    }


    printf("Arquivo %s aberto com sucesso\n", nomeArq);


    status = fread(&num, sizeof(int), 1, arq);

    while(!feof(arq)){
        if(status != 1){
            printf("Erro ao ler o registro\n");
            break;
        }

        printf("registro lido com sucesso: %d\n", num);

        num *= 2;

        status = fseek(arq, - sizeof(int), SEEK_CUR);

        if(status != 0){
            printf("Erro de posicionamento\n");
            break;

        }

        printf("Sucesso no posicionamento\n");


        status = fwrite(&num, sizeof(int), 1, arq);

        if(status != 1){
            printf("Erro ao regitrar atualizacao\n");
            break;

        }

        printf("Atualização registrada com sucesso\n");
        fflush(arq);

        status = fread(&num, sizeof(int), 1, arq);

    }



    status = fclose(arq);

    if(status != 0){
        printf("Erro ao fechar arquivo %s\n", nomeArq);
        return 2;
    }


    printf("Arquivo fechado com sucesso\n");

    return 0;
}