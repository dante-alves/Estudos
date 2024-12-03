#include <stdio.h>
#include <stdlib.h>

//Aula 188 - Vetor é sempre um ponteiro

void modificar(int vet[], int tam){
	int i, vet2[tam];
	for(i = 0; i < tam; i++)
		vet[i] *= 2;
}

void imprimir(int vet[], int tam){
	int i;
	for(i = 0; i < tam; i++)
		printf("%2d ", vet[i]);
	printf("\n");
}

int main(){
	
	int vet[5] = {5, 10, 15, 20, 25};
	
	imprimir(vet, 5);
	modificar(vet, 5); // O valor do vetor no main vai ser modificado no procedimento
	imprimir(vet, 5);
	//Se não quiser que seja modificado, tem que salvar o vetor em uma cópia
	return 0;
}
