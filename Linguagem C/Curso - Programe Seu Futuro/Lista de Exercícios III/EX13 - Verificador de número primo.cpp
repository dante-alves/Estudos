#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX13 - Verificar número primo

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	int n, dividendo;
	
	printf("----------------------------\n");
	printf("VERIFICADOR DE NÚMERO PRIMO\n");
	printf("----------------------------\n");
	printf("Insira um número positivo: ");
	scanf("%d", &n);
	
	while (n < 1) {
		printf("Valor inválido! Insira um número positivo: ");
		scanf("%d", &n);
	}
	//Verificar se o número é primo
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			dividendo++;
		}
	}
	
	if (dividendo == 2) {
		printf("O número %d é primo.\n", n);
	} else {
		printf("O número %d não é primo.\n", n);
	}
}
