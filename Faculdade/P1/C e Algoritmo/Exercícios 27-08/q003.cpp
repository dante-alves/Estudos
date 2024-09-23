#include <stdio.h>
#include <math.h>

//Questao 3
	
int main () {
	float n1, n2, m;
	
	printf ("Primeira nota: ");
	scanf ("%f", &n1);
	printf ("-----------------------\n");
	printf ("Segunda nota: ");
	scanf ("%f", &n2);
	m = (n1 + n2) / 2;
	printf ("-----------------------\n");
	printf ("A media foi %.1f\n", m);
	printf ("-----------------------\n");
}

