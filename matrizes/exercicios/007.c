#include <stdio.h>

#define LINHA 5
#define COLUNA 5

void preencherAutomatico(int m[][COLUNA], int l, int c);
void imprimir(int m[][COLUNA], int l, int c);

int main(){
    int matriz[LINHA][COLUNA];

    preencherAutomatico(matriz, LINHA, COLUNA);
    imprimir(matriz, LINHA, COLUNA);

    return 0;
}



void preencherAutomatico(int m[][COLUNA], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j +=1){
            if(i < j){
                m[i][j] = (2 * i) + (7 * j) - 2;

            }else if(i > j){
                m[i][j] = (4 * (i*i*i)) - (5 * (j*j)) + 1;

            }else{
                 m[i][j] = (3 * (i*i)) - 1;

            }

        }
    }
}


void imprimir(int m[][COLUNA], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1 ){
            printf("%d\t" , m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}