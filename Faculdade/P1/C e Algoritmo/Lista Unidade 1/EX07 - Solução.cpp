#include <stdio.h>
#include <locale.h>

/*EX07 - Solução
Leia dois valores, e exiba sua soma. Em seguida pergunte ao usuário:
“Novo Cálculo (S/N)?”. Deve-se ler a resposta e se a resposta for ‘S’
(sim), deve-se repetir todos os comandos (instruções) novamente,
mas se for qualquer outra resposta, o algoritmo deve ser finalizado
escrevendo a mensagem “Fim dos Cálculos”. Escolha a opção mais
adequada de comando de loop para resolver este problema

Melhor opção: do while.
*/

int main(){
	setlocale(0, "Portuguese");
	int num1, num2, soma;
	char resposta;
	
	//Repetição do cálculo
	do {
		printf("\nInsira um valor: ");
		scanf("%d", &num1);
		
		printf("Insira outro valor: ");
		scanf("%d", &num2);
		
		soma = num1 + num2;
		//Resultado
		printf("A soma entre %d e %d é igual a %d.\n", num1, num2, soma);
		
		printf("\nNovo Cálculo (S/N)? ");
		scanf(" %c", &resposta);
	} while (resposta == 'S');
	
	printf("\nFim dos Cálculos.");
	
	return 0;
}
