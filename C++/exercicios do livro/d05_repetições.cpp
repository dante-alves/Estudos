#include <stdio.h>
#include <math.h>

int main() {
	int c, n, h, maior_h, menor_h, maior_n, menor_n;
	
	maior_h = 0;
	menor_h = 10000;
	
	for (c=1; c<=3; c++) {
		printf ("Insira o numero de identificacao e a altura do %do aluno em cm: ", c);
		scanf ("%d %d", &n, &h);
		if (h > maior_h) {
			maior_h = h;
			maior_n = n;
		} else if (h < menor_h) {
			menor_h = h;
			menor_n = n;
		}
		printf ("---------------------------------------------\n");
	}
	printf ("O maior aluno foi o de numero de identificacao %d, com %d centimentos e o menor foi o de numero %d, com %d centimentros.", maior_n, maior_h, menor_n, menor_h);
}
