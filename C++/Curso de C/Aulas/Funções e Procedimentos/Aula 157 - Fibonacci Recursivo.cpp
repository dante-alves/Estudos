#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Aula 157 - Fibonacci Recursivo


//Fun��o de Fibonacci Recursivo
int fibonacci(int n) {
	if (n == 1) 
		return 0;
	else if (n == 2)
		return 1;
	else 
		return fibonacci(n - 1) + fibonacci(n - 2);
}

//Procedimento para fazer Fibonacci
void printFibonacci(int n) {
	int num1 = 0, num2 = 1, aux;
	
	for (int i = 0; i < n - 1; i++) {
		printf("%d, ", num1);
		
		aux = num1 + num2;
		num1 = num2;
		num2 = aux;
	}
	printf("%d...", num1);
}

//Main
int main() {
	setlocale(LC_ALL, "Portuguese");
	int N, resposta;
	
	printf("Digite o en�simo termo a ser identificado numa sequ�ncia Fibonacci: ");
	scanf("%d", &N);
	
	printFibonacci(N); //Chamando o procedimento
	
	resposta = fibonacci(N); //Retornando a fun��o
	
	printf("\n\n%d� termo: %d", N, resposta);
	
	return 0;
}
