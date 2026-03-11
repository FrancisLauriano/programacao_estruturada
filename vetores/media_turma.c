#include <stdio.h>

#define TAMANHO_LISTA 30
#define PESO_1 2
#define PESO_2 3
#define NOTA_MINIMA 0.00
#define NOTA_MAXIMA 10.00


void inserirNotas(double nota_1[], double nota_2[], int tam);
void calculaMediaPorAluno(double nota_1[], double nota_2[], double medias[], int tam, int p1, int p2);
double calcularMediaGeral(double medias[], int tam);
void imprimirNotasMedia(double nota_1[], double nota_2[], double medias[], int tam, double media_geral);


int main(){
    double nota1[TAMANHO_LISTA];
    double nota2[TAMANHO_LISTA];
    double medias_alunos[TAMANHO_LISTA];
    double media_geral;

    inserirNotas(nota1, nota2, TAMANHO_LISTA);
    calculaMediaPorAluno(nota1, nota2, medias_alunos, TAMANHO_LISTA, PESO_1, PESO_2);
    media_geral = calcularMediaGeral(medias_alunos, TAMANHO_LISTA);

    printf("\n----------------------------------------------------------------\n");
    printf("Media Geral da turma: %.2lf\n", media_geral);
    printf("----------------------------------------------------------------\n");

    printf("\n----------------------------------------------------------------\n");
    printf("Notas e Media dos alunos que estiveram acima da media da turma:\n");
    printf("----------------------------------------------------------------\n");

    imprimirNotasMedia(nota1, nota2, medias_alunos, TAMANHO_LISTA, media_geral);

    return 0;
}


void inserirNotas(double nota_1[], double nota_2[], int tam){
    int i;

    for(i = 0; i < tam; i += 1){
        printf("\n============= Aluno %d =============\n", i + 1);

        do{
            printf("Insirir a 1° nota entre %.2lf - %.2lf:\n", NOTA_MINIMA, NOTA_MAXIMA);
            scanf("%lf", &nota_1[i]);

            if(nota_1[i] < NOTA_MINIMA || nota_1[i] > NOTA_MAXIMA){
                printf("Valor inválido! Digite nota válida!\n");
            }
        }while(nota_1[i] < NOTA_MINIMA || nota_1[i] > NOTA_MAXIMA);
        

        do{
            printf("Insirir a 2° nota entre %.2lf - %.2lf:\n", NOTA_MINIMA, NOTA_MAXIMA);
            scanf("%lf", &nota_2[i]);

            if(nota_2[i] < NOTA_MINIMA || nota_2[i] > NOTA_MAXIMA){
                printf("Valor inválido! Digite valor válido!\n");
            }
        }while(nota_2[i] < NOTA_MINIMA || nota_2[i] > NOTA_MAXIMA);       
    }  
}


void calculaMediaPorAluno(double nota_1[], double nota_2[], double medias[], int tam, int p1, int p2){
    int i;
    double nota1, nota2;

    for(i = 0; i < tam; i += 1){
        nota1 = nota_1[i];
        nota2 = nota_2[i];

        medias[i] = ((nota1 * p1) + (nota2 * p2)) / (p1 + p2);
    }
}


double calcularMediaGeral(double medias[], int tam){
    int i;
    double soma_medias = 0.00;

    for(i = 0; i < tam; i += 1){
        soma_medias += medias[i];
        
    }
    return soma_medias / tam;
}


void imprimirNotasMedia(double nota_1[], double nota_2[], double medias[], int tam, double med_geral){
    int i;

    for(i = 0; i < tam; i += 1){
        if(medias[i] > med_geral){
            printf("Aluno %d:\n", i + 1);
            printf("Nota 1: %.2lf\n", nota_1[i]);
            printf("Nota 2: %.2lf\n", nota_2[i]);
            printf("Media: %.2lf\n", medias[i]);
            printf("\n----------------------------------------------------------------\n");
        }
    }
}