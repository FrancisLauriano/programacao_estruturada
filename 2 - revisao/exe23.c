#include <stdio.h>
#include <string.h>

int main(){
    char palavra[100];
    int i;
    int soma = 0;

    printf("Digite a palavra:\n");
    scanf("%s", palavra);

    for(i = 0; palavra[i] != '\0'; i += 1){
        if(strchr("aA", palavra[i]) != NULL){
            soma += 1;
        }
    }

    printf("Soma: %d\n", soma);

    return 0;
}