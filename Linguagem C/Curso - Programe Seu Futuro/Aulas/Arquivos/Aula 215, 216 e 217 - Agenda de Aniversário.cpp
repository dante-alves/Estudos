#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Aula 215, 216 e 217 - Agenda de Anivers�rio
typedef struct{
	char nome[50];
	int dia, mes, ano;
}t_Aniversariante;

//Procedimento que cria o arquivo de texto e permite escrever o conte�do do mesmo.
void escrever(char f[]){
	FILE *file = fopen(f, "a");
	t_Aniversariante aniversariante;
	
	int opc;
	
	if(file){
		do{
			printf("Insira o nome do aniversariante e sua data de nascimento: ");
			scanf("%50[^\n]%d/%d/%d", 
				aniversariante.nome, 
				&aniversariante.dia, 
				&aniversariante.mes, 
				&aniversariante.ano);
			
			fprintf(file, "%s|%d/%d/%d\n",
					aniversariante.nome, 
					aniversariante.dia, 
					aniversariante.mes, 
					aniversariante.ano);
			
			printf("Anivers�rio salvo com sucesso! :]\nDigite 1 para registrar novo anivers�rio.\n");
			scanf("%d", &opc);
			getchar();
			printf("\n");
		}while(opc == 1);
		
		fclose(file);
	}
	else
		printf("ERRO ao abrir o arquivo...");
}

//Procedimento que l� o arquivo de texto
void ler(char f[]){
		FILE *file = fopen(f, "r");
		t_Aniversariante aniversariante;
		
		if(file){
			printf("\n\nAgenda de Anivers�rios\n---------------------------\n");
			
			while(fscanf(file, "%49[^|]|%d/%d/%d\n", 
						aniversariante.nome,
						&aniversariante.dia, 
						&aniversariante.mes, 
						&aniversariante.ano) == 4) // == 4 pois o fscanf retorna quantos elementos ele pegou
			{
				
				printf("Nome: %s | Data de Nascimento: %d/%d/%d\n\n",
						aniversariante.nome,
						aniversariante.dia, 
						aniversariante.mes, 
						aniversariante.ano);
			}
			fclose(file);
		}
		else
			printf("ERRO ao abrir o arquivo...");
}

int main(){
	setlocale(0,"Portuguese");
	//Vari�veis
	char file_name[50] = "Agenda.txt"; //Nome do arquivo a ser criado
	
	int opc;
	
	do{

		printf("Voc� deseja verificar a agenda, ou adicionar novos aniversariantes?\n[1]Verificar agenda\n[2]Adicionar Aniversariantes\n[3]Sair\n");
		scanf("%d", &opc);
		getchar();
		
		switch(opc){
			case 1:
				ler(file_name); //Procedimento que l� o arquivo de texto
				printf("\n\nPressione ENTER para continuar...");
				getchar(); //Esperar o ENTER
			break;
			case 2:
				escrever(file_name); //Adicionar novos aniversariantes	
		}
		
		system("cls"); //Limpar o terminal
	}while((opc != 3));

	printf("Opera��o finalizada. At� mais!");
	 
	return 0;
}
