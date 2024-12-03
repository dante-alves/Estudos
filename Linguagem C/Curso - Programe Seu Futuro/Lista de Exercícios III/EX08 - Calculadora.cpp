#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
//EX 08 - Calculadora

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	int opcao, i, n1, n2, conta;
	
	while (1) {
		printf ("---------------------\nC A L C U L A D O R A\n---------------------\n");
		printf ("Escolha uma operação:\n");
		printf ("1 - Somar\n2 - Subtrair\n3 - Multiplicar\n4 - Dividir\n0 - Sair\n\nOpção: ");
		scanf ("%d", &opcao);
		
		switch (opcao) {
			case 0: 
				return(0);
			break;
			case 1: 
				printf ("Insira o primeiro valor da soma: ");
				scanf ("%d", &n1);
				printf ("Insira o segundo valor da soma: ");
				scanf ("%d", &n2);
				conta = n1 + n2;
				printf ("A soma entre %d e %d é igual a: %d\n", n1, n2, conta);
			break;
			case 2: 
				printf ("Insira o primeiro valor da subtração (a ordem dos valores alterará o resultado!): ");
				scanf ("%d", &n1);
				printf ("Insira o segundo valor da subtração: ");
				scanf ("%d", &n2);
				conta = n1 - n2;
				printf ("A diferença entre %d e %d é igual a: %d\n", n1, n2, conta);
			break;
			case 3: 
				printf ("Insira o primeiro valor da multiplicação: ");
				scanf ("%d", &n1);
				printf ("Insira o segundo valor da multiplicação: ");
				scanf ("%d", &n2);
				conta = n1 * n2;
				printf ("O produto entre %d e %d é igual a: %d\n", n1, n2, conta);
			break;
			case 4: 
				printf ("Insira o dividendo da divisão: ");
				scanf ("%d", &n1);
				while (n1 == 0) {
					printf ("O dividendo não pode ser 0. Insira um novo valor: ");
					scanf ("%d", &n1);
				}
				printf ("Insira o divisor da divisão: ");
				scanf ("%d", &n2);
				float conta = (float)n1 / (float)n2;
				printf ("O quociente entre %d e %d é igual a: %.2f\n", n1, n2, conta);
			break;
		}
		printf ("\nPressione Enter para continuar...");
		getchar();
		getchar();
		system("cls");
	}
}
