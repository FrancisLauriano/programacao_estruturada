#include <stdio.h>

#define LINHA 2
#define COLUNA 2

void inserir(int m[][COLUNA], int l, int c);
void valoresMaioresDez(int m[][COLUNA], int l, int c);

int main(){
    int matriz[LINHA][COLUNA];

    inserir(matriz, LINHA, COLUNA);
    valoresMaioresDez(matriz, LINHA, COLUNA);
    
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


void valoresMaioresDez(int m[][COLUNA], int l, int c){
    int i, j;
    int qtd = 0;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            if(m[i][j] > 10){
                qtd += 1;

            }
        }
    }
    printf("Quantidade de valores maiores que 10: %d\n", qtd);

}