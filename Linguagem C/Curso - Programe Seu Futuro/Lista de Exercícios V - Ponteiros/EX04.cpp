#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	EX04 - Considere a seguinte declaração: int A, *B, **C, ***D
	Escreva um programa que leia a variável A e calcule e exiba o dobro, o triplo e o quádruplo desse
	valor utilizando apenas os ponteiros B, C e D. O ponteiro B deve ser usada para calcular o dobro, C
	o triplo e D o quádruplo.
*/

int main(){
	int A, *B, **C, ***D;
	
	printf("Digite um valor para A: ");
	scanf("%d", &A);
	
	B = &A;
	C = &B;
	D = &C;
	
	printf("%d, %d, %d, %d", A, *B * 2, **C * 3, ***D * 4);
}
