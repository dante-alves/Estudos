#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX22 - Chico e Zé crescendo

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	float ze = 1.10, chico = 1.50;
	int ano = 0;
	
	while (ze < chico) {
		ze += 0.03;
		chico += 0.02;
		ano++;
	}
	
	printf ("São necessários %d anos para que Zé (%.2f)fique maior do que Chico(%.2f)", ano, ze, chico);
}
