#include <stdio.h>

#define TAMANHO 5

int main(){


    return 0;
}

// inserir
void inserirValores(int v[], int tam){
    int i;
    for(i = 0; i < tam; i += 1){
        printf("Inserir o %d° valor:\n", i+1);
        scanf("%d", &v[i]);
    }
}

// imprimir
void imprimir(int v[], int tam){
    int i;
    for(i = 0; i < tam; i += 1){
        printf("%d\t", v[i]);
    }
    printf("\n");
}

// ordenação bubble sort
void bubbleSort(int v[], int tam){
    int i, aux;
    int troca = 1;

    while(troca){
        troca = 0;

        for(i = 0; i < tam -1; i += 1){
            if(v[i] > v[i + 1]){
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
            }
        }
        tam -= 1;
    }

}

// ordenação insert sort
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

// ordenação select sort
void selectSort(int v[], int tam){
    int i, j, menor, aux;

    for(i = 0; i < tam; i += 1){
        menor = i;

        for(j = i + 1; j < tam; j += 1){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;

    }

}


// busca sequencial
int buscaSequencial(int v[], int tam, int n){
    int i;
    int pos = -1;
    for(i = 0; i < tam; i += 1){
        if(v[i] == n){
            pos = i;
        }
    }
    
    return pos;
}

// busca binaria
int buscaBinaria(int v[], int tam, int n){
    int meio;
    int inicio = 0;
    int fim = tam - 2;
    int pos = -1;

    do{
        meio = (inicio + fim ) / 2;

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

// atualizar
int atualizar(int v[], int tam, int n, int n2){
    int i, result;

    for(i = 0; i < tam; i += 1){
        if(v[i] == n){
            v[i] = n2;
            result = i;
        }else{
            result = -1;
        }
    }
    return result;

}

// deletar
int deletar(int v[], int tam, int n){
    int i, j;

    for(i = 0; i < tam; i += 1){

        if(v[i] == n){

            for(j = i; j < tam - 1; j += 1){
                v[j] = v[j + 1];

            }
            tam -= 1;
        }
    }
    return tam;

}


// Inserir
// imprimir
// busca sequencial
// busca binaria
// atualizar
// deletar
// ordenação bubble sort
// ordenação insert sort
// ordenação select sort