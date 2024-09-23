#include <stdio.h>

//Questao 4

int main () {
	float C, F;
	
	printf ("Insira a temperatura em graus Fahrenheit: ");
	scanf ("%f", &F);
	C = (F-32) * (5.0/9);
	
	printf ("A temperatura em graus Celsius equivale a %.1f.", C);
	
}
