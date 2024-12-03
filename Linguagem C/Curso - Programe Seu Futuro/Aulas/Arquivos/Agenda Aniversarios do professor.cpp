#include <stdio.h>
#include <stdlib.h>

// AGENDA DE ANIVERSÁRIOS

typedef struct{
	char nome[50];
	int dia, mes, ano;
}t_Contato;

void imprimir(t_Contato **c, int quant){
	int i;
	
	printf("\n\tLista de Contatos:\n");
	printf("\t-----------------------------\n");
	for(i = 0; i < quant; i++){
		printf("\t%d = %2d/%2d/%4d\t%s\n", i+1, c[i]->dia, c[i]->mes, c[i]->ano, c[i]->nome);	
	}
	printf("\t-----------------------------\n");
}

int cadastrar_contato(t_Contato **c, int quant, int tam){
	
	if(quant < tam){
		t_Contato *novo = (t_Contato *)malloc(sizeof(t_Contato));
	
		printf("\nDigite o nome do contato: ");
		scanf("%50[^\n]", novo->nome);
		
		printf("\nDigite a data de aniversario dd/mm/aaaa: ");
		scanf("%d/%d/%d", &novo->dia, &novo->mes, &novo->ano);
		getchar();
		c[quant] = novo;
		
		return 1;
	}
	else{
		printf("\n\tImpossivel novo cadastro. Contatos cheios!\n");
		return 0;
	}
}

void alterar_contato(t_Contato **c, int quant){
	int id;
	
	imprimir(c, quant);
	
	printf("\n\tDigite o codigo do contato que deseja alterar: \n");
	scanf("%d", &id);
	getchar();
	
	id--;
	
	if(id >= 0 && id < quant){
		t_Contato *novo = (t_Contato *)malloc(sizeof(t_Contato));
		printf("\nDigite o nome do contato: ");
		scanf("%50[^\n]", novo->nome);
		
		printf("\nDigite a data de aniversario dd/mm/aaaa: ");
		scanf("%d/%d/%d", &novo->dia, &novo->mes, &novo->ano);
		getchar();
		c[id] = novo;
	}
	else
		printf("\n\tCodigo inválido!\n");
}

int deletar_contato(t_Contato **c, int quant){
	int id, i;
	
	imprimir(c, quant);
	
	printf("\n\tDigite o codigo do contato que deseja deletar: \n");
	scanf("%d", &id);
	getchar();
	
	id--;
	
	if(id >= 0 && id < quant){
		
		if(id < quant - 1){
			for(i = id; i < quant - 1; i++)
				c[i] = c[i+1];
		}
		quant--;
	}
	else
		printf("\n\tCodigo inválido!\n");	
	
	return quant;
}

void salvar(t_Contato **c, int quant, char f[]){
	FILE *file = fopen(f, "w");
	int i;
	
	if(file){
		fprintf(file, "%d\n", quant);
		for(i = 0; i < quant; i++){
			fputs(c[i]->nome, file);
			fputc('\n', file);
			fprintf(file, "%d/%d/%d\n", c[i]->dia, c[i]->mes, c[i]->ano);
		}
		fclose(file);
	}
	else
		printf("\n\tERRO ao abrir o arquivo...\n");
}

int ler(t_Contato **c, char f[]){
	FILE *file = fopen(f, "r");
	int quant = 0, i;
	t_Contato *novo = (t_Contato *)malloc(sizeof(t_Contato));
	
	if(file){
		fscanf(file, "%d\n", &quant);
		
		for(i = 0; i < quant; i++){
			fscanf(file, "%50[^\n]", novo->nome);
			fscanf(file, "%d/%d/%d\n", &novo->dia, &novo->mes, &novo->ano);	
			c[i] = novo;
			novo = (t_Contato *)malloc(sizeof(t_Contato));	
		}
		
		fclose(file);
	}
	else
		printf("ERRO ao abrir o arquivo...");
	
	return quant;
}

int main(){
	t_Contato *agenda[50];
	char file_name[] = {"Arquivo.txt"};
	int tam = 50, quant = 0;
	int opcao;
	
	quant = ler(agenda, file_name); //Ler o arquivo e pegar os dados
	
	do{
		printf("\n\t[1] - Imprimir \n\t[2] - Cadastrar\n\t[3] - Alterar\n\t[4] - Deletar\n\t[5] - Salvar \n\t[0] - Sair\n");
		scanf("%d", &opcao);
		getchar();
		
		switch(opcao){
			case 1:
				imprimir(agenda,quant);
				printf("\n\n\tPressione ENTER para continuar...");
				getchar();
				break;
			case 2:
				quant += cadastrar_contato(agenda, quant, tam);
				
				break;
			case 3:
				alterar_contato(agenda,quant);
				break;
			case 4:
				quant = deletar_contato(agenda, quant);
			case 5:
				salvar(agenda, quant, file_name);
				break;
			default:
				if(opcao != 0)
					printf("\n\tOpção Inválida!!!\n");
		}
		system("cls");
	}while(opcao != 0);

	
	return 0;
}
