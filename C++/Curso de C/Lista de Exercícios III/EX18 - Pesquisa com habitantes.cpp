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
	
	//Quantas pessoas s�o
	printf ("Quantas pessoas participaram da pesquisa? ");
	scanf ("%d", &x);
	
	//Estrutura principal
	for (i = 1; i <= x; i++) {
		//Coleta dos dados
		
		printf ("\n%d� Pessoa\n", i);
		printf ("-----------------\n");
		
		printf ("Sal�rio: R$ ");
		scanf ("%f", &sal);
		
		printf ("Sexo (M/F): ");
		scanf ("%s", sexo);
		
		printf ("Idade: ");
		scanf ("%d", &idade);

		//Verifica��o
		
		//Somar salarios
		somaSal += sal;
		
		//Atualizar maior e menor idade
		if (idade > maiorIdade) {
			maiorIdade = idade;
		}
		
		if (idade < menorIdade) {
			menorIdade = idade;
		}
		
		//Verificar mulheres com sal�rio menor que 2000
		if (strcmp(sexo, "F") == 0 || strcmp(sexo, "f") == 0 && sal <= 2000) {
			mulheresSal2000++;
		}
	}
	mediaSal = somaSal / x;
	printf ("a) A m�dia de sal�rio do grupo: %.2f\n", mediaSal);
	printf ("b) A maior idade do grupo foi %d anos, enquanto a menor foi de %d anos.\n", maiorIdade, menorIdade);
	printf ("c) No total, %d mulhere(s) tem o sal�rio de at� R$ 2000,00\n", mulheresSal2000);
}
