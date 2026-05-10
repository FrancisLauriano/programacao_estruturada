#include <stdio.h>
#define COL 3
#define LIN 3

void receber(int m[][COL], int l, int c);
void imprimir(int m[][COL], int l, int c);
void matrizTriangularSuperior(int m[][COL], int l, int c);
void zerarDiagonaPrincipal(int m[][COL], int l, int c);
void zerarDiagonaSecundaria(int m[][COL], int l, int c);

int main(){
    int matriz[LIN][COL];

    receber(matriz, LIN, COL);
    imprimir(matriz, LIN, COL);


    // matrizTriangularSuperior(matriz, LIN, COL);
    // zerarDiagonaPrincipal(matriz, LIN, COL);
    zerarDiagonaSecundaria(matriz, LIN, COL);

    printf("\n\n");

    imprimir(matriz, LIN, COL);


    


    return 0;
}


// receber matriz
void receber(int m[][COL], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            printf("Inserir o valor[%d][%d]:\n", i+1, j+1);
            scanf("%d", &m[i][j]);
        }
    }
}



// imprimir matriz
void imprimir(int m[][COL], int l, int c){
    int i, j;

    printf("[ ");
    for(i = 0; i < l; i += 1){
        printf("[ ");
        for(j = 0; j < c; j += 1){
            printf("%3d", m[i][j]);

            if(j < c - 1){
                printf(", ");

            }
        }
        printf(" ]");
        if(i < l - 1){
            printf("\n");
        }
    }
    printf(" ]");
    printf("\n");

}




// soma matrizes
void soma(int m1[][COL], int m2[][COL], int s[][COL], int l1, int c1, int l2, int c2){
    int i, j;

    if(l1 != l2 && c1 != c2){
        printf("Nao e possivel somar\n");

    }else{
        for(i = 0; i < l1; i += 1){
            for(j = 0; j < c2; j += 1){
                s[i][j] = m1[i][j] + m2[i][j];

            }
        }

    }
}


//produto matriz por escalar
void matrizPorEscalar(int m[][COL], int n, int l, int c){

    int i, j;

    for(i = 0; i < l; i += 1){
        for(j  = 0; j < c; j += 1){
            m[i][j] = n * m[i][j];

        }
    }

} 

// produto matrizes
void produtoMatrizes(int m1[][COL], int m2[][COL], int m3[][COL], int l1, int c1, int l2, int c2){
    int i, j, k;

    if(c1 != l2){
        printf("Nao e possivel realizar produto das matrizes\n");
    }else{
        for(i = 0; i < l1; i += 1){

            for(j = 0; j < c2; j += 1){
                m3[i][j] = 0;

                for(k = 0; k < c1; k += 1){
                    m3[i][j] =+ m1[i][k] * m2[k][j];
                }

            }
        }
    }

}


// matriz transposta quadrada
void transpostaQuadrada(int m[][COL], int l, int c){
    int i, j, aux;

    for(i = 0; i < l; i += 1){
        for(j = i + 1; j < c; j += 1){
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }



}

// matriz transposta matriz nao quadrada
void transposta(int m1[][COL], int m2[][LIN], int l1, int c1, int l2, int c2){
    int i, j;

    if(c2 != l1 || c1 != l2){
        printf("Nao e possivel fazer a transposta\n");
    }else{
        for(i = 0; i < l1; i += 1){
            for(j = 0; j < c1; j += 1){
                m2[j][i] = m1[i][j];

            }
        }
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

// matriz triangular inferior




// maior valor matriz

// menor valor matriz

// zerar diagonal principal
void zerarDiagonaPrincipal(int m[][COL], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){

        for(j = 0; j < c; j += 1){
            if(i == j){
                m[i][j] = 0;

            }

        }
    }

}


// zerar diagonal secundaria
void zerarDiagonaSecundaria(int m[][COL], int l, int c){
    int i, j;
    int n =  l + 1;

    for(i = 0; i < l; i += 1){

        for(j = 0; j < c; j += 1){

            if( ((i + 1) + (j + 1)) == n){
                m[i][j] = 0;

            }
           

        }
    }

}



// buscar valor na matriz
void buscarValor(int m[][COL], int l, int c, int valor){
    int i, j;
    int pos = 0;
 
  
    for(i = 0; i < l; i += 1){
       
        for(j = 0; j < c; j += 1){
            if(m[i][j] == valor){
               pos = 1;
               break; 
            }

        }
    }
    
    if(pos == 0){
        printf("Valor nao encontrado\n");

    }else{
        printf("Valor encontrado\n");

    }
}

// atualizar matriz 
void atualizarValor(int m[][COL], int l, int c, int valor, int novo_valor){
    int i, j;
    int pos = 0;
 
  
    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            if(m[i][j] == valor){
                m[i][j] = novo_valor;
                pos = 1;
                break;
            }
        }
    }

    if(pos == 0){
        printf("Nao foi possivel atualizar\n");
    }else{
        printf("Atualizado com sucesso\n");
    }
}

// deletar um valor da matriz
void deletarValor(int m[][COL], int l, int c, int valor){
    int i, j;
    int pos = 0;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            if(m[i][j] == valor){
                m[i][j] = 0;
                pos = 1;
            }

        }
    }

    if(pos == 0){
        printf("Nao foi possivel excluir\n");
    }else{
        printf("Excluido com sucesso\n");

    }
    
}
