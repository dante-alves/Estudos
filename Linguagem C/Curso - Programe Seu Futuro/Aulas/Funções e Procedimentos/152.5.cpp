#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Aula 152.5 - Como transformar texto em n�mero

int main() {
	setlocale(0, "Portuguese");
	
	int num;
	char palavra[20] = {'5'};
	
	num = palavra[0]; //Uma forma aqui
	
	printf("%d", palavra[0] - '0'); //Outra forma aqui, subtrair o caracter do n�mero pelo caracter do n�mero '0', que equivale a 48.
	printf("\n%c", num);
	
	return 0;
} 
