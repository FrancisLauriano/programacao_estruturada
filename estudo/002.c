#include <stdio.h>
#define NUM 2

void receberMatriz(int m[][NUM], int l, int c);
void transposta(int m[][NUM], int l, int c);
void imprimir(int mS[][NUM],int l, int c);


int main(){
    int matriz[NUM][NUM];


    receberMatriz(matriz, NUM, NUM);
    printf("Matriz Original:\n");
    imprimir(matriz, NUM, NUM);

    transposta(matriz, NUM, NUM);

    printf("Matriz Transposta:\n");
    imprimir(matriz, NUM, NUM);



    return 0;
}


void receberMatriz(int m[][NUM], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            printf("Inserir o valor [%d][%d] da matriz:\n", i+1, j+1);
            scanf("%d", &m[i][j]);
        }
    }

}

void transposta(int m[][NUM], int l, int c){
    int i, j, aux;

    for(i = 0; i < l; i += 1){
        for(j = i + 1; j < c; j += 1){
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
            
        }
    }
}


void imprimir(int mS[][NUM],int l, int c){
    int i, j;
    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            printf("%d\t", mS[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}