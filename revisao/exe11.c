#include <stdio.h>

int main(){
    int a11, a12, a21, a22, det_a;
    float inv_a11, inv_a12, inv_a21, inv_a22;
   

    printf("Digite o a11:\n");
    scanf("%d", &a11);
    printf("Digite o a12:\n");
    scanf("%d", &a12);

    printf("Digite o a21:\n");
    scanf("%d", &a21);
    printf("Digite o a22:\n");
    scanf("%d", &a22);

    det_a = (a11 * a22) - (a12 * a21);

    if(det_a == 0){
        printf("Não é inversivel.\nDeterminate: %d\n", det_a);

    }else{
        inv_a22 = (1 / det_a) * a22; 
        inv_a12 = (1 / det_a) * -a12; 
        inv_a21 = (1 / det_a) * -a21; 
        inv_a11 = (1 / det_a) * a11; 

        printf("Matriz inversivel:\n%.2f\t%.2f\n%.2f\t%.2f\n", inv_a22, inv_a12, inv_a21, inv_a11);
    }

    return 0;
}