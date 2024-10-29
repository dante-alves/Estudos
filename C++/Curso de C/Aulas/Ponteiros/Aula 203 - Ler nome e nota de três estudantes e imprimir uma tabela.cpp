#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Aula 203 - Ler nome e nota de três estudantes e imprimir uma tabela

typedef struct{
	char nome[30];
	float nota;
}Alunos;

void lerDados(Alunos *aluno, int tam){
	int i;
	
	for(i = 0; i < tam; i++){
		printf("Nome do %d aluno: ", i+1);
		scanf("%30[^\n]", aluno[i].nome);
		scanf("%c");
		
		printf("Nota do %d aluno: ", i+1);
		scanf("%f", &aluno[i].nota);
		scanf("%c");
		
		printf("-----------------------\n");
}
}

void imprimirTabela(Alunos *aluno, int tam){
	int i;
	printf("\n\t\tBOLETIM DOS ALUNOS\n");
	printf("\t----------------------------------\n");
	printf("\t|\tNOME\t |\tNOTA\t |\n");
	printf("\t----------------------------------\n");
	for(i = 0; i < 3; i++){
		printf("\t|\t%s\t |\t%.1f\t |\n", aluno[i].nome, aluno[i].nota);
		printf("\t----------------------------------\n");
	}
}

int main(){
	//Variável
	Alunos *aluno;
	
	//Alocando memória dinâmica
	aluno =  (Alunos *)malloc(3 * sizeof(Alunos));
	
	//Verificando se aluno não é nulo e executando o programa
	if(aluno){
		lerDados(aluno, 3);// Proced. de ler os dados
		
		imprimirTabela(aluno, 3);// Proced. de imprimir a tabela
		
		free(aluno);// Limpar a memória alocada para o vetor aluno.

	}
	else{
		printf("Erro na alocacao de memoria!");
	}

	return 0;
}
