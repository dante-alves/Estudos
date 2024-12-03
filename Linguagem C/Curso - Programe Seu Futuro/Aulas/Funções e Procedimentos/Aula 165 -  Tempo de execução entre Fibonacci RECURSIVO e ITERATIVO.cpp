#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//Aula 165 -  Tempo de execução entre Fibonacci RECURSIVO e ITERATIVO

//RECURSIVO
long long int fiboR(int n) {
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return fiboR(n - 1) + fiboR(n - 2);
}

//ITERATIVO
long long int fiboI(int n) {
	long long int i = 2, num1 = 0, num2 = 1, att;
	if (n == 1)
		return num1;
	else if (n == 2)
		return num2;
	else {
		while (i < n) {
			att = num1 + num2;
			num1 = num2;
			num2 = att;
			i++; 
		}
		return att;
	}
}

int main() {
	setlocale(0, "Portuguese");
	int n = 50; 
	time_t tInicio, tFim;
	
	tInicio = time(NULL);
	printf("\nFibonacci Iterativo: %lld\n", fiboI(n));
	tFim = time(NULL);
	printf("\tTempo de execução em segundos: %f", difftime(tFim, tInicio));
	
	
	tInicio = time(NULL);
	printf("\nFibonacci Recursivo: %lld\n", fiboR(n));
	tFim = time(NULL);
	printf("\tTempo de execução em segundos: %f", difftime(tFim, tInicio));
	
	return 0;
}
