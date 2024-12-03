#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Aula 199 -  Como alocar um vetor dinâmico

int main(){
	/*Alocação usada até o momento
	int tam;
	perguntar o tamanho;
	int vet[tam];
	
	Isso não vai funcionar em todo caso, principalmente para valores muito altos, pois o computador usa mais memória dinâmica do que estática
	*/
	
	//Como fazer o vetor com alocação dinâmica?
	
	int tam, *vet;
	srand(time(NULL));
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam);
	
	vet = (int *)malloc(tam * sizeof(int)); //Lembrar do (int *) para forçar o malloc a retornar um valor inteiro
	
	if(vet){
		for(int i = 0; i < tam; i++){
			*(vet + i) = rand() % 100;
			printf("%d ", *(vet + i));
		}
	}
	else{
		printf("Erro ao alocar memoria!");
	}
	return 0;
}
