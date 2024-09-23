#include <stdio.h>
#include <math.h>

int main () {
	int a, b, c;
	for (c = 1; c <= 5; c++) 
	{
	
		printf ("Insira dois valores inteiros e positivos: ");
		scanf ("%d %d", &a, &b);
		
		if (a < b) //Quando a for menor que b
		{
		
			printf ("Os valores pares entre o intervalo de %d e %d sao: ", a, b);
			for (a; a <= b; a++)
			{
				if (a % 2 == 0) {
					printf ("%d ", a);
				}
			}
		} else // quando b for menor que a
		{
			printf ("Os valores pares entre o intervalo de %d e %d sao: ", b, a);
			for (b; b <= a; b++)
			{
				if (b % 2 == 0) {
					printf ("%d ", b);
				}
			}	
		}
		printf ("\n-----------------------------------------------------------------------------\n");
	}
}
