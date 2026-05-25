#include <stdio.h>

#define TAM_MAX 10


void inserirValor(double n[], int *qtd);
int buscaValor(double n[], double num, int qtd);
void imprimir(double n[], int qtd);
int verificaValor(double n[], double num, int qtd);



int main(){
    double vetorNum[TAM_MAX];
    int opcao;
    int quantidade = 0;
    double numero;
    int pesquisa;
    

    do{
        printf("=== MENU ===\n1. Inserir\n2. Busca\n3. Listar\n0. Sair\nOpcao: ");
        scanf("%d", &opcao);


        if(opcao == 1){
        
            inserirValor(vetorNum, &quantidade);

            continue;
        }else if(opcao == 2){
            printf("Valor a pesquisar:\n ");
            scanf("%lf", &numero);

            pesquisa = buscaValor(vetorNum, numero, quantidade);

            if(pesquisa == -1){
                printf("Numero nao localizado\n");
            }else{
                printf("Numero encontrado na posicao: %d\n", pesquisa);
            }

            continue;
        }else if(opcao == 3){
            imprimir(vetorNum, quantidade);
            continue;
        }else if(opcao == 0){
            printf("Encerrando...\n");
            break;
        }else{
            printf("Opcao invalida. Tente novamente\n");
            continue;
        }

    }while(opcao != 0);

    printf("Vetor final\n");
    imprimir(vetorNum, quantidade);
    
    return 0;
}



void inserirValor(double n[], int *qtd){
    double valor;
    int valorRepetido;
    int continuar = 1;
    int pos;

    

    while(continuar && *qtd < TAM_MAX){
        
        printf("%d valor:\n", *qtd + 1);
        scanf("%lf", &valor);

        valorRepetido = verificaValor(n, valor, *qtd);

        // inserir de forma crescente
        if(!valorRepetido){
            pos = *qtd;

            while(pos > 0 &&  n[pos - 1] > valor){
                n[pos] = n[pos - 1];
                pos -= 1;
            }
            n[pos] = valor;
            
            *qtd += 1;
            printf("Valor inserido com sucesso\n");
        }else{
            printf("Valor repedido. Tente outro valor.\n");
            continue;
        }

        if(*qtd >= TAM_MAX){
            printf("Vetor  sem espaco\n");
            break;
        }


        printf("Deseja continuar inserindo novos valores?\n1. SIM\n0. NAO\nOpcao: ");
        scanf("%d", &continuar);

    }


}

int verificaValor(double n[], double num, int qtd){
    int i;

    for(i = 0; i < qtd; i += 1){
        if(n[i] == num){
            return 1;
        }
    }

    return 0;
}



int buscaValor(double n[], double num, int qtd){
    int i;

    for(i = 0; i < qtd; i += 1){
        if(num == n[i]){
            return i;
        }
    }

    return -1;
}


void imprimir(double n[], int qtd){
    int i;

    for(i = 0; i < qtd; i += 1){
        printf("%.2lf", n[i]);

        if(i < qtd - 1){
            printf(", ");
        }
    }

    printf("\n");
}