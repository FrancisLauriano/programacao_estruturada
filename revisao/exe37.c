#include <stdio.h>
#include <string.h>

void filtraVogal(char* string);

int main(){
    char palavra[100];


    printf("Palavra:\n");
    scanf("%s", palavra);

    filtraVogal(palavra);

    return 0;
}

void filtraVogal(char* string){
    int i;

    for(i = 0; string[i] != '\0'; i += 1){
        if(strchr("aeiouAEIOU", string[i]) == NULL){
            printf("%c", string[i]);
        }
    }
    printf("\n");
}