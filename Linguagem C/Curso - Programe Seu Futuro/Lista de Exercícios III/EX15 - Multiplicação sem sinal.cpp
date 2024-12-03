#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX15 - Multiplicação sem sinal

int main () {
	setlocale (LC_ALL, "Portuguese");
	
	int n1, n2, soma = 0;
	
	printf ("Insira o primeiro valor: ");
	scanf ("%d", &n1);
	printf ("\nInsira o segundo valor: ");
	scanf ("%d", &n2);
	
	for (int i = 1; i <= n2; i++) {
		soma += n1;
	}
	
	printf ("\nA soma é igual a %d.\n", soma);
}
