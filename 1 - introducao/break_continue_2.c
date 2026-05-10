#include <stdio.h>

int main(){

    int i;

    for (i = 1; i <= 10; i += 1){
        if(i == 5){
            printf(" [Ignora o 5] ");
            continue;
        }
        
        printf("%d ", i);
    }

    return 0;
}

