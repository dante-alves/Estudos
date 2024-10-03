#include <stdio.h>
#include <locale.h>

/*EX03 - Um restaurante durante o mês de fevereiro, armazenou diariamente a
quantidade de refeições vendidas. Determine em que dia do mês
ocorreu o maior número de vendas e qual foi a quantidade de refeições
vendida nesse dia. A partir do enunciado, faça o planejamento
conforme praticado em sala de aula.

Fevereiro - ano bissexto ou não?
Tamanho do vetor = 28 ou 29 dias 
Quantidade vendida por dia x 28 ou 29
*/

int main() {
	setlocale(0, "Portuguese");
	int tam = 28, i, diaMaiorVendas, maior = 0;
	char bissexto;
	
	//Verificar se o ano é bissexto
	printf("O ano em questão é bissexto [S/N]? ");
	scanf(" %c", &bissexto);
	while (bissexto != 'S' && bissexto != 'N'){
		printf("Responda com S ou N: ");
		scanf(" %c", &bissexto);
	}
	//Aumentar o tamanho se ano for bissexto
	if (bissexto == 'S')
		tam = 29;
	
	//Definir o array
	int vet[tam];
	
	//Registrar número de vendas por dia
	printf("\nREGISTROS\n-----------------------\n");
	for (i = 0; i < tam; i++) {
		printf("Quantidade de refeições vendidas no dia %d: ", i + 1);
		scanf("%d", &vet[i]);
		if (vet[i] > maior) {
			maior = vet[i];
			diaMaiorVendas = i + 1;
		}
	}
	
	//Resultado final
	printf("-----------------------\n");
	printf("O maior número de vendas ocorreu no dia %d do mês de Fevereiro, com um total de %d vendas.", diaMaiorVendas, maior);
	
	return 0;
}
