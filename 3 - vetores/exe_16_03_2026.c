#include <stdio.h>
#define TAMANHO 8

void insertSort(int v[], int tam);
void imprimirValores(int v[], int tam);
void quantidadeValores(int v[], int tam);


int main(){
    int vetor [TAMANHO]= {9, 1, 3, 7, 4, 1, 2, 4}; 
    printf("Antes ordenar:\n");
    imprimirValores(vetor, TAMANHO);

    insertSort(vetor, TAMANHO);
    printf("Apos ordenar:\n");
    imprimirValores(vetor, TAMANHO);

    quantidadeValores(vetor, TAMANHO);
        
    return 0;
}



void insertSort(int v[], int tam){
    int i, j, aux;

    for(i = 1; i < tam; i += 1){


        j = i;
        aux = v[j];
        while(j > 0 && aux < v[j - 1]){
            v[j] = v[j - 1];
            j -= 1;
        }
        v[j] = aux;
    }

}



void quantidadeValores(int v[], int tam){
    int i, j;
    int qtd;


    for(i = 0; i < tam; i += 1){
        if(i > 0 && v[i] == v[i -1]){
            continue;

        }

        qtd = 0;

        for(j = i; j < tam; j += 1){
            if(v[i] == v[j]){
                qtd += 1;
            }
        }

        printf("Numero %d tem: %d repeticoes\n", v[i], qtd);
    }


}




void imprimirValores(int v[], int tam){
    int i;

    for(i = 0; tam > i; i += 1){
        printf("%d\t", v[i]);
    }
    printf("\n");
} 