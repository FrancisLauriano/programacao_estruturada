#include <stdio.h>
#include <string.h>

#define SENHA_PADRAO "1234"

int main(){
    char senha[5];

    printf("Informe sua senha para logar:\n");
    scanf("%s", senha);

    if(strcmp(senha, SENHA_PADRAO) == 0){
        printf("SENHA VALIDA. ACESSO LIBERADO.\n");
    }else{
        printf("SENHA INVALIDA. ACESSO NEGADO.\n");
    }

    return 0;
}

