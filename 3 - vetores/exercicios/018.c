#include <stdio.h>

#define TAM 5

void receber(int v[], int t);
void contarMultiplos(int v[], int t, int x);

int main(){
    int vetor[TAM];
    int valor;

    receber(vetor, TAM);

    printf("Informe o valor:\n");
    scanf("%d", &valor);

    contarMultiplos(vetor, TAM, valor);

   
    return 0;
}


void receber(int v[], int t){
    int i;

    for(i = 0; i < t; i +=1 ){
        printf("%d° valor:\n", i+1);
        scanf("%d", &v[i]);
    }
}

void contarMultiplos(int v[], int t, int x){
    int i;
    int qtd = 0;

    for(i = 0; i < t; i +=1 ){
        if(v[i] % x == 0){
            printf("%d\t", v[i]);
            qtd += 1;

        }
        
    printf("\n");

    }
    if(qtd == 0){
        printf("Multiplo não encontrado");

    }else{
        printf("Qtd multiplos de %d: %d", x, qtd);
    }
    
    
}
