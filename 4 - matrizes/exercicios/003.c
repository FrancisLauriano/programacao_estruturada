#include <stdio.h>

#define LINHA 4
#define COLUNA 4

void produto(int m[][COLUNA], int l, int c);
void imprimir(int m[][COLUNA], int l, int c);

int main(){
    int matriz[LINHA][COLUNA];
    
    produto(matriz, LINHA, COLUNA);
    imprimir(matriz, LINHA, COLUNA);

   
    return 0;
}


void produto(int m[][COLUNA], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            m[i][j] = i * j;
        }
    }
}

void imprimir(int m[][COLUNA], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
