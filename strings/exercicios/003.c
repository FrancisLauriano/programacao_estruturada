#include <stdio.h>

#define TAM 21

void receber(char tex[], int t);
void imprimir(char tex[]);

int main(){
    char texto[TAM];

    receber(texto, TAM);
    imprimir(texto);

    return 0;
}

void receber(char tex[], int t){
    int i;
    
    printf("Insira um texto [ate 20 caracteres}:\n");
    fgets(tex, t, stdin);

    for(i = 0; tex[i] != '\0'; i += 1){
        if(i > 0 && tex[i] == '\n'){
            tex[i] = '\0';
            break;
        }
    }
}

void imprimir(char tex[]){
    
    if(tex[0] == 'a' || tex[0] == 'A'){
        printf("%s", tex);

    }else{
        printf("'%s' não começa com a letra 'a'", tex);
    }

}