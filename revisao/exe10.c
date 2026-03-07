#include <stdio.h>

int main(){
    float valor_moeda;
    int qtd_moeda;


    printf("Digite o valor da moeda:\n");
    scanf("%f", &valor_moeda);

    qtd_moeda = (300 * valor_moeda) / (0.95 * valor_moeda);

    printf("Vale a pena a parti %d moedas\n", qtd_moeda);
  
    return 0;
}