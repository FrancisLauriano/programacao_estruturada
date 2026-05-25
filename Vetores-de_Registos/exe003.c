#include <stdio.h>
#include <string.h>

#define TAM_CONTA 100
#define TAM_CPF 20
#define TAM_NOME 100
#define TAM_TEL 20

struct Conta{
    int num;
    char nome[TAM_NOME];
    char cpf[TAM_CPF];
    char telefone[TAM_TEL];
    double saldo;
};


int buscaConta(struct Conta vc[], int qtd, int n_conta);
void cadastraConta(struct Conta vc[], int *qtd);
void consultaSaldo(struct Conta vc[], int qtd);
void deposito(struct Conta vc[], int qtd);
void saque(struct Conta vc[], int qtd);
void listarContas(struct Conta vc[], int qtd);
void receberString(char s[], int t);
int opcaoConta();


int main(){
    struct Conta correntes[TAM_CONTA];
    struct Conta poupancas[TAM_CONTA];

    int opcao, opcao_conta, num_conta, indice;
    int qtd_corrente = 0, qtd_poupanca = 0;


   do{
    printf("==================== MENU ====================\n");
    printf("1. Buscar\n2. Cadastrar\n3. Depositar\n4. Sacar\n5. Saldo\n6. Listar\n0. Sair\n");
    printf("==============================================\n");
    printf("Informe a opcao:\n");
    scanf("%d", &opcao);


    if(opcao == 1){
        opcao_conta = opcaoConta();
        printf("Informe numero conta:\n");
        scanf("%d", &num_conta);
         
        if(opcao_conta == 1){
            indice = buscaConta(correntes, qtd_corrente, num_conta);

            if(indice >= 0){
                printf("\n==============================================\n");
                printf("Conta localizada!\n");
                printf("==============================================\n");
                printf("N° Conta: %d\n", correntes[indice].num);
                printf("Tilular: %s\n", correntes[indice].nome);
                printf("Telefone: %s\n", correntes[indice].telefone);
                printf("==============================================\n");
            }
        }else if(opcao_conta == 2){
            indice = buscaConta(poupancas, qtd_poupanca, num_conta);

            if(indice >= 0){
                printf("\n==============================================\n");
                printf("Conta localizada!\n");
                printf("==============================================\n");
                printf("N° Conta: %d\n", poupancas[indice].num);
                printf("Tilular: %s\n", poupancas[indice].nome);
                printf("Telefone: %s\n", poupancas[indice].telefone);
                printf("==============================================\n");
            }
        }


        if(indice == -2){
            printf("\n==============================================\n");
            printf("Conta nao localizada\n");
            printf("==============================================\n");
        
        }else if(indice == -1){
            printf("\n==============================================\n");
            printf("Nenhuma conta cadastrada\n");
            printf("==============================================\n");
        }

        // printf("_________________________________________________________\n");
        // printf("\n****************************************\n");
        printf("**********************************************\n");
        continue;

    }else if(opcao == 2){
        opcao_conta = opcaoConta();

        if(opcao_conta == 1){
            cadastraConta(correntes, &qtd_corrente);
        }else if(opcao_conta == 2){
            cadastraConta(poupancas, &qtd_poupanca);
        }

        // printf("_________________________________________________________\n");
        printf("**********************************************\n");
        continue;
        

    }else if(opcao == 3){
        opcao_conta = opcaoConta();

        if(opcao_conta == 1){
            deposito(correntes, qtd_corrente);
        }else if(opcao_conta == 2){
            deposito(poupancas, qtd_poupanca);
        }

        // printf("_________________________________________________________\n");
        printf("**********************************************\n");
        continue;

        
    }else if(opcao == 4){
        opcao_conta = opcaoConta();

        if(opcao_conta == 1){
            saque(correntes, qtd_corrente);
        }else if(opcao_conta == 2){
            saque(poupancas, qtd_poupanca);
        }

        // printf("_________________________________________________________\n");
        printf("**********************************************\n");
        continue;
        
    }else if(opcao == 5){
        opcao_conta = opcaoConta();

        if(opcao_conta == 1){
            consultaSaldo(correntes, qtd_corrente);
        }else if(opcao_conta == 2){
            consultaSaldo(poupancas, qtd_poupanca);
        }

        // printf("_________________________________________________________\n");
        printf("**********************************************\n");
        continue;
        
    }else if(opcao == 6){
        opcao_conta = opcaoConta();

        if(opcao_conta == 1){
            printf("LISTA CONTAS CORRENTES:\n");
            listarContas(correntes, qtd_corrente);
        }else if(opcao_conta == 2){
            printf("LISTA CONTAS POUPANCAS:\n");
            listarContas(poupancas, qtd_poupanca);
        }

        // printf("_________________________________________________________\n");
        printf("**********************************************\n");
        continue;
        
    }else if(opcao == 0){
        printf("Finalizando...\n");
        break;
        
    }else{
        printf("\n==============================================\n");
        printf("Opcao Invalida\n");
        printf("==============================================\n");
        continue;
    }

   }while(opcao != 0);


    return 0;
}

int opcaoConta(){
    int opcao_conta;

    do{
        printf("============= Informe tipo conta =============\n");
        printf("1. Corrente\n2. Poupanca\n");
        printf("==============================================\n");
        printf("Opcao: ");
        scanf("%d", &opcao_conta);

        if(opcao_conta != 1 && opcao_conta != 2){
            printf("\n==============================================\n");
            printf("Opcao invalida.\n");
            printf("==============================================\n");
            continue;
        }

    }while(opcao_conta != 1 && opcao_conta != 2);

    return opcao_conta;
}


int buscaConta(struct Conta vc[], int qtd, int n_conta){
    int i;

    if(qtd == 0){
        return -1;
    }

    for(i = 0; i < qtd; i += 1){
        if(vc[i].num == n_conta){
            return i;
        }
    }
   
    return -2;
}

void cadastraConta(struct Conta vc[], int *qtd){
    int n, pos;

    if(*qtd >= TAM_CONTA){
        printf("\n==============================================\n");
        printf("Vetor cheio!\n");
        printf("==============================================\n");
        return;
    }


    printf("Informe numero conta:\n");
    scanf("%d", &n);

    getchar(); //limpar enter do buffer do teclado

    pos = buscaConta(vc, *qtd, n);

    if(pos >= 0){
        printf("\n==============================================\n");
        printf("Conta ja cadastrada.\n");
        printf("==============================================\n");
        return;
    }

    vc[*qtd].num = n;

    printf("Nome:\n");
    receberString(vc[*qtd].nome, TAM_NOME);

    printf("CPF:\n");
    receberString(vc[*qtd].cpf, TAM_CPF);

    printf("Telefone:\n");
    receberString(vc[*qtd].telefone, TAM_TEL);

    printf("Saldo:\n");
    scanf("%lf", &vc[*qtd].saldo);

    *qtd += 1;

    printf("\n==============================================\n");
    printf("Cadastro realizado com sucesso!\n");
    printf("==============================================\n");

    getchar(); // limpar enter do buffer do teclado
   
}


void consultaSaldo(struct Conta vc[], int qtd){
    int n, pos;

    printf("Informe numero conta:\n");
    scanf("%d", &n);

    pos = buscaConta(vc, qtd, n);

    if(pos < 0){
        printf("\n==============================================\n");
        printf("Conta nao cadastrada.\n");
        printf("==============================================\n");
        return;
    }

    printf("\n==============================================\n");
    printf("Saldo: R$%.2lf\n", vc[pos].saldo);
    printf("==============================================\n");

}


void deposito(struct Conta vc[], int qtd){
    int n, pos;
    double valor;

    printf("Informe numero conta:\n");
    scanf("%d", &n);

    pos = buscaConta(vc, qtd, n);

    if(pos < 0){
        printf("\n==============================================\n");
        printf("Conta nao cadastrada.\n");
        printf("==============================================\n");
        return;
    }

    do{
        printf("Valor deposito R$:\n");
        scanf("%lf", &valor);

        if(valor <= 0.00){
            printf("\n==============================================\n");
            printf("Valor invalido\n");
            printf("==============================================\n");
            continue;
        }

        vc[pos].saldo += valor;
        printf("\n==============================================\n");
        printf("Deposito realizado com sucesso.\n");
        printf("==============================================\n");
        break;

    }while(valor <= 0.00);

}




void saque(struct Conta vc[], int qtd){
    int pos, n;
    double valor;

    printf("Informe numero conta:\n");
    scanf("%d", &n);

    pos = buscaConta(vc, qtd, n);

    if(pos < 0){
        printf("\n==============================================\n");
        printf("Conta nao cadastrada\n");
        printf("==============================================\n");
        return;
    }

    do{
        printf("Valor saque R$:\n");
        scanf("%lf", &valor);

        if(valor <= 0.00){
           printf("\n==============================================\n");
            printf("Valor invalido\n");
            printf("==============================================\n");
            continue;
        }

        if(valor > vc[pos].saldo){
            printf("\n==============================================\n");
            printf("Saldo insuficiente\n");
            printf("==============================================\n");
            continue;
        }

        vc[pos].saldo -= valor;
        printf("\n==============================================\n");
        printf("Saque realizado com sucesso.\n");
        printf("==============================================\n");
        break;

    }while(valor <= 0.00 || valor > vc[pos].saldo);

}


void listarContas(struct Conta vc[], int qtd){
    int i;

    // printf("_________________________________________________________\n");
    printf("\n==============================================\n");

    for(i = 0; i < qtd; i += 1){
        printf("N° conta: %d\n", vc[i].num);
        printf("Titular: %s\n", vc[i].nome);
        printf("Telefone: %s\n", vc[i].telefone);
        // printf("_________________________________________________________\n");
        printf("==============================================\n");

    }

}


void receberString(char s[], int t){
    int tam;

    fgets(s, t, stdin);

    tam = strlen(s);

    if(tam > 0 && s[tam - 1] == '\n'){
        s[tam - 1] = '\0';
    }
}