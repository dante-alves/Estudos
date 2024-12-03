#include <stdio.h>
#include <locale.h>

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	int a, b, c;
	
	printf ("Insira o tamanho de um lado da figura geométrica: ");
	scanf ("%d", &a);
	printf ("Insira o tamanho do segundo lado: ");
	scanf ("%d", &b);
	printf ("Agora, o valor do terceiro lado: ");
	scanf ("%d", &c);
	
	if (a + b > c && b + c > a && a + c > b) {
		printf ("\nA figura é um triângulo ");
		if (a == b && b == c) {
			printf ("Equilátero.\n");
		} else if (a == b || b == c || a == c) {
			printf ("Isósceles.\n");
		} else {
			printf ("Escaleno.\n");
		}
	} else {
		printf ("\n A figura não pode ser um triângulo.");
	}
	return (0);
}
