#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Uma pequena loja de artesanato possui apenas um vendedor e comercializa 10 tipos de objetos
diferentes. O vendedor recebe um salário de R$1100,00 acrescido de 5% do valor total de suas
vendas. O valor unitário dos objetos deve ser informado e armazenado em um vetor; a quantidade
vendida de cada objeto deve ficar em outro vetor, mas na mesma posição. Crie um programa que
receba os preços e as quantidades vendidas, armazenando-os em seus respectivos vetores. Depois,
determine e mostre:
a) A quantidade vendida, valor unitário e valor total de cada objeto. Ao final, deverão ser mostrados
o valor total das vendas e o valor da comissão que será paga ao vendedor.
b) O valor do objeto mais vendido e sua posição no vetor (em caso de empates mostre todos
empatados).

Comissão = 5% das vendas
valor unitário 1 vetor
quantidade vendida outro vetor na mesma posição
valor total de cada objeto = valor unitário x quantidade
valor total das vendas = valor total de cada objeto x total de objetos (10)

*/

//EX04 - Venda de Produtos

int main () {
	//Português
	setlocale(LC_ALL, "Portuguese");
	
	//Variáveis
	float vUnitario[10], vTotal[10], totalVendas = 0, comissao, salario;
	int qtdVendida[10], i, j, empatados = 0, maiorQtd = 0;
	
	//Código
	
	for (i = 0; i < 10; i++) {
		printf("Insira o preço do %dº produto: R$", i + 1);
		scanf("%f", &vUnitario[i]);
		printf("Quantos foram vendidos? ");
		scanf("%d", &qtdVendida[i]);
		
		//Capturar a maior quantidade
		if (maiorQtd < qtdVendida[i])
			maiorQtd = qtdVendida[i];
		
		/* LOUCURA INSENSATEZ ESTADO INEVITÁVEL
		if (maisVendido < qtdVendida[i]) {
			maisVendido = qtdVendida[i];
			maiorValor[i] = vUnitario[i];
			primeiroMais = i;
			
		} else if (maisVendido == qtdVendida[i]) {
			maiorValor[i] = vUnitario[i];
			posicaoMaisVendido[i] = i;
			empatados++;
		} */
		
		//Valor total de cada objeto
		for (j = 0; j < 10; j++) {
			vTotal[i] = vUnitario[i] * qtdVendida[i];
		}
		totalVendas += vTotal[i];
	}
	
	//Verificar quantos tiveram a maior quantidade de vendas
	for (i = 0; i < 10; i++) {
		if (qtdVendida[i] == maiorQtd)
			empatados++;
	}
	
	//Valor da comissão
	comissao = totalVendas * 0.05;
	salario = 1100 + comissao;
	//Resultados
	for (i = 0; i < 10; i++) {
		printf("\nProduto %d\n", i + 1);
		printf("----------------\n");
		printf("Quantidade vendida: %d\n", qtdVendida[i]);
		printf("Valor Unitário: R$%.2f\n", vUnitario[i]);
		printf("Valor das vendas do produto: R$%.2f\n", vTotal[i]);
		printf("----------------\n");
	}
	
	printf("\nValor total das vendas: R$%.2f\n", totalVendas);
	printf("Comissão do vendedor: R$%.2f\nSalário final do vendedor: R$%.2f\n", comissao, salario);
	

	if (empatados == 1) {
		for (i = 0; i < 10; i++) {
			if (qtdVendida[i] == maiorQtd) {
				printf("O produto mais vendido custava R$%.2f, e estava na posição: %d.\n", vUnitario[i], i);
			}
		}
							
	} else {
		printf("Os produtos mais vendidos empatados estavam nas posições: ");
		for (i = 0; i < 10; i++) {
			if (qtdVendida[i] == maiorQtd) {
				printf("(%d) ", i);
			}				
		}
		printf("\nCustando, respectivamente: ");
		for (i = 0; i < 10; i++) {
			if (qtdVendida[i] == maiorQtd) {
				printf("(R$%.2f) ", vUnitario[i]);
			}				
		}
	}
	
	return 0;
}
