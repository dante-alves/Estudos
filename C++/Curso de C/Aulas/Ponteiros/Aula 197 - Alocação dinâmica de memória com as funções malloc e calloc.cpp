#include <stdio.h>
#include <stdlib.h> //Todas as fun��es de aloca��o de mem�ria est�o nessa biblioteca

/*
	Aula 197 e 198 - Aloca��o din�mica de mem�ria com a fun��o malloc e calloc
*/

/*
	malloc = Memory Allocation
	retorna um ponteiro para a regi�o de mem�ria alocada ou NULL.
*/
int main(){
	int y; //Aloca��o de mem�ria est�tica
	
	float *x;//Aloca��o din�mica de mem�ria
	
	//USANDO MALLOC
	//x = (int *)malloc(sizeof(int)); //precisa passar como par�metro a quantidade de bytes do tipo de dado que quer utilizar(no caso do int, 4 bytes)
	
	//USANDO CALLOC
	x = (float *)calloc(1, sizeof(float)); //passa primeiro para quantos elementos eu quero alocar mem�ria, e depois os bytes
	
	
	//OBS -- se esquecer a quantidade de mem�ria que um determinado tipo utiliza, � s� usar o sizeof(tipo de dado)
	
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
