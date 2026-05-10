#include <stdio.h>

int main(){
    int num, i, c;

    printf("Numero:\n");
    scanf("%d", &num);

    for(i = 1; num >= i; i += 1){
        for(c = 1; i >= c; c += 1){
            printf("%d ", c);
        }
        printf("\n");
    }

    return 0;
}