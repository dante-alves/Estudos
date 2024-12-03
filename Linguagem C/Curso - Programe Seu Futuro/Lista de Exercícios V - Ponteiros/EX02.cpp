#include <stdio.h>
#include <stdlib.h>

/*
	Escreva um procedimento que troca os valores dos parâmetros recebidos. Sua assinatura deve
	ser: void troca(float *a, float *b);
*/
void troca(float *a, float *b){
	*a += *b;
	*b = *a - *b;
	*a = *a - *b;
}

int main(){
	float a = 10, b = 20;
	
	printf("Valor de (a) antes da troca: %.0f\nValor de (b) antes da troca: %.0f", a, b);
	
	troca(&a, &b);
	
	printf("\nValor de (a) depois da troca: %.0f\nValor de (b) depois da troca: %.0f", a, b);
	
	float *p;
	
	p = &a;
	
	printf("\n\nEndereco de p: %p\tEndereco salvo por p: %p == Endereco de a: %p\tValor apontado por p: %.0f", &p, p, &a, *p);
	return 0;
}
