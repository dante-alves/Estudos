#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Aula 200 e 201-  Como realocar mem�ria com a fun��o realloc() e liberar com a fun��o free()
/*
		Fun��o realloc()
		-> Retorna um ponteiro para a nova regi�o de mem�ria.
		-> Se o ponteiro for nulo, ela aloca mem�ria.
		-> Se o novo tamanho for zero, a mem�ria � liberada.
		-> Se n�o houver mem�ria suficiente, retorna NULL.
*/

int main(){
	int tam1, tam2, *vet;
	srand(time(NULL));
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam1);
	
	vet = (int *)malloc(tam1 * sizeof(int)); //Lembrar do (int *) para for�ar o malloc a retornar um valor inteiro
	
	if(vet){
		for(int i = 0; i < tam1; i++){
			*(vet + i) = rand() % 100;
			printf("%d ", *(vet + i));
		}
		
		// AQUI COME�A A REALOCA��O
		
		printf("\n\nDigite um novo tamanho para o vetor: ");
		scanf("%d", &tam2); //usei tam2 para definir um novo tamanho e n�o perder o antigo
		
		vet = (int *)realloc(vet, tam2);
		printf("\nVetor realocado: ");
		for(int i = tam1; i < tam2; i++){ //Alocar novos valores sem perder os antigos.
				*(vet + i) = rand() % 100;
		}
		
		//Printar todos os valores
		for(int i = 0; i < tam2; i++){
			printf("%d ", *(vet + i));
		}
		
		free(vet); //IMPORTANTE --> Liberar a mem�ria alocada, principalmente para programas grandes
		
		printf("\n\n");
		for(int i = 0; i < tam2; i++){
			printf("%d ", *(vet + i));
		}
	}
	else{
		printf("Erro ao alocar memoria!");
	}
	return 0;
}
