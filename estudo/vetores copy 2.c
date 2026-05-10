#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define NUM 5



int main(){
    int vetor[NUM];

    // iniciar semente
    srand(time(NULL));

  


    return 0;
}


// preencher valore vetor
void preencher(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digite o %d° valor:\n", i + 1);
        scanf("%d", &v[i]);
    }
}

// preencher valores aleatorios de 0 a 1000
void preencherAleatorio(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        v[i] = rand() % 1000 + 1;
    }
   
}

// preencher vetor ordenando
void preencherOrdenado(int v[], int t){
    int i, num, pos;


    for(i = 0; i < t; i += 1){
        printf("Digite o %d° valor:\n", i + 1);
        scanf("%d", &num);

        pos = i;

        while(pos > 0 && v[pos - 1] > num){
            v[pos] = v[pos - 1];
            pos -= 1;
        }

        v[pos] = num;
    }
}


// ordenar vetor bubble sort
void bubbleSort(int v[], int t){
    int i, aux;
    int troca = 1;


    while(troca){
        troca = 0;

        for(i = 0; i < t - 1; i += 1){
            if(v[i] > v[i + 1]){
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                troca = 1;
            }
        }
        t -= 1;
    }
}


// ordenar  vetor insert sort
void insertSort(int v[], int t){
    int i, j, aux;

    for(i = 0; i < t; i += 1){
        j = i;
        aux = v[j];

        while(j > 0 && aux < v[j - 1]){
            v[j] = v[j - 1];
            j -= 1;
        }
        v[j] = aux;
    }

}


// ordenar vetor  select sort
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


// busca sequencial em vetor
int buscaSequencial(int v[], int t, int valor){
    int i;
    int pos = -1;

    for(i = 0; i < t; i += 1){
        if(v[i] = valor){
            pos = i;
            break;
        }
    }
    return pos;
}


// busca binaria em vetor (so da para usar se vetor estiver ordenado)
int buscaBinaria(int v[], int t, int valor){
    int meio;
    int pos = -1;
    int inicio = 0;
    int fim = t - 1;

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


// atualizar valor em vetor
void atualizar(int v[], int t, int valor, int novoValor){
    int i;
    int status = 0;

    for(i = 0; i < t; i += 1){
        if(v[i] == valor){
            v[i] = novoValor;
            status = 1;
            break;
        }
    }

    if(status){
        printf("Valor atualizado com sucesso\n");
    }else{
        printf("Nao foi possivel atualizar\n");
    }
}




// deletar valor em vetor
int deletar(int v[], int t, int valor){
    int i, j;

    for(i = 0; i < t; i += 1){
        if(v[i] == valor){
            for(j = i; j < t - 1; j += 1){
                v[j] = v[j + 1];
            }
            i -= 1;
            t -= 1;
        }
    }
    return t;
}

// quais valores tem repeticoes no vetor no vetor ordenado
void valoresRepetido(int v[], int t){
    int i, j;
    int repetido;
    int status = 0;

    bubbleSort(v, t);

    printf("Valores repetidos:\n");

    for(i = 0; i < t; i += 1){
        if(i > 0 && v[i] == v[i - 1]){
            continue;
        }
        
        repetido = 0;

        for(j = i + 1; j < t; j += 1){
            if(v[i] == v[j]){
                repetido = 1;
                break;
            }
        }

        if(repetido){
            status = 1;
            printf("%d\n", v[i]);
        }
    }

    if(status == 0){
        printf("Nenhum valor repetido\n");

    }
}

// quantidade de cada valor num vetor ordenado
void qtdDeCadaValor(int v[], int t){
    int i, j;
    int qtd;

    bubbleSort(v, t);    

    printf("Quantidade de cada valor:\n");
    for(i = 0; i < t; i += 1){
        if(i > 0 && v[i] == v[i - 1]){
            continue;
        }

        qtd = 0;

        for(j = i; j < t; j += 1){
            if(v[j] == v[i]){
                qtd += 1;
            }
        }
        printf("Valor '%d': %d qtd\n", v[i], qtd);
    }
}


// exluir valores repetivos num vetor ordenado
int excluirValoresRepetidos(int v[], int t){
    int i, j, k;

    bubbleSort(v, t);   

    for(i = 0; i < t; i += 1){
        if(i > 0 && v[i] == v[i - 1]){
            continue;
        }

        for(j = i + 1; j < t; j += 1){
            if(v[i] == v[j]){
                for(k = j; k < t - 1; k += 1){
                    v[k] = v[k + 1];
                }
                j -= 1;
                t -= 1;
            }
        }
    }
    return t;
}



// maior valor do vetor
void maiorValor(int v[], int t){
    int i;
    int maior = 0;

    for(i = 1; i < t; i += 1){
        if(v[i] > v[maior]){
            maior = i;
        }
    }

    printf("Maior valor: %d\n", v[maior]);
}


// menor valor do vetor
void menorvalor(int v[], int t){
    int i;
    int menor = 0;

    for(i = 1; i < t; i += 1){
        if(v[i] < v[menor]){
            menor = i;
        }
    }

    printf("Menor valor: %d\n", v[menor]);
}



// primeiros numeros primos
void primeirosNumerosPrimos(int v[], int t){
    int qtd_primos = 0;
    int i = -1;
    int qtd_divisores, j;
    int num = 2;

    while(qtd_primos < t){
        qtd_divisores = 0;

        for(j = 1; j <= num; j += 1){
            if(num % j == 0){
                qtd_divisores += 1;
            }
        }

        if(qtd_divisores == 2){
            i += 1;
            v[i] = num;
            qtd_primos += 1;
        }

        num += 1;
    }
}


// quais numeros primos do vetor ordenado
void quaisNumerosPrimos(int v[], int t){
    int i, j;
    int qtd_divisores;
    int status = 0;

    bubbleSort(v, t);   

    printf("Numeros primos:\n");

    for(i = 0; i < t; i += 1){
        if(i > 0 && v[i] == v[i - 1]){
            continue;
        }

        qtd_divisores = 0;

        for(j = 1; j <= v[i]; j += 1){
            if(v[i] % j == 0){
                qtd_divisores += 1;
            }
        }

        if(qtd_divisores == 2){
            printf("%d\n", v[i]);
            status = 1;

        }
    }

    if(status == 0){
        printf("Nenhum numero primo encontrado\n");
    }

}



// qtd numeros primos do vetor
void qtdNumerosPrimos(int v[], int t){
    int i, j;
    int qtd_divisores;
    int qtd_primos = 0;

    for(i = 0; i < t; i += 1){
        qtd_divisores = 0;

        for(j = 1; j <= v[i]; j += 1){
            if(v[i] % j == 0){
                qtd_divisores += 1;
            }
        }

        if(qtd_divisores == 2){
            qtd_primos += 1;

        }

    }
    printf("Quantidade de primos: %d\n", qtd_primos);
}



// primeiros numeros perfeitos
void primeirosNumerosPerfeitos(int v[], int t){
    int i = -1;
    int soma, j;
    int qtd_perfeitos = 0;
    int num = 2;


    while(qtd_perfeitos < t){
        soma = 0;
        
        for(j = 1; j < num; j += 1){
            if(num % j == 0){
                soma += j;
            }
            
        }

        if(num == soma){
            i += 1;
            v[i] = num;
            qtd_perfeitos += 1;
        }

        num += 1;
    }
}


// quais numeros perfeitos do vetor ordenado
void quaisNumerosPerfeitos(int v[], int t){
    int i, j;
    int soma;
    int status = 0;

    bubbleSort(v, t);   

    printf("Numeros perfeitos:\n");

    for(i = 0; i < t; i += 1){
        if(i > 0 && v[i] == v[i - 1]){
            continue;
        }

        soma = 0;

        for(j = 1; j < v[i]; j += 1){
            if(v[i] % j == 0){
                soma += j;
            }
        }

        if(v[i] == soma){
            printf("%d\n", v[i]);
            status = 1;
        }
    }

    if(status == 0){
        printf("nenhum numero perfeito encontrado\n");

    }

}


// qtd numeros perfeitos do vetor
void qtdNumerosPerfeitos(int v[], int t){
    int i, j;
    int soma;
    int qtd_perfeitos = 0;

    for(i = 0; i < t; i += 1){
        soma = 0;

        for(j = 1; j < v[i]; j += 1){
            if(v[i] % j == 0){
                soma += j;
            }
        }

        if(soma == v[i]){
            qtd_perfeitos += 1;
        }
    }

    printf("Quantidade de numeros perfeitos: %d\n", qtd_perfeitos);
}


// mdc


// mmc


// Escreva um programa que leia um numero inteiro positivo ´ n e em seguida imprima n
// linhas do chamado Triangulo de Pascal: