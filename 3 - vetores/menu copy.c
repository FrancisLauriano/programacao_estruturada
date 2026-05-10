#include <stdio.h>

#define TAM_MINIMO 3
#define TAM_MAXIMO 50

int main(){
    int tamanho;

    return 0;
}


int tamnhoVetor(int max, int min){
    int i, tam;

    do{
        printf("Informe o tamanho do vetor entre %d e %d:\n", min, max);
        scanf("%d", &tam);

        if(tam < min || tam > max){
            printf("Tamanho inválido!\n");
        }
    }while(tam < min || tam > max);

}

void bubbleSort(int v[], int tam){
    int i, aux;
    int troca = 1;

    while(troca){
        troca = 0;

        for(i = 0; i < tam - 1; i += 1){
            if(v[i] > v[i + 1]){
                v[i] = aux;
                v[i] = v[i + 1];
                v[i + 1] = aux;
                troca = 1;
            }
        }
        troca -= 1;
    }
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


void selectSort(int v[], int tam){
    int i, j, aux, menor;

    for(i = 0; i < tam; i += 1){
        menor = i;

        for(j = i + 1; j < tam; j += 1){
            if(v[j] < menor){
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;

    }
}


void inserirOrdenado(int v[], int contador, int valor){

    int pos = contador;
    
    while(pos > 0 && v[pos - 1] > valor){
        v[pos] = v[pos - 1];
        pos -= 1;
    }
    v[pos] = valor;

}


int inserir(int v[], int tam){
    int i;

    for(i = 0; i < tam; i += 1){
        printf("Digite o %d° valor:\n", i + 1);
        scanf("%d", v[i]);
    }

}



void imprimir(int v[], int tam){
    int i;

    for(i = 0; i < tam; i += 1){
        printf("%d\t", v[i]);
    }
    printf("\n");
}


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

int buscaBinaria(int v[], int tam, int n){
    int meio;
    int inicio = 0;
    int fim = tam - 2;
    int pos = -1;

    do{
        meio = (fim + inicio) / 2;

    if(v[meio] > n){
        fim = meio - 1;
    }else{
        inicio = meio + 1;

    }
    }while(v[meio] != n && inicio <= fim);

    if(v[meio == n]){
        pos = meio;
    }

    return pos;


}

int remover(int v[], int tam, int n){
    int i, j;

    for(i = 0; i < tam; i += 1){

        if(v[i] == n){
            for(j = i; j < tam -1; j += 1){
                v[j] = v[j + 1];
            }
            tam -= 1;
        }
    }
    return tam;
}


int atualizar(int v[], int tam, int n, int novo_n){
    int i;
    int result = -1;

    for(i = 0; i < tam; i += 1){
        if(v[i] == n){
            v[i] = novo_n;
            result = 1;
        }
    }
    return result;
}