#include <stdio.h>
#include <locale.h>

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	int a, b, c;
	
	printf ("Insira o tamanho de um lado da figura geom�trica: ");
	scanf ("%d", &a);
	printf ("Insira o tamanho do segundo lado: ");
	scanf ("%d", &b);
	printf ("Agora, o valor do terceiro lado: ");
	scanf ("%d", &c);
	
	if (a + b > c && b + c > a && a + c > b) {
		printf ("\nA figura � um tri�ngulo ");
		if (a == b && b == c) {
			printf ("Equil�tero.\n");
		} else if (a == b || b == c || a == c) {
			printf ("Is�sceles.\n");
		} else {
			printf ("Escaleno.\n");
		}
	} else {
		printf ("\n A figura n�o pode ser um tri�ngulo.");
	}
	return (0);
}
