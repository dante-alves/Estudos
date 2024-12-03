#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX10 - Guardando migalhas

int main () {
	setlocale (LC_ALL, "Portuguese");

	int i, centDia, soma = 0;

	centDia = 1;
	for (i = 1; i <= 30; i++) {
		soma += centDia;
		centDia *= 2; 
	}
	float reais = (float)soma / 100; 
	printf ("Ganha um total de %.2f reais.", reais);
}
