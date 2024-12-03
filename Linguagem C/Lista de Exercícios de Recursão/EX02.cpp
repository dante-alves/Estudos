#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*EX02 - Faça uma função recursiva que calcule e retorne o N-ésimo termo da sequência
Fibonacci. Alguns números desta sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...*/

int fibo(int n){
	if(n == 1)
		return 0;
	else if(n == 2)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}

int main(){
	int n;
	
	setlocale(0, "Portuguese");
	
	printf("Digite um enésimo termo a ser calculado na sequência de Fibonacci: ");
	scanf("%d", &n);
	
	printf("\nResultado: %d", fibo(n));
	
	return 0;
}
