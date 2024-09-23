#include <stdio.h>

//Questao 5

int main () {
	float b, h, A;
	printf ("AREA DE UM TRIANGULO\n");
	printf ("---------------------------\n");
	printf ("Qual a altura do triangulo? ");
	scanf ("%f", &h);
	printf ("E qual a sua base? ");
	scanf ("%f", &b);
	
	A = (b * h)/2;
	
	printf ("A area do triangulo e igual a: %.2f", A);
}
