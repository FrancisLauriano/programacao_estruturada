#include <stdio.h>

int main(){
    int idade = 0;

    printf("Informe uma idade em anos:\n");
    scanf("%d", &idade);

    if(idade > 60){
        printf("Idoso\n");
    }else if(idade > 32){
        printf("Adulto\n");
    }else if(idade > 18){
        printf("Jovem\n");
    }else if(idade > 12){
        printf("Adolescente\n");
    }else{
        printf("Criança\n");
    }

    return 0;
}