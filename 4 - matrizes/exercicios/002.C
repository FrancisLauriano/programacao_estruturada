#include <stdio.h>

#define LINHA 2
#define COLUNA 2

void inserir(int m[][COLUNA], int l, int c);
void diagonal(int m[][COLUNA], int l, int c);
void imprimir(int m[][COLUNA], int l, int c);


int main(){
    int vetor[LINHA][COLUNA];
    // int novo_vetor[LINHA][COLUNA];

    inserir(vetor, LINHA, COLUNA);

    printf("Vetor:\n");
    imprimir(vetor, LINHA, COLUNA);

    diagonal(vetor, LINHA, COLUNA);

    printf("Vetor alterada:\n");
    imprimir(vetor, LINHA, COLUNA);

    return 0;
}


void inserir(int m[][COLUNA], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            printf("Insirir oo valor [%d][%d]:\n", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

void diagonal(int m[][COLUNA], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            if(i == j){
                m[i][j] = 1;
            }else{
                m[i][j] = 0;
            }
        }
    }
}

void imprimir(int m[][COLUNA], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            printf("%d ", m[i][j]);
            
        }
        printf("\n");
    }
    printf("\n");
}