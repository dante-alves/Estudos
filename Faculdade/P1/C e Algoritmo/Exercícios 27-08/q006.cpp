#include <stdio.h>

//Questao 6

int main () {
	int num;
	printf ("Digite um numero: ");
	scanf ("%d", &num);
	
	if (num >= 10 && num <= 15) {
		printf ("O numero %d esta contido entre o intervalo de 10 e 15.", num);
	} else {
		printf ("O numero %d nao esta contido entre o intervalo de 10 e 15.", num);
	}
}
