#include <stdio.h>
#include <math.h>

int main () {
	int fat, c, j, n;
	printf ("Indique ate qual valor quer saber o fatorial: ");
	scanf ("%d", &n);

	for (c = 1; c <= n; c++) 
	{
		fat = 1;
		for (j = 1; j <= c; j++) 
		{
			fat *= j;
		}
		printf ("O fatorial de %d e igual a %d\n", c, fat);
	}
}
