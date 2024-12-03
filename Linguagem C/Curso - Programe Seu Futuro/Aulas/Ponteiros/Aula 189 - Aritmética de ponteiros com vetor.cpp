#include <stdio.h>
#include <stdlib.h>

//Aula 189 - Aritmética de ponteiros com vetor

void imprimir(int vet[], int tam){
	int i;
	for(i = 0; i < tam; i++)
		//printf("%d ", vet[i]); Forma utilizando o i
		printf("%d ", *(vet + i)); //Utilizando aritmética com o ponteiro
	printf("\n");
}

int main(){
	int vet[5] = {5, 10, 15, 20, 25};
	
	imprimir(vet, 5);
	return 0;
}
