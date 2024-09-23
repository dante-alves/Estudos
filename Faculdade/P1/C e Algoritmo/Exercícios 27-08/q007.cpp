#include <stdio.h>

//Questao 7

int main () {
	int num;
	printf ("Escolha um numero: ");
	scanf ("%d", &num);
	if (num % 2 == 0) 
	{
		printf ("O numero lido foi %d e ele eh PAR!", num);
	}
	else 
	{
		printf ("O numero lido foi %d e ele eh IMPAR!", num);		
	}
}
