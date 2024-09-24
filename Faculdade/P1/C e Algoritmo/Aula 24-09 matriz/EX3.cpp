#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//NOTAS 10 ALUNOS

int main () {
	setlocale(LC_ALL, "Portuguese");
	float notas[10][3], soma, media[10];
	int i = 0, j = 0;
	
	for (i = 0; i < 10; i++) {
		soma = 0;
		for (j = 0; j < 3; j++) {
			printf ("Nota %d: ", j + 1);
			scanf ("%f", &notas[i][j]);
			
			soma += notas[i][j];
			
		}
		
		media[i] = soma / 3;
		
	}
	
	
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 3; j++) {
			printf("%.2f - ", notas[i][j]);
		}
		
		printf("%.2f\n", media[i]);
	} 
}
