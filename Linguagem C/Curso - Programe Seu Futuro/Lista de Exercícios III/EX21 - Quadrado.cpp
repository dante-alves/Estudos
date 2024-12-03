#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX21 - Quadrado com *

//Jeito muito simples
int main () {
	for (int i = 1; i <= 10; i++)
		printf ("********************\n");
}

/*Jeito bugadasso
int main () {
	for (int i = 1; i <= 10; i++) {
		for (int c = 1; c <=20; c++){
			printf("*");
		}
		printf ("\n");
	}
}*/
