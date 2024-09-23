#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX14 - Sal�rios

int main () {
	setlocale (LC_ALL, "Portuguese");
	
	int qtd, funcMaior = 0, funcMenor = 0;
	float sal, media, totalSal = 0, maiorSal = 0, menorSal = 99999;
	
	printf ("Qual o total de funcion�rios? ");
	scanf ("%d", &qtd);
	
	//Identificar sal�rios
	for (int i = 1; i <= qtd; i++) {
		printf("Qual � o sal�rio do %d� funcion�rio? R$", i);
		scanf("%f", &sal);
		
		totalSal += sal;
		
		if (sal > maiorSal) {
			maiorSal = sal;
			funcMaior = i;
		} 
		
		if (sal < menorSal) {
			menorSal = sal;
			funcMenor = i;
		}
	}
	
	media = totalSal / qtd;
	
	printf ("\nA m�dia do sal�rio da empresa � de R$%.2f, onde o menor sal�rio � de R$%.2f, do %d� funcion�rio, e o maior sal�rio � de R$%.2f, do %d� funcion�rio.\n", media, menorSal, funcMenor, maiorSal, funcMaior);
}
