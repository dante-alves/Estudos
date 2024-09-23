#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX17 - Contador de números positivos e negativos

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	int n = 1, positivo = 0, negativo = 0;
	
	while (n != 0) {
		printf ("Digite um valor (0 para finalizar o contador): ");
		scanf ("%d", &n);
		
		if (n > 0) {
			positivo++;
		} else if (n < 0) {
			negativo++;
		}
	}
		printf ("\nPositivos: %d\n", positivo);
		printf ("Negativos: %d\n", negativo);
}
