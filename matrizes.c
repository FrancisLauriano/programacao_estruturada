#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define COL 3
#define LIN 3



int main(){
    int matriz[LIN][COL];

    // semente inicial
    srand(time(NULL));
   



    return 0;
}


// receber valores e preencher matriz
void receber(int m[][COL], int l, int c){
    int i, j;


    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            printf("digite [%d][%d] valor:\n", i + 1, j + 1);
            scanf("%d", m[i][j]);
        }
    }
}



// preencher aleatorio a matriz com valores ate 1000
void preencherAleatorio(int m[][COL], int l, int c){
    int i , j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            m[i][j] = rand() % 1000 + 1;
        }
    }

}



// imprimir matriz
void imprimir(int m[][COL], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){

        for(j = 0; j < c; j += 1){
            printf("%d", m[i][j]);
        }
        printf("\n");
    }

}


// somar matriz
void somar(int mA[][COL], int mB[][COL], int mC[][COL], int lA, int cA, int lB, int cB){
    int i, j;
    
    if(lA != lB && cA != cB){
        printf("nao e possive");
    }else{
        for(i = 0; i < lA; i += 1){

            for(j = 0; j < cA; j += 1){
                mC[i][j] = mA[i][j] + mB[i][j];
            }
        }
    }
}


// produto matriz por escalar


// produto de matrizes
void produto(int mA[][COL], int mB[][COL], int mC[][COL], int lA, int cA, int lB, int cB){
    int i, j, k;

    if(cA != lB){
        printf("nao e possive");
    }else{
        for(i = 0; i < lA; i += 1){
            for(j = 0; j < cB; j += 1){

                mC[i][j] = 0;

                for(k = 0; k < cA; k += 1){
                    mC[i][j] += mA[i][k] * mB[k][j];

                }

            }
            
        }
    }
}




// matriz transposta (matriz quadrada)
void transposta(int m[][COL], int l, int c){
    int i, j, aux;

    for(i = 0; i < l; i += 1){

        for(j = i + 1; j < c; j += 1){
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }
}


// matriz transposta (matriz nao quadrada)
void transposta(int m[][COL], int mT[][LIN] , int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){

        for(j = 0; j < c; j += 1){
            mT[j][i] = m[i][j];

        }
    }


}




// maior valor da matriz
void maiorValor(int m[][COL], int l, int c){
    int i, j;
    int maiorI = 0;
    int maiorJ = 0;

    for(i = 0; i < l; i += 1){

        for(j = 0; j < c; j += 1){
            if(m[i][j] > m[maiorI][maiorJ]){
                maiorI = i;
                maiorJ = j;

            }

        }
    }
    printf("maior valor: %d\n", m[maiorI][maiorJ]);
}



// maior valor de cada linha da matriz
void maiorValorLinha(int m[][COL], int l, int c){
    int i, j, maior;

    for(i = 0; i < l; i += 1){
        maior = 0;

        for(j = 0; j < c; j += 1){
            if(m[i][j] > m[i][maior]){
                maior = j;
            }
        }
        printf("Maior valor linha %d: %d\n", i + 1, m[i][maior]);
    }
    
}



// maior valor de cada  coluna da matriz
void maiorValorColuna(int m[][COL], int l, int c){
    int i, j, maior;

    for(j = 0; j < c; j += 1){
        maior = 0;

        for(i = 0; i < l; i += 1){
            if(m[i][j] > m[maior][j]){
                maior = i;
            }
        }
        printf("Maior valor da coluna %d: %d\n", j + 1, m[maior][j]);

    }

}



// matriz triangular superior 
void matrizTriagularSuperior(int m[][COL], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            if(i > j){
                m[i][j] = 0;
            }
        }
    }
}


// matriz triangular inferir



// soma diagonal principal
void diagonalPrincipal(int m[][COL], int l, int c){
    int i, j;
    int soma = 0;

    for(i = 0; i < l; i += 1){

        for(j = 0; j < c; j += 1){
            if(i == j){
                soma += m[i][j];
            }
        }
    }
}




// maior valor da diagonal principal de uma matriz quadrada



// zerar diagonal secundaria de uma matriz quadrada
void matrizSecundaria(int m[][COL], int l, int c){
    int i, j;
    int n = l + 1;

    for(i = 0; i < l; i += 1){

        for(j = 0; j < c; j += 1){
            if(((i + 1) + (j + 1)) == n){
                m[i][j] = 0;
            }
        }
    }

}


// buscar um valor na matriz


// atualizar um valor na matriz



// deletar um valor da matriz
void deletar(int m[][COL], int l, int c, int valor){
    int i, j;

    for(i = 0; i < l; i += 1){

        for(j = 0; j < c; j += 1){
            if(m[i][j] == valor){
                m[i][j] = 0;
                break;
            }

        }
    }

}