#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //PERMITE ACENTUA��O

int main () {
	int a, b;
	setlocale(LC_ALL, "Portuguese");//PERMITE ACENTUA��O
	printf ("Estou testando a acentua��o, ����\n");
	
	printf ("Insira dois valores: ");
	scanf ("%d %d", &a, &b);
	
	
	//Trocando valores de vari�veis sem uma vari�vel auxiliar
	
	printf ("a vale %d\t b vale %d.\n", a, b);
	
	a = a + b;
	b = a - b;
	a = a - b;
	
	printf ("a vale %d\t b vale %d.\n", a, b);
}
