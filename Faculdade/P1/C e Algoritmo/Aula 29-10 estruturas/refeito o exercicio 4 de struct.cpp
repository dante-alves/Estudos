#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

/*Fa�a um algoritmo para calcular a �rea total de uma resid�ncia (por exemplo, sala, cozinha, banheiro, quartos, �rea de servi�o, quintal garagem, 
etc.). 

O programa dever� capturar do teclado o nome do c�modo e a largura e o comprimento deste, armazenar estes dados em uma estrutura do tipo 
ESTRUTURA (typedef struct). 

Em seguida, dever� calcular a �rea do c�modo lido e armazenar o resultado junto com os dados do respectivo c�modo.
 
Perguntar ao usu�rio se deseja continuar calculando a �rea de um outro c�modo. A casa pode ter at� 5 c�modos. Caso o usu�rio responda "N�O", o 
programa dever� recuperar e apresentar todos valores gravados na estrutura e o valor da �rea total da resid�ncia.*/

typedef struct{
	char nome[30];
	float largura;
	float comprimento;
	float area;
}t_Comodo;

//procedimento para deixar em portugu�s (fui testar se funcionava assim)
void pt(){
	setlocale(0, "Portuguese");
}

// fun��o que verifica se o usu�rio deseja calcular mais algum c�modo.
char verificarOpcao(int i){
	char opcao;
	if(i < 4){
		printf("\nDeseja calcular a �rea de mais algum c�modo[S/N]? ");
		scanf("%c", &opcao);
		scanf("%c");
		
		opcao = toupper(opcao);
		
		while(opcao != 'S' && opcao != 'N'){
			printf("Op��o inv�lida. Digite S para sim e N para n�o: ");
			scanf("%c", &opcao);
			scanf("%c");
			
			opcao = toupper(opcao);
		}
	}
	else
		opcao = 'S';
		
	return opcao;
}

// fun��o que l� os dados e retorna a quantidade de c�modos inseridos
int lerDados(t_Comodo *comodo, float *areaTotal){
	
	int qtd = 0, i = 0;
	char opcao;
	
	do{
		qtd++;
		
		printf("C�modo %d", i + 1);
		printf("\n----------------\n");
		
		printf(" Nome do c�modo: ");
		scanf("%30[^\n]", comodo[i].nome);
		scanf("%c");
		
		printf(" Largura em metros: ");
		scanf("%f", &comodo[i].largura);
		scanf("%c");
		
		printf(" Comprimento em metros: ");
		scanf("%f", &comodo[i].comprimento);
		scanf("%c");
		
		comodo[i].area = comodo[i].largura * comodo[i].comprimento;
		
		*areaTotal += comodo[i].area;

		opcao = verificarOpcao(i);
			
		printf("\n");
		
		if(opcao == 'S')
			i++;
	}while(opcao == 'S' && i < 5);
	
	return qtd;
}

// procedimento que imprime o resultado
imprimirDados(t_Comodo *comodo, float areaTotal, int qtd){
	int i = 0;
	
	printf("\n\t-------------------------\n");
	printf("\t      PLANTA DA CASA");
	printf("\n\t-------------------------\n");
	for(i = 0; i < qtd; i++){
		printf("\t  %s\n\t   Largura: %.2fm�\n\t   Comprimento: %.2fm�\n\t   Area: %.2fm�", 
		comodo[i].nome, 
		comodo[i].largura, 
		comodo[i].comprimento, 
		comodo[i].area);
		printf("\n\t-------------------------\n");
	}
	printf("\t  Total de c�modos: %d\n\t  �rea total: %.2fm�", qtd, areaTotal);
	printf("\n\t-------------------------\n");
}

int main(){
	pt();
	
	//Vari�veis
	t_Comodo comodo[5];
	
	int i = 0, qtd = 0;
	char opcao;
	float areaTotal = 0;
	
	// fun��o que l� os dados e retorna a quantidade de c�modos inseridos
	qtd = lerDados(comodo, &areaTotal);
	
	// limpar o terminal
	system("cls");
	
	// procedimento que imprime o resultado
	imprimirDados(comodo, areaTotal, qtd);
		
	return 0;
}
