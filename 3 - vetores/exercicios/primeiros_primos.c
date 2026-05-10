#include <stdio.h>

#define TAM 5

#define LIN 5
#define COL 5

int mains(){



    return 0;
}


//1. inserir os cinco primeiros primos no vetor;
void primos(int v[], int t){
    int qtd_div, i;
    int qtd_primos = 0;
    int num = 2;
    int j = 0;
    int eh_primo;

    while(qtd_primos < t){
        qtd_div = 0;

        for(i = 1; i <= num; i += 1){
            if(num % i == 0){
                qtd_div += 1;
            }
        }

        eh_primo = 0;

        if(qtd_div == 2){
            qtd_primos += 1;
            eh_primo = 1;
        }

        if(eh_primo){
            v[j] = num;
            j += 1;
        }

        num += 1;
    }
}


// 2. maior valor por linha da matriz
void maiorValorLinhaMatriz(int m[][COL], int l, int c, int v[], int t){
    int i, j;
    int maiorJ;


    for(i = 0; i < l && i < t; i += 1){
        maiorJ = 0;

        for(j = 0; j < c; j += 1){

            if(m[i][j] > m[i][maiorJ]){
                maiorJ = j;
            }  
        }

        v[i] = m[i][maiorJ];
       

    }
 
}


// 4. maior valor por coluna da matriz
void maiorValorLinhaMatriz(int m[][COL], int l, int c, int v[], int t){
    int i, j;
    int maiorI;

    maiorI = 0;

    for(i = 0; i < l && i < t; i += 1){

        for(j = 0; j < c; j += 1){

            if(m[i][j] > m[maiorI][j]){
                maiorI = i;
            }  
        }

        v[i] = m[maiorI][j];
    }
}

// 5. inverter cada palavra da string
void invertePalavra(char frase[], int t){
    int i = 0;
    int inicio, fim, j;

    while(frase[i] != '\0'){

        while(frase[i] == ' '){
            printf(" ");
            i += 1;

        }

        inicio = i;


        while(frase[i] != ' ' && frase[i] != '\0'){
            i += 1;

        }

        fim = i - 1;


        for(j = fim; j >= inicio; j -= 1){
            printf("%c", frase[j]);

        }
        

    }

}