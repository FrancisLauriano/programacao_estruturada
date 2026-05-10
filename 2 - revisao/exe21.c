#include <stdio.h>
#include <string.h>

int main(){
    char palavra[100];
    int i;

    printf("Digite palavra:\n");
    scanf("%s", palavra);

    for(i = 0; palavra[i] != '\0'; i += 1){
        if(strchr("aeiouAEIOU", palavra[i]) == NULL){
            printf("%c", palavra[i]);
        }
    }

    printf("\n");

    return 0;
}