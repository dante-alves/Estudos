#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Aula 160 - Somat�rio de 1 at� n com Fun��o recursiva

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
	
	printf("Digite um n�mero: ");
	scanf("%d", &n);
	
	printf("\nDe 1 at� %d...\n", n);
	procedSomatorio(n);
	
	printf("\n\nO somat�rio de 1 at� %d �: %d", n, somatorio(n));
	
	return 0;
}
