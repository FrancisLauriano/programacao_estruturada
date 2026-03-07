#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(){
    int ano, mes, dia;

    printf("Infome o ano no formado XXXX:\n");
    scanf("%d", &ano);

    printf("Infome o mês no formado XX:\n");
    scanf("%d", &mes);

    do{
        printf("Infome o dia no formado XX:\n");
        scanf("%d", &dia);

        if(mes == 2){
            if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0){
                if(dia <= 0 || dia > 29){
                    printf("Dia Inválido!\n");
                    continue;  
                }else{
                    break;
                }   
            }else{
                if(dia <= 0 || dia > 28){
                    printf("Dia Inválido!\n");
                    continue;   
                }else{
                    break;
                }
            }
        }else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 11){
            if(dia <= 0 || dia > 31){
                printf("Dia Inválido!\n");
                continue; 
            }else{
                break;
            }
        }else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
            if(dia <= 0 || dia > 30){
                printf("Dia Inválido!\n");
                continue; 
            }else{
                break;
            }
        }else{
            printf("Mês inválido!\n");
            printf("Infome o mês no formado XX:\n");
            scanf("%d", &mes);
        }
    
    }while(TRUE);
   
    return 0;
}