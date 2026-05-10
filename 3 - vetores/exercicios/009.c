#include <stdio.h>

#define TAM 6

void receberPares(int v[], int t);
void imprimir(int v[], int t);


int main(){
    int vetor[TAM];

    receberPares(vetor, TAM);

    printf("Vetor:\n");
    imprimir(vetor, TAM);

    return 0;
}

void receberPares(int v[], int t){
    int qtdPares = 1;
    int i = 0;
    int num;

    do{
        printf("Digite o %d° num par:\n", qtdPares);
        scanf("%d", &num);

        if(num % 2 == 0){
            v[i] = num;
            i += 1;
            qtdPares += 1;
        }else{
            printf("Valor invalido.\nDigite num par.\n");
        }
    }while(qtdPares <= TAM);

}


void imprimir(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("%d\t", v[i]);
    }
    printf("\n");
}