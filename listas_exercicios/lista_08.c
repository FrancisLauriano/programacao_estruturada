#include <stdio.h>

#define TAM 10


void preencherVetor(double v[], int *t);
int verificarSeOrdenado(double v[], int t);
void imprimirVetor(double v[], int t);
int buscaSequencial(double v[], double n, int t);
int buscaBinaria(double v[], double n, int t);

int main(){
    double vetor[TAM];
    int tamanho = 0;
    int opcao;
    int eh_ordenado;
    double num;
    int pesquisa;

    
    
    do{
        printf("====================================\n");
        printf("MENU\n");
        printf("1. Inserir\n2. Imprimir\n3. Buscar\n0. Sair\n");
        printf("====================================\n");
        printf("Opcao: ");
        
        scanf("%d", &opcao);


        if(opcao == 1){
            preencherVetor(vetor, &tamanho);
            continue;
        }else if(opcao == 2){
            imprimirVetor(vetor, tamanho);
            continue;
        }else if(opcao == 3){
            printf("Valor a buscar: ");
            scanf("%lf", &num);

            eh_ordenado = verificarSeOrdenado(vetor, tamanho);

            if(eh_ordenado){
                pesquisa = buscaBinaria(vetor, num, tamanho);
            }else{
                pesquisa = buscaSequencial(vetor, num, tamanho);
            }
            
            if(pesquisa == -1){
                printf("Valor nao encontrado\n");
            }else if(pesquisa == - 2){
                printf("Vetor vazio\n");
            }else{
                printf("Encontrado no indice: %d\n", pesquisa);
            }

            continue;
        }else if(opcao == 0){
            printf("Ecerrando...\n");
            break;
        }else{
            printf("Opcao invalida\n");
            continue;
        }

    }while(opcao != 0);


    return 0;
}



void  preencherVetor(double v[], int *t){
    int continuar = 1;
    int eh_ordenado;

    while(continuar && *t < TAM){
        printf("Digite um num:\n");
        scanf("%lf", &v[*t]);
        *t += 1;

        eh_ordenado = verificarSeOrdenado(v, *t);

        if(eh_ordenado){
            printf("==================\nVetor ordenado\n==================\n");
        }else{
            printf("==================\nVetor NAO ordenado\n==================\n");
        }

       if(*t >= TAM){
            printf("Vetor sem espaco\n");
            break;
        }

        do{
            printf("\nDeseja continuar?\n1. SIM\n0. NAO\nOpcao: ");
            scanf("%d", &continuar);
            
            if(continuar != 0 && continuar != 1){
                printf("Opcao invalida\n");
                continue;
            }

        }while(continuar != 0 && continuar != 1);
        

    }
}

int verificarSeOrdenado(double v[], int t){
    int i;
    int ordenado = 1;


    for(i = 0; i < t; i += 1){
        if(i > 0 && v[i] < v[i - 1]){
            ordenado = 0;
            break;
        }
    }
    return ordenado;
}

void imprimirVetor(double v[], int t){
    int i;

    printf("\n");

    for(i = 0; i < t; i += 1){
        printf("%.2lf", v[i]);

        if(i < t - 1){
            printf(", ");
        }
    }

    printf("\n");
}



int buscaSequencial(double v[], double n, int t){
    int i;

    if(t == 0){
        return -2;

    }

    for(i = 0; i < t; i += 1){
        if(v[i] == n){
            return i;
        }
    }
    return -1;
}



int buscaBinaria(double v[], double n, int t){
    int i, meio;
    int inicio = 0;
    int fim = t - 1;

    if(t == 0){
        return -2;

    }
    
    do{
        meio = (inicio + fim) / 2;

        if(v[meio] > n){
            fim = meio - 1;
        }else{
            inicio = meio + 1;
        }

    }while(v[meio] != n && inicio <= fim);

    if(v[meio] == n){
        return meio;
    }else{
        return -1;
    }
}