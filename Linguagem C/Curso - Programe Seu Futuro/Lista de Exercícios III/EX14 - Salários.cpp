#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX14 - Salários

int main () {
	setlocale (LC_ALL, "Portuguese");
	
	int qtd, funcMaior = 0, funcMenor = 0;
	float sal, media, totalSal = 0, maiorSal = 0, menorSal = 99999;
	
	printf ("Qual o total de funcionários? ");
	scanf ("%d", &qtd);
	
	//Identificar salários
	for (int i = 1; i <= qtd; i++) {
		printf("Qual é o salário do %dº funcionário? R$", i);
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
	
	printf ("\nA média do salário da empresa é de R$%.2f, onde o menor salário é de R$%.2f, do %dº funcionário, e o maior salário é de R$%.2f, do %dº funcionário.\n", media, menorSal, funcMenor, maiorSal, funcMaior);
}
