#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX22 - Chico e Z� crescendo

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	float ze = 1.10, chico = 1.50;
	int ano = 0;
	
	while (ze < chico) {
		ze += 0.03;
		chico += 0.02;
		ano++;
	}
	
	printf ("S�o necess�rios %d anos para que Z� (%.2f)fique maior do que Chico(%.2f)", ano, ze, chico);
}
