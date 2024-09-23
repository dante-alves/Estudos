#include <stdio.h>

int main () {
	float n1, n2, m;
	int i;
	
	for (i = 0; i < 3; i++){
		printf ("--------------------\n");
		printf ("Primeira nota: ");
		scanf ("%f", &n1);
		printf ("Segunda nota: ");
		scanf ("%f", &n2);
		m = (n1 + n2) / 2;
		printf ("A media foi %.1f\n", m);
	}
}
