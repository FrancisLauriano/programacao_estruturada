#include <stdio.h>

int divisaoInteira(int n1, int n2);
int divisaoResto(int n1, int n2);

int main(){
    int num1, num2, divisao, resto_divisao;

    printf("Digite numero 1:\n");
    scanf("%d", &num1);

    printf("Digite numero 2:\n");
    scanf("%d", &num2);

    divisao = divisaoInteira(num1, num2);
    resto_divisao = divisaoResto(num1, num2);
    printf("Divisão inteira entre %d e %d: %d\nResto da divisão: %d\n", num1, num2, divisao, resto_divisao);

    return 0;
}

int divisaoInteira(int n1, int n2){
    int maior, menor;
    int result = 0;

    if(n1 >= n2){
        maior = n1;
        menor = n2;
    }else{
        maior = n2;
        menor = n1;
    }
    
    while(maior >= menor){
        maior -= menor;
        result += 1;
    }

    return result;

}

int divisaoResto(int n1, int n2){
    int maior, menor;

    if(n1 >= n2){
        maior = n1;
        menor = n2;
    }else{
        maior = n2;
        menor = n1;
    }

    while(maior >= menor){
        maior -= menor;
    }
    return maior;
}