#include <stdio.h>
#include <string.h>

#define TAM_P 5
#define TAM_N 20
#define NOME_ARQ "teste.bin"

struct Pessoa{
    char nome[TAM_N];
    int idade;
    double peso;
    double altura;
    double imc;
};

void receberString(char s[], int t){
    int tam;
    fgets(s, t, stdin);
    tam = strlen(s);

    if(tam > 0 && s[tam - 1] == '\n'){
        s[tam - 1] = '\0';
    }
}

int criarArquivo(){
    FILE *arq;
    arq = fopen(NOME_ARQ, "wb");

    if(arq == NULL){
        printf("Erro ao criar arquivo\n");
        return 0;
    }

    printf("Arquivo criado com sucesso!\n");

    fclose(arq);

    return 1;

}


void cadastrarPessoa(struct Pessoa *p){
    printf("Informe o nome:\n");
    receberString(p -> nome, TAM_N);

    printf("Idade:\n");
    scanf("%d", &p -> idade);

    printf("Peso:\n");
    scanf("%lf", &p -> peso);

    printf("Altura:\n");
    scanf("%lf", &p -> altura);

    p -> imc = p -> peso / (p -> altura * p -> altura);

    getchar(); // limpar  buffer

}

void cadastrarPessoas(struct Pessoa vp[], int *qtd){
    FILE *arq;
    int status;
    int continua = 1;

    if(*qtd >= TAM_P){
        printf("Vetor sem espaco\n");
        return;
    }

    arq = fopen(NOME_ARQ, "ab");

    if(arq == NULL){
        printf("Erro ao abrir arquivo %s\n", NOME_ARQ);
        return;
    }

    do{
        cadastrarPessoa(&vp[*qtd]);
        status = fwhite(&vp[*qtd], sizeof(struct Pessoa), 1, arq);

        if(!status){
            printf("Erro ao gravar regristro\n");
            break;
        }

        printf("Registro gravado com sucesso\n");
        *qtd += 1;

        if (*qtd >= TAM_P) {
            printf("Vetor cheio\n");
            break;
        }


        do{
            printf("Deseja continuar?\n1. Sim\n0. Nao\n");
            scanf("%d", &continua);
            getchar(); // limpar buffer

            if(continua != 0 && continua != 1){
                printf("Valor invalido\n");
                continue;
            }

        }while(continua != 0 && continua != 1);


    }while(continua == 1 && *qtd < TAM_P);

    fclose(arq);

}



