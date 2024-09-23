#include <stdio.h>

//Questao 8

int main () {
	int n1, n2, n3, menor;
	/* Tudo de uma vez
	printf ("Insira tres valores: ");
	scanf ("%d %d %d", &n1, &n2, &n3); */
	
	// Um de cada vez
	printf ("Insira o 1 valor: ");
	scanf ("%d", &n1);
	printf ("Insira o 2 valor: ");
	scanf ("%d", &n2);
	printf ("Insira o 3 valor: ");
	scanf ("%d", &n3);
	
	if (n1 < n2 && n1 < n3) {
		menor = n1;
	} else if (n2 < n1 && n2 < n3) {
		menor = n2;
	} else if (n3 < n1 && n3 < n2) {
		menor = n3;
	}
	printf ("O menor valor encontrado foi: %d", menor);
}
