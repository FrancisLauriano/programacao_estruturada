#include <stdio.h>

#define TAM 3

void receberA(int A[], int t);
void processarAB(int A[], int B[], int t);
void imprimir(int V[], int t);


int main(){
    int vetor_a[TAM];
    int vetor_b[TAM];
    int vetor_c[TAM];

    printf("Receber:\n");
    receberA(vetor_a, TAM);

    processarAB(vetor_a, vetor_b, TAM);
    
    printf("Imprimir A:\n");
    imprimir(vetor_a, TAM);

    printf("Imprimir B:\n");
    imprimir(vetor_b, TAM);

    return 0;
}



void receberA(int A[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digitar o %d° valor:\n", i + 1);
        scanf("%d", &A[i]);
    }
}

void receberAB(int A[], int B[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("Digitar o %d° valor A:\n", i + 1);
        scanf("%d", &A[i]);
        printf("Digitar o %d° valor B:\n", i + 1);
        scanf("%d", &B[i]);
    }


}

void somarVetores(int A[], int B[], int C[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        C[i] = A[i] + B[i];
    }
}

int somarValoresVetor(int V[], int t){
    int i;
    int soma = 0;

    for(i = 0; i < t; i += 1){
        soma += V[i];
    }

    return soma;
}


void somarValoresVetor(int V[], int t){
    int i;
    int soma = 0;

    for(i = 0; i < t; i += 1){
        soma += V[i];
        if((i + 1) % 10 == 0){
            printf("Soma parcial: %d\n", soma);

        }
    }
    printf("Soma total: %d\n", soma);
}

void processarAB(int A[], int B[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        if(i % 2 == 0){
            B[i] = A[i] / 2;

        }else{
            B[i] = A[i] * 3;

        }
    }
}


void imprimir(int V[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        printf("%d", V[i]);

        if(i < t - 1){
            printf(", ");
        }

    }
    printf("\n");

}


void diferencaMaior(double v[], int t){
    int i;
    int n1 = 0;
    int n2 = 1;
    double maior_diferenca = v[n1] - v[n2];

    if(maior_diferenca < 0){
        maior_diferenca = v[n2] - v[n1];
    }
    
    for(i = 0; i < t - 1; i += 1){
        if(v[i] - v[i + 1] < 0){
            if(v[i + 1] - v[i] > maior_diferenca){
                maior_diferenca = v[i + 1] - v[i];
                n1 = i;
                n2 = i + 1;
            }
            
        }else{
            if(v[i] - v[i + 1] > maior_diferenca){
                maior_diferenca = v[i] - v[i + 1];
                n1 = i;
                n2 = i + 1;
            }
        }
    }
    printf("Maior diferenca: %lf e %lf\n", v[n1], v[n2]);
}



