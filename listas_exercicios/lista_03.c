#include <stdio.h>

#define TAM_MAX 10

int preencherVetores(int A[], int B[]);
void preencherOrdenado(int vetor[], int p, int num);


int main(){
    int vetor_a[TAM_MAX];
    int vetor_b[TAM_MAX];
    int quantidade = 0;

    quantidade = preencherVetores(vetor_a, vetor_b);

    return 0;
}


int preencherVetores(int A[], int B[]){
    int continuar = 1;
    int qtd = 0;
    int num_a, num_b, pos;


    while(continuar && qtd < TAM_MAX){
        printf("Inserir valor em A:\n");
        scanf("%d", &num_a);

        printf("Inserir valor em B:\n");
        scanf("%d", &num_b);

        pos = qtd;

        preencherOrdenado(A, pos, num_a);

        preencherOrdenado(B, pos, num_b);

        qtd += 1;

        if(qtd >= TAM_MAX){
            printf("Vetor cheio\n");
            break;
        }

        printf("Deseja continuar inserindo novos valores?\n1. SIM\n0. NAO\nOpcao: ");
        scanf("%d", &continuar);

    }

    return qtd;

}

void preencherOrdenado(int vetor[], int p, int num){

    while(p > 0 && num < vetor[p - 1]){
        vetor[p] = vetor[p - 1];
        p -= 1;
    }

    vetor[p] = num;
    
}



int uniao(int A[], int B[], int C[], int q){
    int i, t = 0;
    int valor_repetido;

    for(i = 0; i < q; i += 1){
        if(i == 0 ||  i > 0 && A[i] != A[i - 1]){
            C[t] = A[i];
            t += 1;
        }

    }

    for(i = 0; i < q; i += 1){
        valor_repetido = verificarRepeticao(C, B[i], t);
        if(! valor_repetido){
            C[t] = B[i];
            t += 1;

        }
    }
    

    return t;

}


int verificarRepeticao(int C[], int valor_b, int t){
    int i;
    int valor_igual = 0;

    for(i = 0; i < t; i += 1){
        if(valor_b == C[i]){
            valor_igual = 1;
            break;
        }
    }
    return valor_igual;
}


void intersecao(int A[], int B[], int D[], int q){
    int i, j, t = 0;


    for(i = 0; i < q; i += 1){
        if(i > 0 && A[i] == A[i - 1]){
            continue;
        }

        for(j = 0; j < q; j += 1){
            if(A[i] == B[j]){
                D[t] = A[i];
                t += 1;
                break;
            }
        }
    }

    return t;
}



int diferencaAB(int A[], int B[], int E[], int q){
    int i, j, t = 0;
    int repetido = 0;


    for(i = 0; i < q; i += 1){
        for(j = 0; j < q; j += 1){
            if(A[i] == B[j]){
                repetido = 1;
                break;
            }
        }

        if(!repetido){
            E[t] = A[i];
            t += 1;
        }

    }

    return t;

}


int diferencaBA(int A[], int B[], int F[], int q){
    
}


void imprimir(int vetor[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("%d", vetor[i]);

        if(i < t - 1){
            printf(", ");

        }
    }

    printf("\n");

}