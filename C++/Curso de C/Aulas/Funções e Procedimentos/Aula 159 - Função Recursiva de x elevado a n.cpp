#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Aula 159 - Função Recursiva de x elevado a n

int potencia(int x, int n) {
	if (n == 0) 
		return 1;
	else {
		return	x * potencia(x, n - 1);
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	int x, n;
	
	printf("Digite um número: ");
	scanf("%d", &x);
	
	printf("Escolha a que potência o número será elevado: ");
	scanf("%d", &n);
	
	printf("\n%d elevado a %d é igual a: %d\n", x, n, potencia(x,n));
	
	return 0;
	
}
