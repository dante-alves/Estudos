#include <stdio.h>
#include <stdlib.h>

//Aula 191 - Ponteiro para ponteiro

int main(){
	
	int A = 100, *B, **C; //**C é uma variável do tipo ponteiro que vai apontar para outro ponteiro
	
	B = &A; //Para o ponteiro receber valor nulo, é só botar NULL
	
	C = &B;
	
	printf("Endereco de A: %p\t Conteudo de A: %d\n", &A, A);
	
	printf("\nEndereco de B: %p\t Conteudo de B: %p\t Conteudo apontado por B: %d\n", &B, B, *B);
	
	printf("\nEndereco de C: %p\t Conteudo de C: %p\t Conteudo apontado por C: %d\n", &C, C, **C);
	
	return 0;
}
