#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

/*			11. 
			-> Escreva um programa em C, totalmente dinâmico, para realizar as
			quatro operações (CRUD) de um cadastro de alunos: Create, Read,
			Update e Delete. 
			
			-> Cada operação deverá estar em uma função. 
			
			-> Deverá ter uma função para mostrar o cadastro inteiro. ----> FEITO
			
			-> O cadastro deverá armazenar nome completo, RGM e curso. ----> FEITO
			 
			-> O nome deverá ser coletado do teclado e armazenado em uma área estática temporária
			de tamanho 1024 caracteres. ----> FEITO
				- Após ter o nome, alocar a área exata que irá guardar o nome. ----> FEITO
				
				
			-> Os cursos, listados abaixo, deverão estar em um
			ENUMERATION, sendo que o valor armazenado será o número inteiro,
			mas na hora de mostrar, deverá mostrar o nome do curso. ----> FEITO
		
				1 - Análise e Desenvolvimento de Sistemas
				2 - Ciência da Computação
				3 - Ciência de Dados
				4 - Gestão da Tecnologia da Informação
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

// protótipos de função
int tamCadastro(); // função que retorna o tamanho do array de cadastros

// CRUD

int create(t_Cadastro *cadastros, int qtd, int tam); // função para criar novo cadastro
void read(t_Cadastro *cadastros, int qtd); // procedimento para mostrar os cadastros feitos
	

// main
int main(){
	setlocale(0, "Portuguese");
	// variáveis
	t_Cadastro *cadastros;
	
	int tam = tamCadastro(); // tamanho total do array
	int qtd = 0; // quantos alunos já foram cadastrados
	int i, opc;
	
	// alocar dinamicamente quantos cadastros serão feitos
	cadastros = (t_Cadastro *)malloc(sizeof(t_Cadastro) * tam);
	
	system("cls");
	
	// loop principal
	do{
		system("cls");
		printf("\tCADASTRO DE ALUNOS\n\t--------------------\n");
		printf("\tAlunos cadastrados: %d\n\t--------------------\n", qtd);
		printf("\tSelecione uma opção:\n\t[1]Cadastrar novo aluno\n\t[2]Ler cadastros\n\t[3]Atualizar cadastros\n\t[4]Deletar cadastro\n\t[5]Sair\n\n\tInforme: ");
		scanf("%d", &opc);
		fflush(stdin);
		
		switch(opc){
			case 1:
				qtd = create(cadastros, qtd, tam);
				break;
			case 2:
				read(cadastros, qtd);
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				printf("\n\n\tAdeus!\n");
				break;
			default:
				printf("\tValor Inválido!\n");
				break;
		}
		
	}while(opc != 5);
	
	free(cadastros);
	
	return 0;
}

// função que retorna o tamanho do array de cadastros
int tamCadastro(){
	int tam;
	printf("\tQuantos alunos tem na turma (máximo de cadastros que serão permitidos)? ");
	scanf("%d", &tam);
	fflush(stdin);
	
	return tam;
}

// função para criar novo cadastro
int create(t_Cadastro *cadastros, int qtd, int tam){
	char novoNome[1024];
	int i = qtd;
	char opc;
	
	if(qtd >= tam){
		printf("\n\tTamanho máximo da turma alcançado! Impossível fazer novo cadastro.\n\n");
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
			
			printf("\n\tSelecione o curso:\n\n\t1 - Análise e Desenvolvimento de Sistemas\n\t2 - Ciência da Computação\n\t3 - Ciência de Dados\n");
			printf("\t4 - Gestão da Tecnologia da Informação\n\t5 - Redes de Computadores\n\t6 - Sistemas Para Internet\n\n\tInforme: ");
			scanf("%d", &cadastros[i].curso);
			fflush(stdin);
			
			// alocando memória dinamicamente para o tamanho exato do nome
			cadastros[i].nome = (char *)malloc(strlen(novoNome) + 1);
			
			strcpy(cadastros[i].nome, novoNome);
			
			i++;
			
			if(i < tam){
				printf("\n\tCadastrar outro aluno[S/N]? ");
				scanf(" %c", &opc);
				fflush(stdin);
				opc = toupper(opc);
				
				
				if(opc != 'N' && opc != 'S')
					printf("\tResposta inválida! Responda com S ou N.\n");
			}
			else
				printf("\n\tMáximo de cadastros atingidos para a turma.\n");
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
        printf("\tNenhum cadastro feito até o momento.\n");
	else{
	    for (int i = 0; i < qtd; i++) {
	    	printf("\tALUNO %d\n\t--------------", i+1);
	        printf("\n\tNome: %s\n", cadastros[i].nome);
	        printf("\tRGM: %d\n", cadastros[i].rgm);
	        printf("\tCurso: ");
	
	        switch (cadastros[i].curso) {
	            case Analise_Desenvolvimento_de_Sistemas:
	                printf("Análise e Desenvolvimento de Sistemas");
	                break;
	            case Ciencia_da_Computacao:
	                printf("Ciência da Computação");
	                break;
	            case Ciencia_de_Dados:
	                printf("Ciência de Dados");
	                break;
	            case Gestao_de_Tecnologia_da_Informacao:
	                printf("Gestão de Tecnologia da Informação");
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
	        printf("\n\n\t--------------");
	    }
	}
    
    printf("\n\tPressione ENTER para voltar ao menu...\n");
    while(getchar() != '\n');
}

