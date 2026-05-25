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


// 3ª Questão: Faça um programa para criar três vetores de 5 números inteiros, A, B e C. Os vetores A e B devem ser preenchidos
// com valores digitados pelo usuário. O programa deve calcular a soma dos vetores A e B e armazenar o re sultado no vetor C. Ao
// final, o programa deverá exibir o conteúdo do vetor C
void somarVetores(int A[], int B[], int C[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        C[i] = A[i] + B[i];
    }
}


// 4ª Questão: Faça um programa para criar um vetor VET de 100 números reais. O vetor VET deve ser preenchido com valores
// informados pelo usuário. O programa deve calcular e exibir a soma dos elementos do vetor. 
int somarValoresVetor(int V[], int t){
    int i;
    int soma = 0;

    for(i = 0; i < t; i += 1){
        soma += V[i];
    }

    return soma;
}

// 5ª Questão: Altere o programa da questão anterior para exibir as somas parciais a cada 10 elementos lidos.
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


// 2ª Questão: Faça um programa para criar dois vetores de 10 números inteiros, A e B. O programa deve preencher o vetor A com
// valores digitados pelo usuário. O vetor B deve ser preenchido da seguinte forma: os elementos de índice par são os correspondentes
// de A divididos por 2 e os elementos de índice ímpar são os correspondentes de A multiplicados por 3. Ao final, o programa deverá
// exibir os dois vetores (A e B).

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


// 9ª Questão: Faça um programa para criar e preencher um vetor de 10 números reais. O programa deve percorrer o vetor e
// determinar qual a maior diferença entre dois elementos consecutivos.

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




// 8ª Questão: Faça um programa para criar e preencher um vetor de 10 números inteiros. O programa deve percorrer o vetor e
// determinar qual o maior e o menor elemento.
void maiorMenorVetor(int v[], int t){
    int i, menor = 0, maior = 0;

    for(i = 0; i < t; i += 1){
        if(v[i] < menor){
            menor = i;
        }
        if(v[i] > maior){
            maior = i;
        }
    }

    printf("Maior: %d\nMenor: %d\n", v[maior], v[menor]);
}


// 6ª Questão: No colégio Minha Escolinha a média de um aluno em uma disciplina é calculada da seguinte forma: (prime ira nota * 2
// + segunda nota * 3) / 5. Faça um programa para ler a primeira e a segunda nota dos alunos de uma turma de 20 alunos, e calcular e
// exibir a média de cada aluno. O programa deve utilizar três vetores: um para as primeiras notas, um para as segundas notas e um
// outro para as médias.

void receberNotas(double N1[], double N2[], int t){
    int i = 0;

    for(i = 0; i < t; i += 1){
        do{
            printf("Aluno %d - 1° Nota [0.00 - 10.00]:\n", i + 1);
            scanf("%lf", &N1[i]);

            if(N1[i] > 10.00 || N1[i] < 0.00){
                printf("Nota invalida. Digite novamente!\n");
            }

        }while(N1[i] > 10.00 || N1[i] < 0.00);


        do{
            printf("Aluno %d - 2° Nota [0.00 - 10.00]:\n", i + 1);
            scanf("%lf", &N2[i]);

            if(N2[i] > 10.00 || N2[i] < 0.00){
                printf("Nota invalida. Digite novamente!\n");
            }

        }while(N2[i] > 10.00 || N2[i] < 0.00);
    }

}


void calcularMediaPorAluno(double N1[], double N2[], double M[], int t){
    int i;
    double media = 0.00;

    for(i = 0; i < t; i += 1){
        media = ((N1[i] * 2) + (N2[i] *3)) / 5;
        M[i] = media;
    }
}


// 7ª Questão: Altere o programa da questão anterior para que o mesmo calcule a média da turma. O novo programa deve calcular e
// exibir quantos alunos tiverammédia abaixo da média da turma.
double mediaTurma(double M[], int t){
    double soma = 0.00;
    int i;

    for(i = 0; i < t; i += 1){
        soma += M[i];

    }

    return soma / t;
}

void mediaMenorMediaDaTurma(double M[], double mediaTurma, int t){
    int i;
    int qtd = 0;

    for(i = 0; i < t; i += 1){
        if(M[i] < mediaTurma){
            printf("Aluno %d - Media: %.2lf\n", i + 1, M[i]);
            qtd += 1;
        }
    }

    printf("Quantidade de alunos abaixo da media da turma: %d\n", qtd);
}