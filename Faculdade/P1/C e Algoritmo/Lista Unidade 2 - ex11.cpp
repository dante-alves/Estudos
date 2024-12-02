#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

/*			11. 
			-> Escreva um programa em C, totalmente din�mico, para realizar as
			quatro opera��es (CRUD) de um cadastro de alunos: Create, Read,
			Update e Delete. 
			Create ----> FEITO
			Read   ----> FEITO
			Update ----> 
			Delete ----> 
			
			-> Cada opera��o dever� estar em uma fun��o. ----> FEITO
			
			-> Dever� ter uma fun��o para mostrar o cadastro inteiro. ----> FEITO
			
			-> O cadastro dever� armazenar nome completo, RGM e curso. ----> FEITO
			 
			-> O nome dever� ser coletado do teclado e armazenado em uma �rea est�tica tempor�ria
			de tamanho 1024 caracteres. ----> FEITO
				- Ap�s ter o nome, alocar a �rea exata que ir� guardar o nome. ----> FEITO
				
				
			-> Os cursos, listados abaixo, dever�o estar em um
			ENUMERATION, sendo que o valor armazenado ser� o n�mero inteiro,
			mas na hora de mostrar, dever� mostrar o nome do curso. ----> FEITO
		
				1 - An�lise e Desenvolvimento de Sistemas
				2 - Ci�ncia da Computa��o
				3 - Ci�ncia de Dados
				4 - Gest�o da Tecnologia da Informa��o
				5 - Redes de Computadores
				6 - Sistemas Para Internet
*/
// enumeration para o curso
typedef enum {
	Analise_Desenvolvimento_de_Sistemas = 1,
	Ciencia_da_Computacao = 2,
	Ciencia_de_Dados = 3,
	Gestao_de_Tecnologia_da_Informacao = 4,
	Redes_de_Computadores = 5,
	Sistemas_Para_Internet = 6 
}Num_Curso;

// estrutura para o cadastro
typedef struct{
	
	Num_Curso curso;
	char *nome;
	int rgm;
	
}t_Cadastro;

// prot�tipos de fun��o
int tamCadastro(); // fun��o que retorna o tamanho do array de cadastros

// CRUD

int create(t_Cadastro *cadastros, int qtd, int tam); // fun��o para criar novo cadastro
void read(t_Cadastro *cadastros, int qtd); // procedimento para mostrar os cadastros feitos
void update(t_Cadastro *cadastros, int qtd, int tam); // procedimento para atualizar um cadastro
int deletar(t_Cadastro *cadastros, int qtd, int tam); // procedimento para deletar um cadastro

// main
int main(){
	setlocale(0, "Portuguese");
	// vari�veis
	t_Cadastro *cadastros;
	
	int tam = tamCadastro(); // tamanho total do array
	int qtd = 0; // quantos alunos j� foram cadastrados
	int i, opc;
	
	// alocar dinamicamente quantos cadastros ser�o feitos
	cadastros = (t_Cadastro *)malloc(sizeof(t_Cadastro) * tam);
	
	system("cls");
	
	// loop principal
	do{
		system("cls");
		printf("\tCADASTRO DE ALUNOS\n\t--------------------\n");
		printf("\tAlunos cadastrados: %d de %d\n\t--------------------\n", qtd, tam);
		printf("\tSelecione uma op��o:\n\t[1]Cadastrar novo aluno\n\t[2]Ler cadastros\n\t[3]Atualizar cadastros\n\t[4]Deletar cadastro\n\t[5]Sair\n\n\tInforme: ");
		scanf("%d", &opc);
		fflush(stdin);
		
		switch(opc){
			case 1:
				qtd = create(cadastros, qtd, tam);
				break;
			case 2:
				read(cadastros, qtd);
				printf("\n\tPressione ENTER para voltar ao menu...\n");
    			while(getchar() != '\n');
				break;
			case 3:
				update(cadastros, qtd, tam);
				break;
			case 4:
				qtd = deletar(cadastros, qtd, tam);
				break;
			case 5:
				printf("\n\n\tAdeus!\n");
				break;
			default:
				printf("\tValor Inv�lido!\n");
				break;
		}
		
	}while(opc != 5);
	
	free(cadastros);
	
	return 0;
}

// fun��o que retorna o tamanho do array de cadastros
int tamCadastro(){
	int tam, result;
	printf("\tQuantos alunos tem na turma (m�ximo de cadastros que ser�o permitidos)? ");
	result = scanf("%d", &tam);
	fflush(stdin);
	
	
	while(result != 1 || tam < 0 || tam > 60){
		printf("\n\tValor Inv�lido. Insira um valor maior que 0 ou menor que 60.");
		result = scanf("%d", &tam);
		fflush(stdin);
	}
	
	return tam;
}

// fun��o para criar novo cadastro
int create(t_Cadastro *cadastros, int qtd, int tam){
	char novoNome[1024];
	int i = qtd;
	char opc;
	
	if(qtd >= tam){
		printf("\n\tTamanho m�ximo da turma alcan�ado! Imposs�vel fazer novo cadastro.\n\n");
		printf("\tPressione ENTER para voltar ao menu...");
		while(getchar() != '\n');
		return qtd;
	}
	else{
		do{
			system("cls");
			printf("\n\tInsira o nome do aluno: ");
			scanf("%1024[^\n]", novoNome);
			fflush(stdin);
			
			printf("\n\tInsira o RGM: ");
			scanf("%d", &cadastros[i].rgm);
			fflush(stdin);
			
			printf("\n\tSelecione o curso:\n\n\t1 - An�lise e Desenvolvimento de Sistemas\n\t2 - Ci�ncia da Computa��o\n\t3 - Ci�ncia de Dados\n");
			printf("\t4 - Gest�o da Tecnologia da Informa��o\n\t5 - Redes de Computadores\n\t6 - Sistemas Para Internet\n\n\tInforme: ");
			scanf("%d", &cadastros[i].curso);
			fflush(stdin);
			
			// alocando mem�ria dinamicamente para o tamanho exato do nome
			cadastros[i].nome = (char *)malloc(strlen(novoNome) + 1);
			
			strcpy(cadastros[i].nome, novoNome);
			
			i++;
			
			if(i < tam){
				printf("\n\tCadastrar outro aluno[S/N]? ");
				scanf(" %c", &opc);
				fflush(stdin);
				opc = toupper(opc);
				
				
				if(opc != 'N' && opc != 'S')
					printf("\tResposta inv�lida! Responda com S ou N.\n");
			}
			else
				printf("\n\tM�ximo de cadastros atingidos para a turma.\n");
		}while(opc != 'N' && i < tam);
		
		printf("\tPressione ENTER para voltar ao menu...");
		while(getchar() != '\n');
		
		return i;
	}
}

// procedimento para mostrar os cadastros feitos:
void read(t_Cadastro *cadastros, int qtd) {
	system("cls");
    if (cadastros == NULL || qtd <= 0) 
        printf("\tNenhum cadastro feito at� o momento.\n");
	else{
	    for (int i = 0; i < qtd; i++) {
	    	printf("\tALUNO %d\n\t--------------", i+1);
	        printf("\n\tNome: %s\n", cadastros[i].nome);
	        printf("\tRGM: %d\n", cadastros[i].rgm);
	        printf("\tCurso: ");
	
	        switch (cadastros[i].curso) {
	            case Analise_Desenvolvimento_de_Sistemas:
	                printf("An�lise e Desenvolvimento de Sistemas");
	                break;
	            case Ciencia_da_Computacao:
	                printf("Ci�ncia da Computa��o");
	                break;
	            case Ciencia_de_Dados:
	                printf("Ci�ncia de Dados");
	                break;
	            case Gestao_de_Tecnologia_da_Informacao:
	                printf("Gest�o de Tecnologia da Informa��o");
	                break;
	            case Redes_de_Computadores:
	                printf("Redes de Computadores");
	                break;
	            case Sistemas_Para_Internet:
	                printf("Sistemas Para Internet");
	                break;
	            default:
	                printf("Curso desconhecido");
	                break;
	        }
	        printf("\n\t--------------\n");
	    }
	}
}

// procedimento para atualizar os cadastros
void update(t_Cadastro *cadastros, int qtd, int tam){
	char novoNome[1024];
	int i;
	char opc;
	
	system("cls");
	if (cadastros == NULL || qtd <= 0) 
        printf("\n\tNenhum cadastro feito at� o momento.\n\n");
        
    else{
		do{
			system("cls");
			
			read(cadastros, qtd); // chamar a leitura para mostrar os alunos j� cadastrados
			
			// selecionar o aluno a ter os dados alterados
			printf("\n\n\tSelecione o n�mero do aluno o qual deseja atualizar o cadastro: ");
			scanf("%d", &i);
			fflush(stdin);
			i--; // decrementa 1 do �ndice do aluno, para ficar de acordo com a posi��o real do array que come�a em 0
			
			while(i >= qtd && i < 0){
				printf("\n\tValor inv�lido!");
				printf("\n\n\tSelecione um n�mero v�lido do aluno o qual deseja atualizar o cadastro: ");
				scanf("%d", &i);
				fflush(stdin);
				i--;
			}
			
			printf("\n\tInsira o nome do aluno: ");
			scanf("%1024[^\n]", novoNome);
			fflush(stdin);
			
			printf("\n\tInsira o RGM: ");
			scanf("%d", &cadastros[i].rgm);
			fflush(stdin);
			
			printf("\n\tSelecione o curso:\n\n\t1 - An�lise e Desenvolvimento de Sistemas\n\t2 - Ci�ncia da Computa��o\n\t3 - Ci�ncia de Dados\n");
			printf("\t4 - Gest�o da Tecnologia da Informa��o\n\t5 - Redes de Computadores\n\t6 - Sistemas Para Internet\n\n\tInforme: ");
			scanf("%d", &cadastros[i].curso);
			fflush(stdin);
			
			// alocando mem�ria dinamicamente para o tamanho exato do nome
			cadastros[i].nome = (char *)malloc(strlen(novoNome) + 1);
			
			strcpy(cadastros[i].nome, novoNome);
		

			printf("\n\tAtualizar outro cadastro[S/N]? ");
			scanf(" %c", &opc);
			fflush(stdin);
			opc = toupper(opc);
			
			
			if(opc != 'N' && opc != 'S')
				printf("\tResposta inv�lida! Responda com S ou N.\n");
		
		}while(opc != 'N');
	}
		
		printf("\tPressione ENTER para voltar ao menu...");
		while(getchar() != '\n');
}

// fun��o para deletar cadastros
int deletar(t_Cadastro *cadastros, int qtd, int tam){
	int i, j;
	char opc;
	char *auxChar;
	t_Cadastro auxInt;
	
	system("cls");
	if (cadastros == NULL || qtd <= 0) 
        printf("\n\tNenhum cadastro feito at� o momento.\n\n");
        
    else{
		do{
			system("cls");
			
			read(cadastros, qtd); // chamar a leitura para mostrar os alunos j� cadastrados
			
			// selecionar o aluno a ter os dados alterados
			printf("\n\n\tSelecione o n�mero do aluno o qual deseja deletar: ");
			scanf("%d", &i);
			fflush(stdin);
			i--; // decrementa 1 do �ndice do aluno, para ficar de acordo com a posi��o real do array que come�a em 0
			
			while(i >= qtd || i < 0){
				printf("\n\tValor inv�lido!");
				printf("\n\n\tSelecione um n�mero v�lido do aluno o qual deseja deletar o cadastro: ");
				scanf("%d", &i);
				fflush(stdin);
				i--;
			}
			
			for(j = i; j < qtd - 1; j++){
				cadastros[j].nome = cadastros[j+1].nome;
				cadastros[j].rgm = cadastros[j+1].rgm;
				cadastros[j].curso = cadastros[j+1].curso;
			}
			
			free(cadastros[i].nome);
			
			qtd--;
			
			read(cadastros, qtd);

			printf("\n\tDeletar outro cadastro[S/N]? ");
			scanf(" %c", &opc);
			fflush(stdin);
			opc = toupper(opc);
			
			
			if(opc != 'N' && opc != 'S')
				printf("\tResposta inv�lida! Responda com S ou N.\n");
		
		}while(opc != 'N');
	}
		
		printf("\tPressione ENTER para voltar ao menu...");
		while(getchar() != '\n');
		
		return qtd;
}

