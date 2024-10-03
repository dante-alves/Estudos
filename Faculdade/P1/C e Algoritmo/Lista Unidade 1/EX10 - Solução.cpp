#include <stdio.h>
#include <locale.h>

/*EX10 - Solução

Faça um programa em C que receba o preço atual do produto e a venda
média mensal do produto e, com base na regra que corresponde aos
dados de entrada, calcule e mostre o novo preço.

*/

int main() {
	setlocale(0, "Portuguese");
	int vendaMedia;
	float precoAtual, precoNovo, reajuste = 0;
	//Receber os dados
	printf("Insira o valor do produto: R$");
	scanf("%f", &precoAtual);
	printf("Venda média mensal do produto(unidades vendidas): R$");
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
		printf("\nNovo preço: R$%.2f", precoNovo);
	else 
		printf("\nO produto não sofreu reajustes. Valor atual: R$%.2f", precoAtual);
	return 0;
}

