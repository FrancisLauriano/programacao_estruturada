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
void preencher(int m[][COL], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            printf("Digite o valor [%d][%d]:\n", i + 1, i + j);
            scanf("%d", &m[i][j]);
        }
    }
}


// preencher aleatorio a matriz com valores ate 1000
void preencherAleatorio(int m[][COL], int l, int c){
    int i, j;

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
            if(j != c - 1){
                printf(", ");
            }
        }
        printf("\n");
    }
    printf("\n");
}



// somar matriz
void somarMatrizes(int mA[][COL], int mB[][COL], int mC[][COL], int lA, int cA, int lB, int cB){
    int i, j;

    if(lA != lB && cA != cB){
        printf("Nao e possivel somar as matrizes\n");

    }else{
        for(i = 0; i < lA; i += 1){
            for(j = 0; j < cA; j += 1){
                mC[i][j] = mA[i][j] + mB[i][j];
            }
        }
    }
}


// produto matriz por escalar
void produtoMatrizPorEscalar(int m[][COL], int num, int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            m[i][j] = num * m[i][j];
        }
    }
}


// produto de matrizes
void produtoMatrizes(int mA[][COL], int mB[][COL], int mC[][COL], int lA, int cA, int lB, int cB){
    int i, j, k;

    if(cA != lB){
        printf("Nao e possivel realizar o produtos entre as matrizes\n");
    }else{
        for(i = 0; i < lA; i += 1){
            for(j = 0; j < cB; j += 1){
                mC[i][j] = 0;
                for(k = 0; k < cA; k += 1){
                    mC[i][j] =+ mA[i][k] * mB[k][j];

                }
            }
        }
    }
}


// matriz transposta (matriz quadrada)
void matrizQuadradaTransposta(int m[][COL], int l, int c){
    int i, j, aux;

    for(i = 0; i < l; i += 1){
        for(j = i + 1; j < c; j += 1){

            m[i][j] = aux;
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }
}

// matriz transposta (matriz nao quadrada)
void matrizNaoQuadradaTransposta(int m[][COL], int mT[][LIN], int l, int c){
    int i, j, aux;

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
    printf("Maior valor da matriz: %d\n", m[maiorI][maiorJ]);
}




// maior valor de cada linha da matriz
void maiorValorPorLinha(int m[][COL], int v[], int l, int c){
    int i, j, maior;

    for(i = 0; i < l; i += 1){
        maior = 0;

        for(j = 1; j < c; j += 1){
            if(m[i][j] > m[i][maior]){
                maior = j;
            }
        }
        v[i] = m[i][maior];
    }
}



// maior valor de cada  coluna da matriz
void maiorValorPorColuna(int m[][COL], int v[], int l, int c){
    int i, j, maior;

    for(j = 0; j < c; j += 1){
        maior = 0;
        for(i = 1; i < l; i += 1){
            if(m[i][j] > m[maior][j]){
                maior = i;
            }
        }
        v[j] = m[maior][j];
    }
}


// matriz triangular superior 
void matrizTriangularSuperior(int m[][COL], int l, int c){
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
void matrizTriangularInferior(int m[][COL], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            if(i < j){
                m[i][j] = 0;
            }
        }
    }
}


// soma diagonal principal
void somaDiagonalPrincipal(int m[][COL], int l, int c){
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
void maiorValorDiagonalPrincipal(int m[][COL], int l, int c){
    int i, j;
    int maiorI = 0;
    int maiorJ = 0;

    for(i = 1; i < l; i += 1){
        for(j = 1; j < c; j += 1){
            if(i == j && m[i][j] > m[maiorI][maiorJ]){
                maiorI = i;
                maiorJ = j;
            }
        }
    }
    printf("Maior valor da diagonal principal: %d\n", m[maiorI][maiorJ]);
}


// zerar diagonal secundaria de uma matriz quadrada
void zerarDiagonalSecundaria(int m[][COL], int l, int c){
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