#include <stdio.h>
#include <stdlib.h>

//Aula 184: O que � e como criar um ponteiro
//� uma vari�vel que armazena um endere�o de mem�ria
int main(){
	
	char num = 'f';
	
	char *p;
	
	// p = num; essa atribui��o est� errada
	p = &num;
	
	printf("Valor de num: %c\n", num);
	printf("Endereco de num: %p\n", &num); //O "&" indica o endere�o de mem�ria

	printf("Valor de p: %p\n", p);
	printf("Endereco de p: %p\n", &p);
	printf("Valor apontado por p: %c\n", *p);
	
	printf("Tamanho da variavel p: %d\n", sizeof(p)); //De quanta mem�ria um ponteiro precisa?
	
	//Aula 186 - Por que n�o usamos o & ao ler uma string com a fun��o scanf
	
	char palavra[100]; //O nome de um vetor, independente do seu tipo, j� � um ponteiro. 
	
	scanf("%100[^\n]", palavra);

	
	printf("\n%p\n", palavra);
	printf("\n%p\n", &palavra);
	printf("\n%p\n", &palavra[0]);
	
	return 0;
}
