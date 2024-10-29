#include <stdio.h>
#include <stdlib.h>

//Aula 187: Como passar um ponteiro para um procedimento o fun��o

void imprimir(int *num){
	
	
	printf("No procedimento antes de alterar: %d\n", *num);
	*num = 80;
	printf("No procedimento apos alterar: %d\n", *num);
	
}

int main(){
	
	int idade = 35;
	
	printf("No main antes de alterar: %d\n", idade);
	
	imprimir(&idade); //Passar o endere�o de mem�ria da vari�vel como par�metro
	//� uma passagem de valor, n�o de refer�ncia, mas o valor passado n�o �
	printf("No main apos alterar: %d\n", idade);
	
	return 0;
}
