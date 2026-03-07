
#include <stdio.h>
#include <string.h>

int main(){
    char palavra[100];
    int i;

    printf("Infome uma palavra:\n");
    scanf("%s", palavra);

    for(i = 0; palavra[i] != '\0'; i += 1){
        if(palavra[i] != 'a' &&
           palavra[i] != 'e' &&
           palavra[i] != 'i' &&
           palavra[i] != 'o' &&
           palavra[i] != 'u' &&
           palavra[i] != 'A' &&
           palavra[i] != 'E' &&
           palavra[i] != 'I' &&
           palavra[i] != 'O' &&
           palavra[i] != 'U'){
            printf("%c", palavra[i]);
        }   
    }

    printf("\n");

    return 0;
}