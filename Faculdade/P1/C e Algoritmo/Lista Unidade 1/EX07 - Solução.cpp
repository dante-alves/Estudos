#include <stdio.h>
#include <locale.h>

/*EX07 - Solu��o
Leia dois valores, e exiba sua soma. Em seguida pergunte ao usu�rio:
�Novo C�lculo (S/N)?�. Deve-se ler a resposta e se a resposta for �S�
(sim), deve-se repetir todos os comandos (instru��es) novamente,
mas se for qualquer outra resposta, o algoritmo deve ser finalizado
escrevendo a mensagem �Fim dos C�lculos�. Escolha a op��o mais
adequada de comando de loop para resolver este problema

Melhor op��o: do while.
*/

int main(){
	setlocale(0, "Portuguese");
	int num1, num2, soma;
	char resposta;
	
	//Repeti��o do c�lculo
	do {
		printf("\nInsira um valor: ");
		scanf("%d", &num1);
		
		printf("Insira outro valor: ");
		scanf("%d", &num2);
		
		soma = num1 + num2;
		//Resultado
		printf("A soma entre %d e %d � igual a %d.\n", num1, num2, soma);
		
		printf("\nNovo C�lculo (S/N)? ");
		scanf(" %c", &resposta);
	} while (resposta == 'S');
	
	printf("\nFim dos C�lculos.");
	
	return 0;
}
