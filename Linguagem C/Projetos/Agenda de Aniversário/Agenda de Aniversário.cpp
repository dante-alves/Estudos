#include <stdio.h>
#include <stdlib.h>

//Estrutura para armazenar os dados de cada contato
typedef struct{
	char nome[50];
	int dia, mes, ano;	
}t_Contato;

//Procedimento para imprimir a lista no vetor
void imprimir(t_Contato **c, int quant){
	int i;
	
	printf("\n\t\t  Lista de Contatos\n");
	printf("\t-----------------------------------\n");
	for(i = 0; i < quant; i++){
		printf("\t%d = %2d/%2d/%4d\t%s\n", i+1, c[i]->dia, c[i]->mes, c[i]->ano, c[i]->nome);
	}
	printf("\t-----------------------------------\n");
}

//Procedimento para cadastrar um novo contato no vetor
int cadastrar_contato(t_Contato **c, int quant, int tam){
	
	if(quant < tam){
		t_Contato *novo = (t_Contato *) malloc(sizeof(t_Contato)); //Alocando memória dinâmica para o novo ponteiro
		printf("Digite o nome do contato: ");
		scanf("%49[^\n]", novo->nome);
		getchar();
		
		printf("Data de nascimento (dd/mm/aaaa): ");
		scanf("%d/%d/%d", &novo->dia, &novo->mes, &novo->ano);
		getchar();
		
		c[quant] = novo;
		
		return 1;
	}
	else{
		printf("Impossível cadastrar novo contato! Agenda Cheia.");
		return 0;
	}
}

//Procedimento para alterar algum contato do vetor
void alterar(t_Contato **c, int quant){
	int id, opc;
	
	imprimir(c, quant);

	printf("Digite o id do contato que deseja alterar: ");
	scanf("%d", &id);
	getchar();
	
	id--;
	
	if(id >= 0 && id < quant){
		t_Contato *novo = (t_Contato *)malloc(sizeof(t_Contato));
		
		printf("Tem certeza que deseja deletar o contato '%s'?\nDigite 1 para SIM: ", c[id]->nome);
		scanf("%d", &opc);
		getchar();
		
		if(opc){
			printf("Digite o nome do contato: ");
			scanf("%49[^\n]", novo->nome);
			
			
			printf("Data de nascimento (dd/mm/aaaa): ");
			scanf("%d/%d/%d", &novo->dia, &novo->mes, &novo->ano);
			getchar();
			
			c[id] = novo;
		}
	}
	else
		printf("Codigo invalido!");
	
}

//Função para deletar contato e retornar a quantidade total de contatos
int deletar(t_Contato **c, int quant){
	int id, opc;
	
	imprimir(c, quant);

	printf("Digite o id do contato que deseja deletar: ");
	scanf("%d", &id);
	getchar();
	
	
	id--;
	
	
	
	if(id >= 0 && id < quant){
		printf("Tem certeza que deseja deletar o contato '%s'?\nDigite 1 para SIM: ", c[id]->nome);
		scanf("%d", &opc);
		getchar();
		
		if(opc){
			if(id < quant - 1){
				for(int i = id; i < quant - 1; i++)
					c[i] = c[i + 1];
			}
			quant--;
		}
	}
	else
		printf("Codigo invalido!");
	
	return quant;
}

//Procedimento para salvar o vetor num arquivo
void salvar(t_Contato **c, int quant, char f[]){
	FILE *file = fopen(f, "w");
	int i;
	
	if(file){
		fprintf(file, "%d\n", quant);
		
		for(i = 0; i < quant; i++){
			fprintf(file, "%s\n%d/%d/%d\n", c[i]->nome, c[i]->dia, c[i]->mes, c[i]->ano);
		}
		fclose(file);
	}
	else
		printf("Erro ao abrir o arquivo!");
}

//Função que lê o arquivo de texto e passa para o vetor, retornando a quantidade de elementos.
int ler(t_Contato **c, char f[]){
	FILE *file = fopen(f, "r");
	int i, quant = 0;
	
	t_Contato *novo = (t_Contato *)malloc(sizeof(t_Contato));
	
	if(file){
		fscanf(file, "%d\n", &quant);
		
		for(i = 0; i < quant; i++){
			fscanf(file, "%49[^\n]%d/%d/%d\n", novo->nome, &novo->dia, &novo->mes, &novo->ano);
			c[i] = novo;
			novo = (t_Contato *)malloc(sizeof(t_Contato));
		}
		
		fclose(file);	
	}
	else
		printf("Erro ao abrir o arquivo!");
		
	return quant;
}

int main(){
	char file_name[] = {"Agenda.txt"}; //Nome do arquivo onde vai ser armazenado
	int tam = 50, quant = 0; //Tamanho total do vetor e quantidade que já foi preenchida nos contatos
	int opcao;
	
	//Vetor principal da agenda
	t_Contato *contato[tam];
	
	//Ler os dados contidos no arquivo .txt
	quant = ler(contato, file_name);
	
	do{
		printf("\n\t[1] - Imprimir Agenda\n\t[2] - Cadastrar Contato\n\t[3] - Alterar Agenda\n\t[4] - Deletar Contato\n\t[5] - Salvar Agenda\n\t[0] - Sair\n");
		scanf("%d", &opcao);
		getchar();
		
		switch(opcao){
			case 1: 
				imprimir(contato, quant); 
				printf("Pressione ENTER para continuar...");
				getchar();
				break;
			case 2: 
				quant += cadastrar_contato(contato, quant, tam);
				break;
			case 3:
				alterar(contato, quant);
				break;
			case 4:
				quant = deletar(contato, quant);
				break;
			case 5:
				salvar(contato, quant, file_name);
				break;
			default:
				printf("\nOpção inválida! Digite outra opção.\n");
		}
		system("cls");
	}while(opcao != 0);
	
	printf("Programa finalizado, ate a proxima!\n");
	
	return 0;
}
