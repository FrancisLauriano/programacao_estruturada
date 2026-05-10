#include <stdio.h>

#define TAM 5





int main(){
    int vetor[TAM];
    int tamanho;

    return 0;
}

void receber(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digite %dº valor:\n", i+1);
        scanf("%d", &v[i]);
    }
}



int removeRepeticao(int v[], int t){
  int i, j, l, m;
  int ja_encontrou;

  for(i = 0; i < t; i += 1){
    ja_encontrou = 0;

    for(j = 0; j < i; j += 1){
        if(v[i] == v[j]){
            ja_encontrou = 1;
            break;
        }
    }

    if(ja_encontrou){
        continue;
    }

    for(l = i + 1; l < t; l += 1){
        if(v[i] == v[l]){
            for(m = l; m < t - 1; m += 1){
                v[m] =  v[m + 1];
            }
            t -= 1;
        }
    }
  }
  return t;
}


void imprimir(int v[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("%d\t", v[i]);
    }
    printf("\n");
}
