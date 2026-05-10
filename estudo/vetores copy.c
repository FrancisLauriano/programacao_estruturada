#include <stdio.h>
#define NUM 5

void preencher(int v[], int t);
void preencherOrdenado(double v[], int t);
void imprimir(double v[], int t);
void imprimirComVirgula(int v[], int t);

int main(){
    int vetor[NUM];

    preencher(vetor, NUM);
    imprimirComVirgula(vetor, NUM);


    return 0;
}


void preencher(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("%dº valor:\n", i + 1);
        scanf("%d", &v[i]);
    }
}

void preencherOrdenado(double v[], int t){
    int i, num, pos;

    for(i = 0; i < t; i += 1){
        printf("%d° valor:\n", i + 1);
        scanf("%lf", &num);

        pos = i;

        while(pos > 0 && v[pos - 1] > num){
            v[pos] = v[pos -1];
            pos -= 1;

        }
        v[pos] = num;
    }
}

void imprimir(double v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("%lf\t", v[i]);
    }
    printf("\n");
}

void imprimirComVirgula(int v[], int t){
    int i;
    
    printf("[ ");

    for(i = 0; i < t; i += 1){
        printf("%d", v[i]);
        if(i < t - 1){
            printf(", ");
        }
    }

    printf(" ]");

    printf("\n");
}

void bubbleSort(int v[], int t){
    int i, aux;
    int troca = 1;

    while(troca){
        troca = 0;

        for(i = 0; i < t - 1; i += 1){
            if(v[i] > v[i + 1]){
                aux = v[i];
                v[i] = v[i + 1];
                v[i] = aux;
                troca = 1;
            }
        }
        t -= 1;
    }
}

void insertSort(int v[], int t){
    int i, j, aux;

    for(i = 1; i < t; i += 1){
        j = i;
        aux = v[j];

        while(j > 0 && aux < v[j - 1]){
            v[j] = v[j - 1];
            j -= 1;
        }
        v[j] = aux;
    }
}

void selectSort(int v[], int t){
    int i, j, aux, menor;

    for(i = 0; i < t - 1; i += 1){
        menor = i;

        for(j = i + 1; j < t; j += 1){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

int buscaSequencial(int v[], int t, int valor){
    int i;
    int pos = -1;

    for(i = 0; i < t; i += 1){
        if(v[i] = valor){
            pos = i;
        }
    }

    return pos;
}

int buscaBinaria(int v[], int t, int valor){
    int i, meio;
    int inicio = 0;
    int fim = t - 1;
    int pos = -1;

    do{
        meio = (inicio + fim) / 2;

        if(v[meio] > valor){
            fim = meio - 1;
        }else{
            inicio = meio + 1;

        }

    }while(v[meio] != valor && inicio <= fim);

    if(v[meio] == valor){
        pos = meio;

    }

    return pos;

}

void atualizar(int v[], int t, int valor, int novo_valor){
    int i;

    for(i = 0; i < t; i += 1){
        if(v[i] == valor){
            v[i] = novo_valor;
        }else{
            printf("Nao e possivel atualizar\n");
        }

    }
}

int deletar(int v[], int t, int valor){
    int i, j;

    for(i = 0; i < t; i += 1){
        if(v[i] == valor){
            for(j = i; j < t - 1; j += 1){
                v[j] = v[j + 1];
            }
            t -= 1;
            i -= 1;
        }
    }
    return t;
}

void qtdRepeticao(int v[], int t){
    int i, j;
    int qtd;


    for(i = 0; i < t; i += 1){
        if(i > 0 && v[i] == v[i - 1]){
            continue;
        }

        qtd = 0;

        for(j = i; j < t; j += 1){
            if(v[i] == v[j]){
                qtd += 1;
            }
        }
        printf("Numero %d tem: %d repeticoes\n", v[i], qtd);

    }
}

