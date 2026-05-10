#include <stdio.h>

int main(){

    int i;

    for (i = 1; i <= 10; i += 1){
        printf("%d ", i);

        if (i == 5){
            printf("Parou\n");
            break;
        }
        // printf("%d ", i);
    }

    return 0;
}

