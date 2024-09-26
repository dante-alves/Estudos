#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//EX05 - Maior e menor temperatura

int main () {
	setlocale(0, "Portuguese");
	//Variáveis
	float tempMes[12] = {15, 20, 22, 25, 10, 12, 16, 15, 20, 23, 25, 20}, maiorTemp, menorTemp;
	int i, mesMaior, mesMenor;
	const char *mes[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
	
	maiorTemp = tempMes[0];
	menorTemp = tempMes[0];
	mesMaior = 0;
	mesMenor = 0;
	
	for (i = 0; i < 12; i++) {
		if (tempMes[i] < menorTemp) {
			menorTemp = tempMes[i];
			mesMenor = i;
		}
		
		if (tempMes[i] > maiorTemp) {
			maiorTemp = tempMes[i];
			mesMaior = i;
		}
	}
	printf("No mês de %s, houveram as maiores baixas na temperatura, com média de %.1fº Celsius.\nJá no mês de %s, as maiores altas do ano ocorreram, com média de %.1fº Celsius.", mes[mesMenor], menorTemp, 
	mes[mesMaior], maiorTemp);

	return 0;
}
