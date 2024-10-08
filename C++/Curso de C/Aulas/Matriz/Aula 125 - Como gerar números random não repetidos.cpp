#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Aula 125 - Como gerar números random não repetidos

int main () {
	int i = 0, j, igual, vet[10];
	
	srand(time(NULL));
	
	do {
		igual = 0;
		vet[i] = rand() % 10;
		for (j = 0; j < i; j++){
			if (vet[j] == vet[i])
				igual = 1;
		}
		if (igual == 0)
			i++;
	} while (i < 10);
	
	for (i = 0; i < 10; i++)
		printf("%d ", vet[i]);
	return 0;
}
