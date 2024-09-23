#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main () {
	int opNum, n1, n2, soma;
	float raiz;
	
	printf ("Menu de opcoes:\n");
	printf ("1. Somar dois numeros\n");
	printf ("2. Raiz quadrada de um numero\n");
	printf ("Digite a opcao desejada: ");
	scanf ("%d", &opNum);
	system("cls");
	if (opNum == 1)
	{
		printf ("Voce escolheu a soma de dois numeros.\nInsira o valor 1: ");
		scanf ("%d", &n1);
		printf ("Insira o valor 2: ");
		scanf ("%d", &n2);
		soma = n1 + n2;
		printf ("A soma entre %d e %d equivale a %d", n1, n2, soma);
	} else if (opNum == 2)
	{
		printf ("Voce escolheu a raiz quadrada de um numero.\nInsira o valor desejado para tirar a raiz: ");
		scanf ("%d", &n1);
		raiz = sqrt(n1);
		printf ("A raiz quadrada de %d equivale a %.2f", n1, raiz);
	}
}
