#include <stdio.h>

#define TAM 5
#define CHAR 10

int main(){
    FILE *arq;
    char nomeArq[CHAR] = "teste.bin";
    int num;
    int status;         

    arq = fopen(nomeArq, "r+b");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo %s\n", nomeArq);
        return 1;
    }

    printf("Arquivo %s aberto com sucesso\n", nomeArq);

    status = fread(&num, sizeof(int), 1, arq);

    while(!feof(arq)){
        if(status){
            printf("Registro lido com sucesso: %d\n", num);

            num *= 2;

            status = fseek(arq, - sizeof(int), SEEK_CUR);


            if(status == 0){
                status = fwrite(&num, sizeof(int), 1, arq);

                if(status){
                    printf("Registro atualizado com sucesso\n");
                    fflush(arq);

                }else{
                    printf("Erro ao atualizar registro\n");
                    break;
                }

            }else{
                printf("Erro no posicionamento\n");
                break;
            }

        }else{
            printf("Erros ao ler o registro\n");
            break;
        }

        status = fread(&num, sizeof(int), 1, arq);

    }

    status = fclose(arq);

    if(status == 0){
        printf("Arquivo %s fechado com sucesso\n", nomeArq);

    }else{
        printf("Erro ao fechar o arquivo %s", nomeArq);
        return 2;

    }

    return 0;
}