#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX09 - Soma de 1 a N

int main () {
	setlocale (LC_ALL, "Portuguese");
	
	int i, A = 0, N;
	
	printf("Digite um valor maior que 0: ");
	scanf("%d", &N);
	
	while (N < 1) {
		printf("Valor inválido. Digite outro valor: ");
		scanf("%d", &N);
	}
	
	printf ("A = ");
	for (i = 1; i <= N; i++) {
		 A += i;
		 if (i == N) {
		 	printf ("%d = %d\n", i, A);
		 } else {
		 	printf ("%d + ", i);
		 }
	}
}

