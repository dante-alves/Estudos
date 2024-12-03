#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX16 - Divisível por 1 a 10

//Forma louca que pensei
int main () {
	setlocale (LC_ALL, "Portuguese");
	
	int numero, div, n = 1;
	
	while (div != 10) {
		div = 0;
		
		for (int c = 1; c <= 10; c++) {
			if (n % c == 0) {
				div++;
			}	
		}
		
		
		if (div == 10) {
			numero = n;
		}
		n++;
	}
	
	printf ("O número que é divisível pelos números de 1 a 10 é %d.", numero);
}

	

