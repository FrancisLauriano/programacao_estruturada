#include <stdio.h>

#define TAM 30
#define NOTA_MINIMA 0.00
#define NOTA_MAXIMA 10.00
#define PESO_1 2
#define PESO_2 3

struct Aluno{
    double nota1;
    double nota2;
    double media;
};

void receberNotas(struct Aluno a[], int t);
void mediaPorAluno(struct Aluno a[], int t);
double mediaDaTurma(struct Aluno a[], int t);
void imprimirNotasMedias(struct Aluno a[], int t, double media_turma);



int main(){
    struct Aluno aluno[TAM];
    double media_geral_turma;

    receberNotas(aluno, TAM);

    mediaPorAluno(aluno, TAM);

    media_geral_turma = mediaDaTurma(aluno, TAM);
    printf("==================================\n");
    printf("Media geral da turma: %.2lf\n", media_geral_turma);
    printf("==================================\n");

    printf("==================================\n");
    printf("Medias maiores que media geral:\n");
    imprimirNotasMedias(aluno, TAM, media_geral_turma);
    printf("==================================\n");

    return 0;
}


void receberNotas(struct Aluno a[], int t){
    int i;

    for(i = 0; i < t; i += 1){

        printf("========== Aluno %d ==========\n", i + 1);

        do{
            printf("Informe a 1° nota [%.2lf - %.2lf]:\n", NOTA_MINIMA, NOTA_MAXIMA);
            scanf("%lf", &a[i].nota1);

            if(a[i].nota1 < NOTA_MINIMA || a[i].nota1 > NOTA_MAXIMA){
                printf("Valor invalido.\n");
            }

        }while(a[i].nota1 < NOTA_MINIMA || a[i].nota1 > NOTA_MAXIMA);

        
        do{
            printf("Informe a 2° nota [%.2lf - %.2lf]:\n", NOTA_MINIMA, NOTA_MAXIMA);
            scanf("%lf", &a[i].nota2);

            if(a[i].nota2 < NOTA_MINIMA || a[i].nota2 > NOTA_MAXIMA){
                printf("Valor invalido.\n");
            }

        }while(a[i].nota2 < NOTA_MINIMA || a[i].nota2 > NOTA_MAXIMA);

    }
}


void mediaPorAluno(struct Aluno a[], int t){
    int i;

    for(i = 0; i < t; i += 1){
        a[i].media = ((a[i].nota1 * PESO_1) + (a[i].nota2 * PESO_2)) / (PESO_1 + PESO_2);
    }
}


double mediaDaTurma(struct Aluno a[], int t){
    int i;
    double soma = 0.00;

    for(i = 0; i < t; i += 1){
        soma += a[i].media;
    }

    return soma / t;
}


void imprimirNotasMedias(struct Aluno a[], int t, double media_turma){
    int i;

    for(i = 0; i < t; i += 1){
        if(a[i].media > media_turma){
            printf("---------- Aluno %d ----------\n", i + 1);
            printf("Nota 1: %.2lf\n", a[i].nota1);
            printf("Nota 2: %.2lf\n", a[i].nota2);
            printf("Media: %.2lf\n", a[i].media);
        }
    }
}