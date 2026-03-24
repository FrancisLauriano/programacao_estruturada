#include <stdio.h>

#define CAPACIDADE_MINIMA 3
#define CAPACIDADE_MAXIMA 50


int tamanhoVetor(int min, int max);
int quatidadeValores(int min, int tam);
void imprimir(int v[], int tam);
void pesquisarUmValor(int v[], int tam);
void inserirOrdenado(int v[], int contador, int valor);
int inserirUmValor(int v[], int tam_atual, int tam_total);
int removerUmValor(int v[], int tam);

int main(){
    int tamanho_total, tamanho_atual, opcao, i, valor;
    int vetor[CAPACIDADE_MAXIMA];

    tamanho_total = tamanhoVetor(CAPACIDADE_MINIMA, CAPACIDADE_MAXIMA);
    tamanho_atual = quatidadeValores(CAPACIDADE_MINIMA, tamanho_total);

    

    for(i = 0; i < tamanho_atual; i += 1){
        printf("\n----------------------------------------------------------------------------\n");
        printf("Informe o %d° valor:\n", i + 1);
        printf("----------------------------------------------------------------------------\n");
        scanf("%d", &valor);
        inserirOrdenado(vetor, i, valor);

    }

    do{
        printf("\n======== MENU ========\n");
        printf("1. Imprimir Vetor\n");
        printf("2. Consultar Valor\n");
        printf("3. Remover Valor\n");
        printf("4. Inserir um Valor\n");
        printf("0. Sair\n");
        printf("======================\n");
        printf("Informe uma opcao desejada entre 0 e 4:\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
            imprimir(vetor, tamanho_atual);
            break;

            case 2:
            pesquisarUmValor(vetor, tamanho_atual);
            break;

            case 3:
            tamanho_atual = removerUmValor(vetor, tamanho_atual);
            break;

            case 4:
            tamanho_atual = inserirUmValor(vetor, tamanho_atual, tamanho_total);
            break;

            case 0:
            printf("\nFinalizando o programa ...\n");
            break;

            default:
            printf("\n----------------------------------------------------------------------------\n");
            printf("Opcao Invalida\n");
            printf("----------------------------------------------------------------------------\n");
            break;
        }   

    }while(opcao != 0);

    return 0;
}


int tamanhoVetor(int min, int max){
    int i, tam;

    do{
        printf("\n----------------------------------------------------------------------------\n");
        printf("Informe o tamanho do vetor entre %d e %d:\n", min, max);
        printf("----------------------------------------------------------------------------\n");
        scanf("%d", &tam);

        if(tam < min || tam > max){
            printf("\n----------------------------------------------------------------------------\n");
            printf("Tamanho invalido!\n");
            printf("----------------------------------------------------------------------------\n");
        }
    }while(tam < min || tam > max);

    return tam;

}


int quatidadeValores(int min, int tam){
    int i, qtd;

    do{
        printf("\n----------------------------------------------------------------------------\n");
        printf("Inserir a quantidade de valores a serem digitados entre %d e %d:\n", min, tam);
        printf("----------------------------------------------------------------------------\n");
        scanf("%d", &qtd);

        if(qtd < min || qtd > tam){
            printf("\n----------------------------------------------------------------------------\n");
            printf("Quantidade Invalida!\n");
            printf("----------------------------------------------------------------------------\n");
        }

    }while(qtd < min || qtd > tam);

    return qtd;

}



void inserirOrdenado(int v[], int contador, int valor){
    int pos = contador;

    while(pos > 0 && v[pos - 1] > valor){
        v[pos] = v[pos - 1];
        pos -= 1;
    }
    v[pos] = valor;
}


int inserirUmValor(int v[], int tam_atual, int tam_total){
    int num;

    if(tam_total > tam_atual){
        printf("\n----------------------------------------------------------------------------\n");
        printf("Informe o valor que deseja inserir:\n");
        printf("----------------------------------------------------------------------------\n");
        scanf("%d", &num);
        inserirOrdenado(v, tam_atual, num);
        tam_atual += 1;
        printf("\n----------------------------------------------------------------------------\n");
        printf("Valor inserido com sucesso!\n");
        printf("----------------------------------------------------------------------------\n");

    }else{
        printf("\n----------------------------------------------------------------------------\n");
        printf("Não é possivel inserir valor.\nVetor cheio!\n");
        printf("----------------------------------------------------------------------------\n");
    }

    return tam_atual;
}



void imprimir(int v[], int tam){
    int i;
    printf("\n-------------------------------- VETOR ----------------------------------------\n");
    for(i = 0; i < tam; i += 1){
        printf("%d\t", v[i]);
    }
    printf("\n-------------------------------------------------------------------------------\n");

}


int buscaBinaria(int v[], int tam, int valor){
    int meio;
    int inicio = 0;
    int fim = tam - 1;
    int pos = -1;

    do{
        meio = (fim + inicio ) / 2;

        if(v[meio] > valor){
            fim = meio - 1;
        }else{
            inicio = meio + 1;
        }
    }while(v[meio] != valor && inicio <= fim);

    if(v[meio] == valor){
        pos = meio;
    }

    return pos;

}

void pesquisarUmValor(int v[], int tam){
    int result, valor;
    printf("\n----------------------------------------------------------------------------\n");
    printf("Digite o valor:\n");
    printf("----------------------------------------------------------------------------\n");
    scanf("%d", &valor);

    result = buscaBinaria(v, tam, valor);

    if(result != -1){
        printf("\n----------------------------------------------------------------------------\n");
        printf("Valor encontrado no indice: %d\n", result);
        printf("----------------------------------------------------------------------------\n");
    }else{
        printf("\n----------------------------------------------------------------------------\n");
        printf("Valor nao encontrado!\n");
        printf("----------------------------------------------------------------------------\n");
    }

}

int remover(int v[], int tam, int valor){
    int i, pos;

    pos = buscaBinaria(v, tam, valor);

    if(pos != -1){
        for(i = pos; i < tam - 1; i += 1){
            v[i] = v[i + 1];
        }
        tam -= 1;
    }
    
    return tam;
}

int removerUmValor(int v[], int tam){

    int novo_tam, valor;

    printf("\n----------------------------------------------------------------------------\n");
    printf("Informe o valor que deseja excluir:\n");
    printf("----------------------------------------------------------------------------\n");
    scanf("%d", &valor);

    novo_tam = remover(v, tam, valor);

    if(novo_tam == tam){
        printf("\n----------------------------------------------------------------------------\n");
        printf("Não foi possivel remover o valor informado!\n");
        printf("----------------------------------------------------------------------------\n");
    }else{
        printf("\n----------------------------------------------------------------------------\n");
        printf("Valor removido com sucesso!\n");
        printf("----------------------------------------------------------------------------\n");
    }

    return novo_tam;
}