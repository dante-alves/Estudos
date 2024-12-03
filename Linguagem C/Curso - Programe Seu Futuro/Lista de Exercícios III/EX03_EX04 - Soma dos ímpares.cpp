#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX03_04 - Soma dos ímpares

int main () {
	setlocale (LC_ALL, "Portuguese");
	
	int i, soma = 0;
	
	for (i = 1; i <= 1000; i += 2) {
		printf ("%d\n", i);
		soma += i;
	}
	printf ("A soma entre todos os números ímpares entre 1 e 1000 é igual a %d", soma);
}
