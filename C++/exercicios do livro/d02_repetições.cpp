#include <stdio.h>
#include <math.h>

int main () {
	
	int N, c, i, j;
	float  fat, E;
	
	printf ("Escolha um valor inteiro positivo para a operacao: ");
	scanf ("%d", &N);
	
	E = 1;
	
	for (c = 1; c <= N; c++) 
	{
		/*Forma menos indicada de calcular o fatorial que eu fiz
		fat = c;
		for (j = c; j > 1; j--) //
		{ 
			i = j - 1;
			fat *= i;
		}
		*/
		//Forma mais indicada
		fat = 1;
		for (j = 1; j <= c; j++) 
		{
			fat *= j;
		}
		E = E + (1/fat); 
		printf ("%f\n", E);
	}
}
