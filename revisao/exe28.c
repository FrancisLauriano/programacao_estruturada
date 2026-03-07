#include <stdio.h>

int main(){
    int i, c, result;

    for(i = 1; i <= 10; i += 1){
        for(c = 1; c <= 5; c += 1){
            result = c * i;
            printf("%d x %d = %d\t", c, i, result);
        }
        printf("\n");
    }

    printf("\n");

    for(i = 1; i <= 10; i += 1){
        for(c = 6; c <= 10; c += 1){
            result = c * i;
            printf("%d x %d = %d\t", c, i, result);

        }
        printf("\n");
    }

    return 0;
}