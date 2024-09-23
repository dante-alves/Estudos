#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX24 - Sequência I e J

int main () {
	setlocale(LC_ALL, "Portuguese"); 
	/*
	int I = 1;
	
	while (I <= 9) {
		
		//Definir a lógica do J 
		for (int J = 7; J <= 15; J += 2) {
			//Fazer o J diminuir os números necesários
			for (int j = J; j >= (J-2); j--) {
				printf ("I = %d | J = %d\n", I, j);
			}
			//Incremento ao I a cada vez que o J aumenta 2.
			I += 2;
		}
	}
	}*/


//Outra forma:
int I, J;
	for (I = 1; I <= 9; I += 2) {
		for (J = 6 + I; J >= 4 + I; J--) 
			printf ("I = %d | J = %d \n", I, J);
	}
}

