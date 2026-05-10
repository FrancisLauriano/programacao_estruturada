#include <stdio.h>

#define LINHA 4
#define COLUNA 4

void inserir(int m[][COLUNA], int l, int c);
void imprimir(int m[][COLUNA], int l, int c);
void maiorValor(int m[][COLUNA], int l, int c);

int main(){
    int matriz[LINHA][COLUNA];

    inserir(matriz, LINHA, COLUNA);
    imprimir(matriz, LINHA, COLUNA);
    maiorValor(matriz, LINHA, COLUNA);

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

void imprimir(int m[][COLUNA], int l, int c){
      int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            printf("%d ", m[l][c]);
        }
        printf("\n");
    }
    printf("\n");
}

void maiorValor(int m[][COLUNA], int l, int c){
    int i, j, maior, maior_l, maior_c;

    maior = m[0][0];
    maior_l = 0;
    maior_c = 0;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            if(m[i][j] > maior){
                maior = m[i][j];
                maior_l = i;
                maior_c = j;
            }
        }
    } 

    printf("Maior valor: %d.\nLinha: %d.\nColuna: %d\n", maior, maior_l + 1, maior_c + 1);
}