#include <stdio.h>
#include <stdlib.h>

//Aula 187: Como passar um ponteiro para um procedimento o função

void imprimir(int *num){
	
	
	printf("No procedimento antes de alterar: %d\n", *num);
	*num = 80;
	printf("No procedimento apos alterar: %d\n", *num);
	
}

int main(){
	
	int idade = 35;
	
	printf("No main antes de alterar: %d\n", idade);
	
	imprimir(&idade); //Passar o endereço de memória da variável como parâmetro
	//É uma passagem de valor, não de referência, mas o valor passado não é
	printf("No main apos alterar: %d\n", idade);
	
	return 0;
}
