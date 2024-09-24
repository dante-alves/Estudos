#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main () {
	setlocale(LC_ALL, "Portuguese");
	float notas[10][4];
	int i = 0, j = 0;
	
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 3; j++) {
			printf ("Nota %d: ", j + 1);
			scanf ("%f", &notas[i][j]);
			
			notas[i][3] += notas[i][j];
		}
		
		notas[i][3] /= 3;
		
	}
	
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 3; j++) {
			printf("%.2f - ", notas[i][j]);
		}
		
		printf("%.2f\n", notas[i][j]);
	} 
}
