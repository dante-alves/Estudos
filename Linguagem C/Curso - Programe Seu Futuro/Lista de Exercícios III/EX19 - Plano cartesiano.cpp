#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX19 - Plano cartesiano

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	int X, Y;
	
	while (1) {
	
		printf ("Insira as coordenadas no plano carsetiano (X Y): ");
		scanf ("%d %d", &X, &Y);
		if (X > 0 && Y > 0) {
			printf ("Primeiro quadrante.\n");
		} else if (X < 0 && Y > 0) {
			printf ("Segundo quadrante.\n");
		} else if (X < 0 && Y < 0) {
			printf ("Terceiro quadrante.\n");
		} else if (X > 0 && Y < 0) {
			printf ("Quarto quadrante.\n");
		} else {
			return 0;
		}
		printf ("\n");
	}
}
