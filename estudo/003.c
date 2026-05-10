#include <stdio.h>

#define MAX 100
#define TRUE 1

void QtdLinhaColuna(int *lA, int *cA, int *lB, int *cB, int n);
void receberMatriz(int mA[][MAX], int mB[][MAX], int lA, int cA, int lB, int cB);
void multiAB(int mA[][MAX], int mB[][MAX], int mM[][MAX], int lA, int cA, int cB);
void imprimir(int mM[][MAX],int lA, int cB);

int main(){
    int linha_A, coluna_A, linha_B, coluna_B;
    int matriz_A[MAX][MAX], matriz_B[MAX][MAX], matriz_Mult[MAX][MAX];

    QtdLinhaColuna(&linha_A, &coluna_A, &linha_B, &coluna_B, MAX);

    receberMatriz(matriz_A, matriz_B, linha_A, coluna_A, linha_B, coluna_B);

    printf("Matriz A:\n");
    imprimir(matriz_A, linha_A, coluna_A);

    printf("Matriz B:\n");
    imprimir(matriz_B, linha_B, coluna_B);

    multiAB(matriz_A, matriz_B, matriz_Mult, linha_A, coluna_A, coluna_B);


    printf("Produto matrizes:\n");
    imprimir(matriz_Mult, linha_A, coluna_B);
    
    return 0;
}


void QtdLinhaColuna(int *lA, int *cA, int *lB, int *cB, int n){

    do{
        printf("Quantidade linha 1º matriz [1 - 100]:\n");
        scanf("%d", lA);
        if(*lA < 1 || *lA > n){
            printf("Valor inválido\n");
            continue;
        }

        printf("Quantidade coluna 1º matriz [1 - 100]:\n");
        scanf("%d", cA);
        if(*cA < 1 || *cA > n){
            printf("Valor inválido\n");
            continue;
        }

        printf("Quantidade linha 2º matriz [1 - 100]:\n");
        scanf("%d", lB);
        if(*lB < 1 || *lB > n){
            printf("Valor Inválido\n");
            continue;
        }
        if(*lB != *cA){
            printf("Qtd colunas de A deve ser igual qtd de linhas B.\n");
            continue;
        }

        printf("Quantidade coluna 2º matriz [1 - 100]:\n");
        scanf("%d", cB);
        if(*cB < 1 || *cB > n){
            printf("Valor inválido\n");
            continue;
        }

        break;

    }while(TRUE);

}

void receberMatriz(int mA[][MAX], int mB[][MAX], int lA, int cA, int lB, int cB){
    int i, j;

    printf("MATRIZ A:\n");
    for(i = 0; i < lA; i += 1){
        for(j = 0; j < cA; j += 1){
            printf("Inserir o valor A[%d][%d] da 1º matriz:\n", i+1, j+1);
            scanf("%d", &mA[i][j]);
        }
    }

    printf("MATRIZ B:\n");
    for(i = 0; i < lB; i += 1){
        for(j = 0; j < cB; j += 1){
            printf("Inserir o valor B[%d][%d] da 2º matriz:\n", i+1, j+1);
            scanf("%d", &mB[i][j]);
        }
    }

}


void multiAB(int mA[][MAX], int mB[][MAX], int mM[][MAX], int lA, int cA, int cB){
    int i, j, k;

    for(i = 0; i < lA; i += 1){
        for(j = 0; j < cB; j += 1){
           mM[i][j] = 0;
           
           for(k = 0; k < cA; k +=1){
            mM[i][j] += mA[i][k] * mB[k][j];

           }
        }
    }
}



void imprimir(int mM[][MAX],int lA, int cB){
    int i, j;
    for(i = 0; i < lA; i += 1){
        for(j = 0; j < cB; j += 1){
            printf("%d\t", mM[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
