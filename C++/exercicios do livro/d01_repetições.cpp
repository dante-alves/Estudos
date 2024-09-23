#include <stdio.h>
#include <math.h>

int main () {
	float sal_inicial = 1000, sal_atual, aum_1996, percentual = 0.015;
	aum_1996 = sal_inicial + (sal_inicial * percentual);
	sal_atual = aum_1996;
	for (int ano = 1997; ano <= 2024; ano++) 
	{
		percentual *= 2;
		sal_atual += (sal_atual * percentual);
		printf ("%.2f\n", sal_atual);
	}
}

