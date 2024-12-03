#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX11 - Meia vida

int main () {
	setlocale (LC_ALL, "Portuguese");
	
	float m, tempoM;
	int tempoS = 0;
	
	printf ("Insira a massa do material radioativo (g): ");
	scanf ("%f", &m);
	
	while (m > 0.05) {
		tempoS += 50;
		m = m / 2;
	}
	
	tempoM = (float)tempoS / 60;
	int resto = tempoS % 60;
	
	printf ("O tempo necessário para a massa ser menor que 0,05g foi de %.0f minutos e %d segundos.\n", tempoM, resto);
}
