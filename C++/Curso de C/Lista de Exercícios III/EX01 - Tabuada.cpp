#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX 01 - Tabuada

int main () {
	setlocale(LC_ALL, "Portuguese");
	int num, i, tab;
	
	printf ("Escolha um número entre 1 e 10 para ver a tabuada: ");
	scanf ("%d", &num);
	
	while (num < 1 || num > 10) {
		printf ("O número não está entre o intervalo permitido de 1 e 10. Insira um novo valor: ");
		scanf ("%d", &num);
	}
	
	printf ("-----------------------------------\n");
	printf ("TABUADA DO %d\n", num);
	printf ("-----------------------------------\n");
	for (i = 1; i <= 10; i++) {
		tab = num * i;
		printf ("%d X %d = %d\n", num, i, tab);
	}
}
