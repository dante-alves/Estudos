#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Fa�a um algoritmo que capture dados da matriz e da filial de uma loja de esportes.
Os dados a serem armazenados em mem�ria s�o:
	
	N�mero da loja -> 0 para matriz e 1 para filial
	Nome da loja
	Endere�o
	Faturamento

Os valores devem ser inseridos manualmente(como se faz na inicializa��o das vari�veis). Por exemplo, para o nome pode usar Lojas Pague-Bem"*.

Ap�s inicializar as estruturas com os valores escolhidos, mostrar todos os valores armazenados. */

typedef struct {
	int num;
	char nome[50];
	char endereco[50];
	float faturamento;
}t_Loja;


int main(){
	setlocale(0, "Portuguese");
	
	t_Loja loja;
	
	printf("Qual o tipo da loja? 0 para matriz e 1 para filial: ");
	scanf("%d", &loja.num);
	scanf("%c");
	
	printf("\nQual o nome da loja? ");
	scanf("%50[^\n]", loja.nome);
	scanf("%c");
	
	printf("\nQual o endere�o da loja? ");
	scanf("%50[^\n]", loja.endereco);
	scanf("%c");
	
	printf("\nQual o faturamento da loja? ");
	scanf("%f", &loja.faturamento);
	
	printf("Tipo da loja: %s\n\n", loja.num == 0 ? "Matriz" : "Filial");
	printf("Nome da loja: %s\n\n", loja.nome);
	printf("Endere�o da loja: %s\n\n", loja.endereco);
	printf("Faturamento da loja: %.2f\n\n", loja.faturamento);
	return 0;
	}
