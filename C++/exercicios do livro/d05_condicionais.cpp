#include <stdio.h>
#include <math.h>

int main () {
	int n1, n2, n3, n4;
	printf ("Escreva tres numeros em ordem crescente: ");
	scanf ("%d %d %d", &n1, &n2, &n3);
	if (n1 > n2 || n1 > n3 || n2 > n3) 
	{
		printf ("Ordem invalida. Por favor, insira os numeros em ordem crescente.");
		return (0);
	} else;
	printf ("Agora, insira um quarto numero, que nao precisa seguir a ordem dos outros: ");
	scanf ("%d", &n4);

	if (n4 > n3) 
	{
		printf ("Os numeros em ordem decrescente sao: %d, %d, %d, %d.", n4, n3, n2, n1);
		
	} else if (n4 > n2 && n4 < n3)
	{
		printf ("Os numeros em ordem decrescente sao: %d, %d, %d, %d.", n3, n4, n2, n1);
	} else if (n4 > n1 && n4 < n2)
	{
		printf ("Os numeros em ordem decrescente sao: %d, %d, %d, %d.", n3, n2, n4, n1);
	} else if (n4 < n1)
	{
		printf ("Os numeros em ordem decrescente sao: %d, %d, %d, %d.", n3, n2, n1, n4);
	}
}
