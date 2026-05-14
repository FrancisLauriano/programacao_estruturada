// #include <stdio.h>

// #define TAM 20


// int main(){
//     FILE *arq;
//     char nomeArq[TAM] = "teste.bin";
//     int status;
//     int num = 50;

//     arq = fopen(nomeArq, "wb");

//     if(arq == NULL){
//         printf("Erro ao abrir arquivo %s\n", nomeArq);
//         return 1;
//     }


//     printf("Arquivo aberto com sucesso\n");

//     status = fwrite(&num, sizeof(int), 1, arq);

//     if(status == 1){
//         printf("Gravado arquivo %s\n", nomeArq);
//     }else{
//         printf("Erro gravar arquivo");
//     }


//     status = fclose(arq);

//     if(status == 0){
//         printf("Arquivo %s fechado com sucesso\n", nomeArq);
//     }else{
//         printf("Erro ao fechar arquivo\n");
//         return 2;
//     }

//     return 0;
// }


#include <stdio.h>

#define TAM 5
#define CHAR 10

int main(){
    FILE *arq;
    char nomeArq[CHAR] = "teste.bin";
    int num, i;
    int status;

    arq = fopen(nomeArq, "wb");


    if(arq == NULL){
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    printf("Arquivo %s criado com sucesso!\b", nomeArq);

    for(i = 0; i < TAM; i += 1){
        printf("Digite numero inteiro:\n");
        scanf("%d", &num);

        status = fwrite(&num, sizeof(int), 1, arq);

        if(status){
            printf("Registro gravado com sucesso\n");
        }else{
            printf("Erro na gravação do registro\n");
            break;
        }
    }

    status = fclose(arq);

    if(status == 0){
        printf("Arquivo %s fechado com sucesso\n", nomeArq);
    }else{
        printf("Erro ao fechar arquivo %s\n", nomeArq);
        return 2;
    }

    return 0;
}
