#include <stdio.h>

int main(){
    int a11, a12, a21, a22, a31, a32;
    int a13 = 1;
    int a23 = 1;
    int a33 = 1;
    int det_a;

    printf("Digite o X1:\n");
    scanf("%d", &a11);
    printf("Digite o Y1:\n");
    scanf("%d", &a12);

    printf("Digite o X2:\n");
    scanf("%d", &a21);
    printf("Digite o Y2:\n");
    scanf("%d", &a22);

    printf("Digite o X3:\n");
    scanf("%d", &a31);
    printf("Digite o Y3:\n");
    scanf("%d", &a32);

    det_a = ((a11 * a22 * a33) + (a12 * a23 * a31) + (a13 * a21 * a32)) - ((a13 * a22 * a31) + (a11 * a23 * a32) + (a12 * a21 * a33));

    if(det_a == 0){
        printf("Determinante: %d\nSão pontos colineares\n", det_a);

    }else{
        printf("Determinante: %d\nNão são pontos colineares\n", det_a);
    }

    return 0;
}