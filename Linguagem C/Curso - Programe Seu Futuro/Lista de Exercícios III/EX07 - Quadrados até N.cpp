#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX07 - Quadrados até N

int main () {
	setlocale (LC_ALL, "Portuguese");
	
	int i, N, quadrado;

	printf ("Insira um valor maior que 0: ");
	scanf ("%d", &N);
	
	while (N < 0 ) {
		printf ("Valor inválido. Insira um valor maior que 0: ");
		scanf ("%d", &N);
	}
	
	for (i = 2; i <= N; i += 2) {
		quadrado = i * i;
		printf ("%d\n", quadrado);
	}
}
