#include <stdio.h>

int main () {
	int i;
	float r;
	char s[50];
	printf("Digite um valor inteiro, um real e o seu nome: \n");
	scanf("%d %f %s", &i, &r, s);
	printf("Ola, %s, voce escolheu os valores %d e %.2f", s, i, r);
	
}
