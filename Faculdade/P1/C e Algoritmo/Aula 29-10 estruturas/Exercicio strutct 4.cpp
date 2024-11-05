#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

/*Faça um algoritmo para calcular a área total de uma residência (por exemplo, sala, cozinha, banheiro, quartos, área de serviço, quintal garagem, 
etc.). 

O programa deverá capturar do teclado o nome do cômodo e a largura e o comprimento deste, armazenar estes dados em uma estrutura do tipo 
ESTRUTURA (typedef struct). 

Em seguida, deverá calcular a área do cômodo lido e armazenar o resultado junto com os dados do respectivo cômodo.
 
Perguntar ao usuário se deseja continuar calculando a área de um outro cômodo. A casa pode ter até 5 cômodos. Caso o usuário responda "NÃO", o 
programa deverá recuperar e apresentar todos valores gravados na estrutura e o valor da área total da residência.*/

typedef struct{
	char nome[30];
	float largura;
	float comprimento;
	float area;
}t_Comodo;

void pt(){
	setlocale(0, "Portuguese");
}



int main(){
	pt();
	
	t_Comodo comodo[5];
	//Variáveis
	int i = 0, qtd = 0;
	char opcao;
	float areaTotal = 0;
	
	do{
		qtd++;
		
		printf("Cômodo %d", i + 1);
		printf("\n----------------\n");
		
		printf(" Nome do cômodo: ");
		scanf("%30[^\n]", comodo[i].nome);
		scanf("%c");
		
		printf(" Largura em metros: ");
		scanf("%f", &comodo[i].largura);
		scanf("%c");
		
		printf(" Comprimento em metros: ");
		scanf("%f", &comodo[i].comprimento);
		scanf("%c");
		
		comodo[i].area = comodo[i].largura * comodo[i].comprimento;
		
		areaTotal += comodo[i].area;
		if(i < 4){
			printf("\nDeseja calcular a área de mais algum cômodo[S/N]? ");
			scanf("%c", &opcao);
			scanf("%c");
			
			opcao = toupper(opcao);
			
			while(opcao != 'S' && opcao != 'N'){
				printf("Opção inválida. Digite S para sim e N para não: ");
				scanf("%c", &opcao);
				scanf("%c");
				
				opcao = toupper(opcao);
			}
		}
		else
			opcao = 'S';
			
		printf("\n");
		
		if(opcao == 'S')
			i++;
	}while(opcao == 'S' && i < 5);
	
	system("cls");
	
	printf("\n\t-------------------------\n");
	printf("\t      PLANTA DA CASA");
	printf("\n\t-------------------------\n");
	for(i = 0; i < qtd; i++){
		printf("\t  %s\n\t   Largura: %.2fm²\n\t   Comprimento: %.2fm²\n\t   Area: %.2fm²", 
		comodo[i].nome, 
		comodo[i].largura, 
		comodo[i].comprimento, 
		comodo[i].area);
		printf("\n\t-------------------------\n");
	}
	printf("\t  Total de cômodos: %d\n\t  Área total: %.2fm²", qtd, areaTotal);
	printf("\n\t-------------------------\n");
		
	
	return 0;
}
