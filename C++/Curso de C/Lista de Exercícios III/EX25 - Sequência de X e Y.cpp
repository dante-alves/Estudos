#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX25 - Sequ�ncia de X e Y

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	int c, i;
	
	printf ("Insira dois valores: ");
	scanf ("%d %d", &c, &i);
	
	while (c < 1 || i < 1) {
		printf ("Valores inv�lidos. Insira dois valores acima de 1: ");
		scanf ("%d %d", &c, &i);
	}
	
	//In�cio da opera��o
	int Y = 1;
	while (Y <= i) {
		//Fazer com que Y seja printado a quantidade de vezes que for determinado por X para pular a linha
		for (int X = 1; X <= c; X++) {
			printf ("%d ", Y);
			Y++;
		}
		printf ("\n");
	}
}
