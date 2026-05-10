#include <stdio.h>

int main(){
	printf("Valor inteiro: %d.\n", 10);
	
	printf("Valor decimal: %f.\n", 3.14141564678);
	
	printf("Valor decimal com duas casas: %.2f.\n", 3.14141564678);
	
	/* Quando usar apenas um caracter (char), o caracter dever� est� dentro de aspas simples (''):*/
	printf("Valor char (um caracter): %c.\n", 'F');
	
	/* Textos (string) dever� ser escrito dentro de aspas duplas (""): */
	printf("Valor string: %s.\n", "Francis.\n");
	
	return 0;
	
}
