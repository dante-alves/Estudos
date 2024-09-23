#include <stdio.h>
#include <locale.h>

int main () {
	setlocale (0, "Portuguese");
	int num;
	printf ("Escolha um número: ");
	scanf ("%d", &num);
	if (num % 2 == 0) 
	{
		printf ("O número lido foi %d e ele é PAR!", num);
	}
	else 
	{
		printf ("O número lido foi %d e ele é IMPAR!", num);		
	}
}
