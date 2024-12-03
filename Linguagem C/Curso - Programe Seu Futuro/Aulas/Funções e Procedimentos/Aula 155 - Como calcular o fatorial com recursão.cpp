#include <stdio.h>
#include <stdlib.h>

//Aula 155 - Como calcular o fatorial com recursão?

void imprimir (int n) {
	if(n == 0 || n == 1) 
		printf("%d", n);
	else {
		printf("%d x ", n);
		imprimir(n - 1);
	}
}

int fatorial(int n) {
	if (n == 0 || n == 1) 
		return 1;
	else 
		return n * fatorial(n - 1);
}


int main() {
	int n;
	printf("Escolha um valor para calcular o fatorial: ");
	scanf("%d", &n);

	printf("%d! = ", n);
	imprimir(n);
	
	printf(" = %d", fatorial(n));
}
