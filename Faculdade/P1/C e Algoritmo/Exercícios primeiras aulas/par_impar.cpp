#include <stdio.h>
#include <locale.h>

int main () {
	setlocale (0, "Portuguese");
	int num;
	printf ("Escolha um n�mero: ");
	scanf ("%d", &num);
	if (num % 2 == 0) 
	{
		printf ("O n�mero lido foi %d e ele � PAR!", num);
	}
	else 
	{
		printf ("O n�mero lido foi %d e ele � IMPAR!", num);		
	}
}
