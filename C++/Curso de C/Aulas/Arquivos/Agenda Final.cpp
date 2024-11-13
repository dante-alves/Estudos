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
		printf("Erro ao abrir o arquivo!\n");
	
	return quant;
}

void salvarB(t_Contato **c, int quant, char f[]){
	FILE *file = fopen(f, "wb");
	
	int i;
	
	if(file){
		for(i = 0; i < quant; i++)
			//fwrite(c, sizeof(t_Contato), quant, file) ->>> Assim não ia dar certo, pois a variável c é um ponteiro para ponteiro
			fwrite(c[i], sizeof(t_Contato), 1, file);
		
		fclose(file);
	}
	else
		printf("Erro ao abrir arquivo!\n");
}

int lerB(t_Contato **c, char f[]){
	FILE *file = fopen(f, "rb");
	int quant = 0;
	t_Contato *novo = (t_Contato *)malloc(sizeof(t_Contato));
	
	if(file){
		while(fread(novo, sizeof(t_Contato), 1, file)){
			c[quant] = novo;
			quant++;
			novo = (t_Contato *)malloc(sizeof(t_Contato));
			
		}
		fclose(file);
	}
	else
		printf("Erro ao abrir arquivo!\n");
		
	return quant;
}

void alterarB(char f[]){
	//Variáveis
	FILE *file = fopen(f, "rb+");
	
	int id, i = 1;
	
	t_Contato c;
	
	//Código

	if(file){
		printf("\n\tLista de Contatos:\n");
		printf("\t-----------------------------\n");
		//Ler os contatos 1 por 1
		while(fread(&c, sizeof(t_Contato), 1, file)){
			printf("\t%d = %2d/%2d/%4d\t%s\n", i, c.dia, c.mes, c.ano, c.nome);
			i++;
		}
		printf("\t-----------------------------\n");
		
		printf("\n\tDigite o indice de contato que deseja alterar: ");
		scanf("%d", &id);
		getchar();
		id--;
		
		if(id >= 0 && id < i - 1){
			printf("Digite nome e data de nascimento dd/mm/aaaa: ");
			scanf("%49[^\n]%d/%d/%d", c.nome, &c.dia, &c.mes, &c.ano);
			
			//O fseek vai fazer o arquivo apontar para o dado que eu quero modificar --> Aponta com base nos bytes, por isso id * sizeof(t_Contato)
			fseek(file, id * sizeof(t_Contato), SEEK_SET); //FUNÇÃO FSEEK - SEEK_SET COMEÇA DO INÍCIO DO ARQUIVO
			fwrite(&c, sizeof(t_Contato), 1, file);
			
		}
		fclose(file);
	}
	else
		printf("Erro ao abrir arquivo!\n");
}

int main(){
	t_Contato *agenda[50];
	char file_name[] = {"Arquivo.txt"};
	char file_name_bin[] = {"agenda.dat"};
	int tam = 50, quant = 0;
	int opcao;
	
	 //Ler o arquivo e pegar os dados
	quant = ler(agenda, file_name);
	
	do{
		printf("\n\t[1] - Imprimir \n\t[2] - Cadastrar\n\t[3] - Alterar\n\t[4] - Deletar\n\t[5] - Salvar");
		printf("\n\t[6] - SalvarB\n\t[7] - LerB\n\t[8] - AlterarB\n\t[0] - Sair\n");
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
			case 6:
				salvarB(agenda, quant, file_name_bin);
				break;
			case 7:
				quant = lerB(agenda, file_name_bin);
				break;
			case 8:
				alterarB(file_name_bin);
			default:
				if(opcao != 0)
					printf("\n\tOpção Inválida!!!\n");
		}
		system("cls");
	}while(opcao != 0);

	
	return 0;
}
