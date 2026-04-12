#include <stdio.h>

#define TAM 5

// sem ordenação

void receber(int v[], int t);
void valoresIguais(int v[], int t);



int main(){
    int vetor[TAM];

    receber(vetor, TAM);
    printf("valores iguais:\n");
    valoresIguais(vetor, TAM);
   

    return 0;
}

void receber(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digite %dº valor:\n", i+1);
        scanf("%d", &v[i]);
    }
}

void valoresIguais(int v[], int t){
    int i, j, l;
    int repeticao = 0;
    int ja_verificado;
    int encontrado;

    for(i = 0; i < t; i += 1){
        ja_verificado = 0;
        encontrado = 0;

        for(j = 0; j < i; j += 1){
            if(v[i] == v[j]){
                ja_verificado = 1;
                break;
            }
        }

        if(ja_verificado){
            continue;
        }

        for(l = i + 1; l < t; l += 1){
            if(v[i] == v[l]){
                encontrado = 1;
                break;
            }
        }

        if(encontrado != 0){
            printf("%d ", v[i]);
            repeticao = 1;
        }
    }

    if(repeticao == 0){
            printf("Sem valores repetido.\n");
    }

}

