#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX23 - Triângulo Retângulo

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	for (int i = 1; i <= 8; i++) {
		for (int c = 1; c <= i; c++) {
			printf ("*");
		}
		printf ("\n");
	}
}
