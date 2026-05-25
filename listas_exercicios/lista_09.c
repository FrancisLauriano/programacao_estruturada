#include <stdio.h>

#define LIN 2
#define COL 2


void receber(int m[][COL], int l, int c);
void transposta(int M[][COL], int MT[][LIN], int l, int c);
void imprimirT(int m[][LIN], int l, int c);
void imprimir(int m[][COL], int l, int c);

void matrizSimetrica(int M[][COL], int l, int c);

int main(){
    int M1[LIN][COL];
    // int M2[COL][LIN];

    receber(M1, LIN, COL);

    // transposta(M1, M2, LIN, COL);

    printf("Matriz:\n");
    imprimir(M1, LIN, COL);

    // printf("Matriz Transposta:\n");
    // imprimirT(M2, COL, LIN);


    matrizSimetrica(M1, LIN, COL);

    return 0;
}



void transposta(int M[][COL], int MT[][LIN], int l, int c){
    int i, j;


    for(i = 0; i < l; i += 1){

        for(j = 0; j < c; j += 1){
            MT[j][i] = M[i][j];
        }
    }
}


void transpostaMatrizQuadrada(int M[][COL], int l, int c){
    int i, j, aux;

    for(i = 0; i < l; i += 1){

        for(j = i + 1; j < c; j += 1){
            aux = M[i][j];
            M[i][j] = M[j][i];
            M[j][i] = aux;
        }
    }
}


void receber(int m[][COL], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            printf("Informe o valor[%d][%d]:\n", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

void imprimir(int m[][COL], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

void imprimirT(int m[][LIN], int l, int c){
    int i, j;

    for(i = 0; i < l; i += 1){
        for(j = 0; j < c; j += 1){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

void matrizSimetrica(int M[][COL], int l, int c){
    int i, j;
    int eh_simetrica;

    if(l != c){
        printf("Nao e simetrica\n");
        return;

    }else{
        eh_simetrica = 1;

        for(i = 0; i < l; i += 1){
            for(j = 0; j < c; j += 1){
                if(M[i][j] != M[j][i]){
                    eh_simetrica = 0;
                    break;
                }
            }
        }

        if(!eh_simetrica){
            printf("Nao e simetrica\n");
        }else{
            printf("E simetrica\n");
        }

    }

}