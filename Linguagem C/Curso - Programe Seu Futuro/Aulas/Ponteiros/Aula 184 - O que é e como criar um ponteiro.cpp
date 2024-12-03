#include <stdio.h>
#include <stdlib.h>

//Aula 184: O que é e como criar um ponteiro
//É uma variável que armazena um endereço de memória
int main(){
	
	char num = 'f';
	
	char *p;
	
	// p = num; essa atribuição está errada
	p = &num;
	
	printf("Valor de num: %c\n", num);
	printf("Endereco de num: %p\n", &num); //O "&" indica o endereço de memória

	printf("Valor de p: %p\n", p);
	printf("Endereco de p: %p\n", &p);
	printf("Valor apontado por p: %c\n", *p);
	
	printf("Tamanho da variavel p: %d\n", sizeof(p)); //De quanta memória um ponteiro precisa?
	
	//Aula 186 - Por que não usamos o & ao ler uma string com a função scanf
	
	char palavra[100]; //O nome de um vetor, independente do seu tipo, já é um ponteiro. 
	
	scanf("%100[^\n]", palavra);

	
	printf("\n%p\n", palavra);
	printf("\n%p\n", &palavra);
	printf("\n%p\n", &palavra[0]);
	
	return 0;
}
