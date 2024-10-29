#include <stdio.h>
#include <stdlib.h> //Todas as funções de alocação de memória estão nessa biblioteca

/*
	Aula 197 e 198 - Alocação dinâmica de memória com a função malloc e calloc
*/

/*
	malloc = Memory Allocation
	retorna um ponteiro para a região de memória alocada ou NULL.
*/
int main(){
	int y; //Alocação de memória estática
	
	float *x;//Alocação dinâmica de memória
	
	//USANDO MALLOC
	//x = (int *)malloc(sizeof(int)); //precisa passar como parâmetro a quantidade de bytes do tipo de dado que quer utilizar(no caso do int, 4 bytes)
	
	//USANDO CALLOC
	x = (float *)calloc(1, sizeof(float)); //passa primeiro para quantos elementos eu quero alocar memória, e depois os bytes
	
	
	//OBS -- se esquecer a quantidade de memória que um determinado tipo utiliza, é só usar o sizeof(tipo de dado)
	
	//OBS
	if(x){
		printf("Memoria alocada com sucesso!\n");
		*x = 50;
		printf("Valor de x: %f\n", *x);
	}
	else{
		printf("Erro ao alocar memoria!\n");
	}	
	
	return 0;
}
