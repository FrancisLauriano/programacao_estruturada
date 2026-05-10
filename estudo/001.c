#include <stdio.h>

#define LINHA 2
#define COLUNA 3

void receberMatriz(int mA[][COLUNA], int mB[][COLUNA], int l, int c);
void somaMatrizes(int mA[][COLUNA], int mB[][COLUNA], int mS[][COLUNA],int l, int c);
void imprimirSoma(int mS[][COLUNA],int l, int c);

int main(){
    int matA[LINHA][COLUNA], matB[LINHA][COLUNA], matSoma[LINHA][COLUNA];
    receberMatriz(matA, matB, LINHA, COLUNA);
    somaMatrizes(matA, matB, matSoma, LINHA, COLUNA);
    printf("Resultado soma:\n");
    imprimirSoma(matSoma, LINHA, COLUNA);


    return 0;
}


void receberMatriz(int mA[][COLUNA], int mB[][COLUNA], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            printf("Inserir o valor [%d][%d] da 1º matriz:\n", i+1, j+1);
            scanf("%d", &mA[i][j]);
        }
    }


    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            printf("Inserir o valor [%d][%d] da 2º matriz:\n", i+1, j+1);
            scanf("%d", &mB[i][j]);
        }
    }

}

void somaMatrizes(int mA[][COLUNA], int mB[][COLUNA], int mS[][COLUNA],int l, int c){
    int i, j;
    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            mS[i][j] = mA[i][j] + mB[i][j];
        }
    }

}

void imprimirSoma(int mS[][COLUNA],int l, int c){
    int i, j;
    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            printf("%d\t", mS[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}