#include <stdio.h>
#include <math.h>

int main () {
	int n1, n2, n3, c1, c2, c3;
	printf ("Digite o primeiro numero: ");
	scanf ("%d", &n1);
	printf ("Digite o segundo numero: ");
	scanf ("%d", &n2);
	printf ("Digite o terceiro numero: ");
	scanf ("%d", &n3);
	if (n1 > n2 && n2 > n3)  //Casos em que n1 é o maior de todos
	{
		printf ("Os numeros em ordem crescente sao: %d, %d e %d.", n3, n2, n1);
	} else if (n1 > n3 && n3 > n2) 
	{
		printf ("Os numeros em ordem crescente sao: %d, %d, %d.", n2, n3, n1);
	} else if (n2 > n1 && n1 > n3) //Casos em que n2 é o maior de todos
	{
		printf ("Os numeros em ordem crescente sao: %d, %d, %d.", n3, n1, n2);
	} else if (n2 > n3 && n3 > n1)
	{
		printf ("Os numeros em ordem crescente sao: %d, %d, %d.", n1, n3, n2);
	} else if (n3 > n1 && n1 > n2) //Casos em que o n3 é o maior de todos
	{
		printf ("Os numeros em ordem crescente sao: %d, %d, %d.", n2, n1, n3);
	} else if (n3 > n2 && n2 > n1)
	{
		printf ("Os numeros em ordem crescente sao: %d, %d, %d.", n1, n2, n3);
	}
}
