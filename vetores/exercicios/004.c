#include <stdio.h>

#define TAM 8
#define SOMA 2

void receber(int v[], int t);
int buscaBinaria(int v[], int t, int n);
// int soma(int v[], int t, int p1, int p2);
int soma(int v[], int t);


int main(){
    int vetor[TAM];
    int num, pos, soma_n;
    int vetorSoma[SOMA];
    int qtd = 0;
    int i = 0;

    receber(vetor, TAM);

    while(qtd < 2){
        printf("===== SOMA =====\n");
        printf("%d° Valor:\n", i + 1);
        scanf("%d", &num);
        pos = buscaBinaria(vetor, TAM, num);

        if(pos == -1){
            printf("Valor não encontrado.\nInforme um valor valido\n");
            continue;
        }else{
            vetorSoma[i] = num;
            qtd += 1;
            i += 1;
        }
    }

    soma_n = soma(vetorSoma, SOMA);
    printf("===== RESULTADO DA SOMA =====\n");
    printf("%d\n", soma_n);

    return 0;
}


void receber(int v[], int t){
    int i;

    for(i = 0; i < t; i+= 1){
        printf("Digite o %d° valor:\n", i + 1);
        scanf("%d", &v[i]);
    }
}


int buscaBinaria(int v[], int t, int n){
    int pos = - 1;
    int inicio = 0;
    int fim = t - 1;
    int meio;

    do{
        meio = (inicio + fim)/2;

        if(v[meio] > n){
            fim = meio - 1;
        }else{
            inicio = meio + 1;
        }
    }while(v[meio] != n && inicio <= fim);

    if(v[meio] == n){
        pos = meio; 
    }
    return pos;
}


int soma(int v[], int t){
    int i;
    int soma = 0;

    for(i = 0; i < t; i += 1){
        soma += v[i];

    }
    return soma;
}