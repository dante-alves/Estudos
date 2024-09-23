#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //PERMITE ACENTUAÇÃO

int main () {
	int a, b;
	setlocale(LC_ALL, "Portuguese");//PERMITE ACENTUAÇÃO
	printf ("Estou testando a acentuação, éééé\n");
	
	printf ("Insira dois valores: ");
	scanf ("%d %d", &a, &b);
	
	
	//Trocando valores de variáveis sem uma variável auxiliar
	
	printf ("a vale %d\t b vale %d.\n", a, b);
	
	a = a + b;
	b = a - b;
	a = a - b;
	
	printf ("a vale %d\t b vale %d.\n", a, b);
}
