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
		printf ("Escolha uma opera��o:\n");
		printf ("1 - Somar\n2 - Subtrair\n3 - Multiplicar\n4 - Dividir\n0 - Sair\n\nOp��o: ");
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
				printf ("A soma entre %d e %d � igual a: %d\n", n1, n2, conta);
			break;
			case 2: 
				printf ("Insira o primeiro valor da subtra��o (a ordem dos valores alterar� o resultado!): ");
				scanf ("%d", &n1);
				printf ("Insira o segundo valor da subtra��o: ");
				scanf ("%d", &n2);
				conta = n1 - n2;
				printf ("A diferen�a entre %d e %d � igual a: %d\n", n1, n2, conta);
			break;
			case 3: 
				printf ("Insira o primeiro valor da multiplica��o: ");
				scanf ("%d", &n1);
				printf ("Insira o segundo valor da multiplica��o: ");
				scanf ("%d", &n2);
				conta = n1 * n2;
				printf ("O produto entre %d e %d � igual a: %d\n", n1, n2, conta);
			break;
			case 4: 
				printf ("Insira o dividendo da divis�o: ");
				scanf ("%d", &n1);
				while (n1 == 0) {
					printf ("O dividendo n�o pode ser 0. Insira um novo valor: ");
					scanf ("%d", &n1);
				}
				printf ("Insira o divisor da divis�o: ");
				scanf ("%d", &n2);
				float conta = (float)n1 / (float)n2;
				printf ("O quociente entre %d e %d � igual a: %.2f\n", n1, n2, conta);
			break;
		}
		printf ("\nPressione Enter para continuar...");
		getchar();
		getchar();
		system("cls");
	}
}
