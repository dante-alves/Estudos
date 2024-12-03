#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Aula 160 - Somatório de 1 até n com Função recursiva

void procedSomatorio(int n) {
	if (n == 1)
		printf("%d", n);
	else {
		procedSomatorio(n - 1);
		printf(" + %d", n);
	}
}

int somatorio(int n) {
	if (n == 1)
		return 1;
	else {
		return n + somatorio(n - 1);
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	int n;
	
	printf("Digite um número: ");
	scanf("%d", &n);
	
	printf("\nDe 1 até %d...\n", n);
	procedSomatorio(n);
	
	printf("\n\nO somatório de 1 até %d é: %d", n, somatorio(n));
	
	return 0;
}
