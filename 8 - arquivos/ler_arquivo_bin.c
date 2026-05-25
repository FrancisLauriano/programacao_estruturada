// #include <stdio.h>

// #define TAM 20


// int main(){
//     FILE *arq;
//     char nomeArq[TAM] = "teste.bin";
//     int status, num;

//     arq = fopen(nomeArq, "rb");

//     if(arq == NULL){
//         printf("Erro ao abrir arquivo %s\n", nomeArq);
//         return 1;
//     }

//     printf("Arquivo aberto com sucesso\n");

    
//     status = fread(&num, sizeof(int), 1, arq);

//     if(status == 1){
//         printf("Arquivo %s lido com sucesso: %d\n", nomeArq, num);

//     }else{
//         printf("Erro ao ler arquivo\n");
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

int main(){

    FILE *arq;
    char nomeArq[] = "teste.bin";
    int status;
    int num;

    arq = fopen(nomeArq, "rb");

    if(arq == NULL){
        printf("Erro ao abrir arquivo %s\n", nomeArq);
        return 1;
    }

    printf("Arquivo aberto com sucesso\n");

    status = fread(&num, sizeof(int), 1, arq);

    while(!feof(arq)){

        if(!status){
            printf("Erro ao ler regristro\n");
            break;
        }

        printf("Registro lido com sucesso: %d\n", num);

        status = fread(&num, sizeof(int), 1, arq);

    }


    status = fclose(arq);

    if(!status){
        printf("Erro ao fechar arquivo %s\n", nomeArq);
        return 2;
    }

    printf("Arquivo %s fechado com sucesso\n", nomeArq);


    return 0;
}