#include <stdio.h>

//Corre��o do c�digo e explica��o do que ele faz
//O c�digo define a vari�vel numero, pede um valor, e o recebe na vari�vel numero. Por fim, ele apresenta na tela o valor inserido em numero.

int main() {
	int numero = 0;
	
	printf("Informe o valor de um numero: ");
	
	scanf("%d", &numero);
	
	printf("O numero informado foi %d", numero);
	
	return 0;
}
