#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	EX03 - Crie um programa que contenha um array de inteiros com 10 elementos. Imprima o elemento e o
	endereço de cada posição do array.
*/

int main(){
	int x[10];
	int i, j, incremento;
	
	srand(time(NULL));
	do{
		incremento = 1;
		
		x[i] = rand() % 10;
		
		for(j = 0; j < i; j++){
			if(x[j] == x[i])
				incremento = 0;
		}
		
		if(incremento == 1)
			i++;
	}while(i < 10);
	
	for(i = 0; i < 10; i++){
		printf("Valor da posicao %d: %d\tEndereco da posicao %d: %p\n", i, x[i], i, &x[i]);
	}
	return 0;
}
