#include <stdio.h>
#include <string.h>

#define SENHA_PADRAO "1234"

int main(){
    char senha[5] = "0000";
    
    while(strcmp(senha, SENHA_PADRAO) != 0){
        printf("Digite senha:\n");
        scanf("%s", senha);

        if(strcmp(senha, SENHA_PADRAO) != 0){
            printf("ACESSO NEGADO!\n");
        }
    }

    printf("ACESSO PERMITIDO!\n");
    
    return 0;
}