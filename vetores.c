#include <stdio.h>
#define QTD_MAX 5
#define IDADE_MIN 0
#define IDADE_MAX 120

int main() {
    int idades[QTD_MAX];
    double soma = 0.0;
    double media = 0.0;

    for(int i = 0; i < QTD_MAX; i += 1) {
        do {
            printf("Digite a idade %dº pessoa:\n", i + 1);
            scanf("%d", &idades[i]);
        }while (idades[i] < IDADE_MIN || idades[i] > IDADE_MAX);
        
        soma += idades[i];

    }
    if (QTD_MAX != 0) {
        media = soma / QTD_MAX;
    }

    for(int i = 0; i < QTD_MAX; i += 1) {
        if (idades[i] >= media) {
            printf("\n%d\n", idades[i]);

        }
        
    }

    


    printf("soma das %d: %.2lf\n", QTD_MAX, soma);
    printf("Media das %d: %.2lf\n", QTD_MAX, media);





    // for(int i = 0; i < QTD_MAX; i += 1) {
    //     printf("\n%d\n", idades[i]);
    // }

    

   


    return 0;
}