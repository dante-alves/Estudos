#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX13 - Verificar n�mero primo

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	int n, dividendo;
	
	printf("----------------------------\n");
	printf("VERIFICADOR DE N�MERO PRIMO\n");
	printf("----------------------------\n");
	printf("Insira um n�mero positivo: ");
	scanf("%d", &n);
	
	while (n < 1) {
		printf("Valor inv�lido! Insira um n�mero positivo: ");
		scanf("%d", &n);
	}
	//Verificar se o n�mero � primo
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			dividendo++;
		}
	}
	
	if (dividendo == 2) {
		printf("O n�mero %d � primo.\n", n);
	} else {
		printf("O n�mero %d n�o � primo.\n", n);
	}
}
