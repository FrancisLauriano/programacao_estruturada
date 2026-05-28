#include <stdio.h>
#include <string.h>

#define TAM 100

struct Categoria {
    int codigo;
    char nome[50];
};

struct Produto {
    int codigo;
    char titulo[100];
    char descricao[256];
    int categoria; // código da categoria que está no vetor categorias
    int preco; // representa um valor numérico com 2 casas decimais
};


void receberString(char c[], int t);
void cadastrarCategoria(struct Categoria v[], int *qtd);
void imprimirCategorias(struct Categoria v[], int qtd);
void imprimirProdutos(struct Produto vp[], int qtdProdutos, struct Categoria vc[], int qtdCategorias);
void selectionSortPorDescricao(struct Produto v[], int qtd);
void buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x);



int main(){

    struct Categoria categorias[TAM];
    struct Produto produtos[TAM];

    int qtdCategorias = 0;
    int qtdProdutos = 3;

    char descricaoBusca[256];


    
    cadastrarCategoria(categorias, &qtdCategorias);

    produtos[0].codigo = 1;
    strcpy(produtos[0].titulo, "Mouse");
    strcpy(produtos[0].descricao, "Mouse gamer");
    produtos[0].categoria = categorias[0].codigo;
    produtos[0].preco = 15000;

    produtos[1].codigo = 2;
    strcpy(produtos[1].titulo, "Teclado");
    strcpy(produtos[1].descricao, "Teclado mecanico");
    produtos[1].categoria = categorias[1].codigo;
    produtos[1].preco = 25000;

    produtos[2].codigo = 3;
    strcpy(produtos[2].titulo, "Monitor");
    strcpy(produtos[2].descricao, "Monitor ultrawide");
    produtos[2].categoria = categorias[0].codigo;
    produtos[2].preco = 120000;

    imprimirCategorias(categorias, qtdCategorias);

    selectionSortPorDescricao(produtos, qtdProdutos);

    imprimirProdutos(produtos, qtdProdutos, categorias, qtdCategorias);

    printf("Informe descricao para busca:\n");
    receberString(descricaoBusca, 256);

    buscaBinariaPorDescricao(produtos, qtdProdutos, descricaoBusca);


    return 0;
}


// QUESTÃO 1:
void cadastrarCategoria(struct Categoria v[], int *qtd){
    int cod, i, repetido;

    if(*qtd >= TAM){
        printf("Vetor sem espaco.\n");
        return;
    }

    do{
        printf("CADASTRO\n");
        printf("Informe codigo:\n");
        scanf("%d", &cod);

        repetido = 0;

        for(i = 0; i < *qtd; i += 1){
            if(v[i].codigo == cod){
                printf("Codigo cadastrado. Informe codigo valido\n");
                repetido = 1;
                break;
            }
            
        }
    }while(repetido == 1);

    v[*qtd].codigo = cod;

    getchar();

    printf("Informe nome:\n");
    receberString(v[*qtd].nome, 50);

    *qtd += 1;
    
    printf("Cadsatro realizado com sucesso!\n");

}



// QUESTAO 2:
void imprimirCategorias(struct Categoria v[], int qtd){
    int i;

    printf("----------------------------------------\n");
    printf("CATEGORIAS\n");
    printf("----------------------------------------\n");
    for(i = 0; i < qtd; i += 1){
        printf("Codigo: %d\n", v[i].codigo);
        printf("Nome: %s\n", v[i].nome);
        printf("----------------------------------------\n");

    }
}


// QUESTAO 3:
void imprimirProdutos(struct Produto vp[], int qtdProdutos, struct Categoria vc[], int qtdCategorias){
    int i, j;

    printf("----------------------------------------\n");
    printf("PRODUTOS\n");
    printf("----------------------------------------\n");
    
    for(i = 0; i < qtdProdutos; i += 1){
        printf("Codigo: %d\n", vp[i].codigo);
        printf("Titulo: %s\n", vp[i].titulo);
        printf("Descricao: %s\n", vp[i].descricao);

        for(j = 0; j < qtdCategorias; j += 1){
            if(vc[j].codigo == vp[i].categoria){
                printf("Categoria: %s\n", vc[j].nome);
                break;
            }
        }

        printf("Preco:  R$ %.2lf\n", (double)vp[i].preco / 100);

        printf("----------------------------------------\n");
    }
}


// QUESTAO 4:
void selectionSortPorDescricao(struct Produto v[], int qtd){
    int i, j, menor;
    struct Produto aux;

    for(i = 0; i < qtd - 1; i += 1){
        menor = i;

        for(j = i + 1; j < qtd; j += 1){
            if(strcmp(v[j].descricao, v[menor].descricao) < 0){
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

// QUESTAO 5:
void buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x){
    int inicio = 0;
    int fim = qtd - 1;
    int meio;

    do{
        meio = (inicio + fim) / 2;

        if(strcmp(v[meio].descricao, x) < 0){
            inicio = meio + 1;
        }else{
            fim = meio - 1;
        }


    }while(strcmp(v[meio].descricao, x) != 0 && inicio <= fim);

    if(strcmp(v[meio].descricao, x) == 0){
        printf("Descricao encontrada no produto codigo: %d\n", v[meio].codigo);
        return;
    }

    printf("Descricao nao localizada\n");
}


// funcoes auxilires
void receberString(char c[], int t){
    int tam;

    fgets(c, t, stdin);
    tam = strlen(c);

    if(tam > 0 && c[tam - 1] == '\n'){
        c[tam - 1] = '\0';
    }
}
