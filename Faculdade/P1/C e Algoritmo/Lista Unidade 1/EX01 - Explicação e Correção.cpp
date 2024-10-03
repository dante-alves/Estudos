#include <stdio.h>

//Correção do código e explicação do que ele faz
//O código define a variável numero, pede um valor, e o recebe na variável numero. Por fim, ele apresenta na tela o valor inserido em numero.

int main() {
	int numero = 0;
	
	printf("Informe o valor de um numero: ");
	
	scanf("%d", &numero);
	
	printf("O numero informado foi %d", numero);
	
	return 0;
}
