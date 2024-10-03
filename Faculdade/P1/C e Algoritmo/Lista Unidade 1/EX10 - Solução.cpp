#include <stdio.h>
#include <locale.h>

/*EX10 - Solu��o

Fa�a um programa em C que receba o pre�o atual do produto e a venda
m�dia mensal do produto e, com base na regra que corresponde aos
dados de entrada, calcule e mostre o novo pre�o.

*/

int main() {
	setlocale(0, "Portuguese");
	int vendaMedia;
	float precoAtual, precoNovo, reajuste = 0;
	//Receber os dados
	printf("Insira o valor do produto: R$");
	scanf("%f", &precoAtual);
	printf("Venda m�dia mensal do produto(unidades vendidas): R$");
	scanf("%d", &vendaMedia);
	
	//Regras
	if (vendaMedia < 500 && precoAtual < 30) 
		reajuste = 0.1;
	else if (vendaMedia < 1200 && precoAtual < 80)
		reajuste = 0.15;
	else if (vendaMedia >= 1200 && precoAtual >= 80)
		reajuste = -0.20;
	
	precoNovo = precoAtual + (precoAtual * reajuste);
	
	if (reajuste != 0)
		printf("\nNovo pre�o: R$%.2f", precoNovo);
	else 
		printf("\nO produto n�o sofreu reajustes. Valor atual: R$%.2f", precoAtual);
	return 0;
}

