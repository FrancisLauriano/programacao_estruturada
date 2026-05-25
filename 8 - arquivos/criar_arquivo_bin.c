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


int main(){

    FILE *arq;
    char nomeArq[] = "teste.bin";
    int num;
    int status, i;


    arq = fopen(nomeArq, "wb");

    if(arq == NULL){
        printf("Erro ao criar arquivo %s\n", nomeArq);
        return 1;
    }

    printf("Arquivo %s criado com sucesso\n", nomeArq);

    for(i = 0; i < TAM; i += 1){
        printf("Digite um numero inteiro:\n");
        scanf("%d", &num);

        status = fwrite(&num, sizeof(int), 1, arq);


        if(!status){
            printf("Erro ao gravar registro\n");
            break;
        }

        printf("Registro gravado com sucesso\n");
    }


    status = fclose(arq);

        if(status){
            printf("Erro ao fechar arquivo %s\n", nomeArq);
            return 2;
        }

        printf("Arquivo %s fechado com sucesso\n", nomeArq);


    return 0;
}

