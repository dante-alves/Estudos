#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//EX18 - Pesquisa com habitantes

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	int x, i, idade, menorIdade = 9999, maiorIdade = 0, mulheresSal2000 = 0;
	float  sal, somaSal = 0, mediaSal;
	char sexo[2];
	
	//Quantas pessoas são
	printf ("Quantas pessoas participaram da pesquisa? ");
	scanf ("%d", &x);
	
	//Estrutura principal
	for (i = 1; i <= x; i++) {
		//Coleta dos dados
		
		printf ("\n%dª Pessoa\n", i);
		printf ("-----------------\n");
		
		printf ("Salário: R$ ");
		scanf ("%f", &sal);
		
		printf ("Sexo (M/F): ");
		scanf ("%s", sexo);
		
		printf ("Idade: ");
		scanf ("%d", &idade);

		//Verificação
		
		//Somar salarios
		somaSal += sal;
		
		//Atualizar maior e menor idade
		if (idade > maiorIdade) {
			maiorIdade = idade;
		}
		
		if (idade < menorIdade) {
			menorIdade = idade;
		}
		
		//Verificar mulheres com salário menor que 2000
		if (strcmp(sexo, "F") == 0 || strcmp(sexo, "f") == 0 && sal <= 2000) {
			mulheresSal2000++;
		}
	}
	mediaSal = somaSal / x;
	printf ("a) A média de salário do grupo: %.2f\n", mediaSal);
	printf ("b) A maior idade do grupo foi %d anos, enquanto a menor foi de %d anos.\n", maiorIdade, menorIdade);
	printf ("c) No total, %d mulhere(s) tem o salário de até R$ 2000,00\n", mulheresSal2000);
}
