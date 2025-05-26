#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


#define F "alunos.txt"
#define Fbase "alunosBase.txt"

typedef struct {
	char nome[50];
	char rgm[10];
}Aluno;

typedef struct no{
	struct no *direita;
	struct no *esquerda;
	Aluno aluno;	
}No;

void cleanBuffer() {
	int c; // pegar um inteiro.
	while((c = getchar()) != '\n' && c != EOF); // \n -> 10 | EOF -> -1
	
	// vai pegar os caracteres do buffer até encontrar ou \n ou EOF.
}

// funcao para pegar parte do nome e validar
int nameIsValid(char *parteDoNome) {	
	for (int i = 0; i < strlen(parteDoNome); i++) {
		// compara cada caractere de acordo com a tabela ascii
		if((parteDoNome[i] < 'A' || parteDoNome[i] > 'Z') 
		&& (parteDoNome[i] < 'a' || parteDoNome[i] > 'z') )  
			return 0; // nome no  valido
	}
	
	return 1; // nome e valido
}

// funcao para retornar a validacao do caractere.
bool validarCaractere(char caractere) {	
	return !((caractere >= 'A' && caractere <= 'Z') || (caractere >= 'a' && caractere <= 'z'));
	
	// retorna o oposto
	// se nao estiver dentro dos parametros -> retorna true.
}

// funcao para validar o nome
bool validarNome(char *nome) {
	bool validacao;
	
	
	for(int i = 0; i < strlen(nome); i++) {
		validacao = validarCaractere(nome[i]);
		
		// se o usu digitar espaco no 1 caractere -> retorna falso.
		if(nome[0] == ' ')
			return false;
		
		// caso seja o espao verificar o caractere anterior e depois
		if(nome[i] == ' ') {
				
				// se o caractere depois for == igual a '\0' ou ' ' ->  invalido
				/*
					Ex:
						a ' ' \0 -> invalido
						a ' ' ' ' -> invalido
						a \0 -> valido
				*/
				if(nome[i + 1] == '\0'|| nome[i + 1] == ' ') 
					return false;		
					
			// verificar a validao do caractere anterior e depois
			return !(validarCaractere(nome[i - 1]) && validarCaractere(nome[i + 1]));
		}
		
			
		if(validacao)
			return false;
	}
	
	
	return true;
}

int validarRGM(char *rgm) {
	for(int i = 0; i < 9; i++) {
		if(rgm[i] < '0' || rgm[i] > '9')
			return 0; // RGM INVALIDO
	}
	
	// validou o RGM
	return 1;
}

Aluno lerAluno() {
	Aluno novo;
	
	printf("Insira o nome do aluno: ");
	
	scanf("%49[^\n]", novo.nome);
	cleanBuffer();
	while(!validarNome(novo.nome)) {
		printf("\nNome inválido... Insira um nome com caracteres válidos.\n");
		printf("Nome: ");
		scanf("%49[^\n]", novo.nome);
		cleanBuffer();
	}
	
	printf("Insira o RGM do aluno: ");
	scanf("%9[^\n]", novo.rgm);
	cleanBuffer();
	
	while(!validarRGM(novo.rgm)) {
		printf("\nRGM inválido! Insira um RGM com apenas números!\n");
		printf("RGM: ");
		scanf("%9[^\n]", novo.rgm);
		cleanBuffer();
	}
	
	return novo;
}

No* inserir(No *arvore, Aluno aluno){
	No *novo = (No *)malloc(sizeof(No));

	if(novo){
		
		if(arvore == NULL){
			novo->aluno = aluno;
			novo->direita = NULL;
			novo->esquerda = NULL;
			
			return novo;
		}
		
		int comparacao = strcmp(aluno.rgm, arvore->aluno.rgm);
		
		if(comparacao < 0){ // caso o RGM seja menor, vai para a ESQUERDA
			arvore->esquerda = inserir(arvore->esquerda, aluno);
		}
		else{ // se não, vai para a DIREITA
			arvore->direita = inserir(arvore->direita, aluno);
		}
		return arvore;
	}
	else
		printf("\nErro ao alocar memória.");
	
	return NULL;
}


// inserir sem retorno
void inserir2(No **arvore, Aluno aluno){
	if(*arvore == NULL){
		*arvore = (No *)malloc(sizeof(No));
		(*arvore)->aluno = aluno;
		(*arvore)->esquerda = NULL;
		(*arvore)->direita = NULL;
	}
	else{
		if(strcmp(aluno.rgm, (*arvore)->aluno.rgm) < 0)
			inserir2(&((*arvore)->esquerda), aluno);
		else
			inserir2(&((*arvore)->direita), aluno);
	}
}

// inserir sem recursão, só iterativo
//void inserir3(No **arvore, int num){
//	No *aux = *arvore;
//	while(aux){
//		if(num < aux->valor)
//			arvore = &aux->esquerda;
//		else
//			arvore = &aux->direita;
//		
//		aux = *arvore;
//	}
//	aux = (No *)malloc(sizeof(No));
//	aux->valor = num;
//	aux->esquerda = NULL;
//	aux->direita = NULL;
//	
//	*arvore = aux;
//}

No *busca_recursiva(No *arvore, char *rgm){
	
	if(arvore == NULL)
		return NULL;
		
	int comparacao = strcmp(rgm, arvore->aluno.rgm);	
	
	if(comparacao == 0)
		return arvore;
	
	if(comparacao < 0)
		return busca_recursiva(arvore->esquerda, rgm);
	else
		return busca_recursiva(arvore->direita, rgm);
}

//No* busca_iterativa(No *arvore, int num){
//	No *aux;
//	
//	while(arvore){
//		if(num < arvore->valor)
//			arvore = arvore->esquerda;
//		else if(num > arvore->valor)
//			arvore = arvore->direita;
//		else
//			return arvore;
//	}
//	
//	return NULL;
//}


//int contarNos(No *arvore){
//	if(arvore == NULL)
//		return 0;
//	else
//		return 1 + contarNos(arvore->esquerda) + contarNos(arvore->direita);
//	
//	// return (arvore == NULL) ? 0 : 1 + contarNos(arvore->esquerda) + contarNos(arvore->direita);
//}

//int contarFolhas(No *arvore){
//	if(arvore == NULL)
//		return 0;
//	else if(arvore->esquerda == NULL && arvore->direita == NULL)
//		return 1;
//	else	
//		return contarFolhas(arvore->esquerda) + contarFolhas(arvore->direita);
//	
//}

int ehFolha(No *arvore){
	return (arvore->direita == NULL && arvore->esquerda == NULL);
}

No* remover(No *arvore, char *rgm){
	if(arvore == NULL)
	{
		printf("\n\tValor não encontrado!\n");
		return NULL;
	}
	int comparacao = strcmp(rgm, arvore->aluno.rgm);
	if(comparacao == 0){
		if(ehFolha(arvore)){
			printf("\n\tAluno %s, de RGM %s removido.\n", arvore->aluno.nome, arvore->aluno.rgm);
			free(arvore);
			return NULL;
		}
		else
		{
			if(arvore->direita && arvore->esquerda)
			{
				// pegar o sucessor
				No *aux = arvore->direita;
				
				while(aux->esquerda != NULL)
					aux = aux->esquerda;
				
				arvore->aluno = aux->aluno;
				arvore->direita = remover(arvore->direita, aux->aluno.rgm);
				
				return arvore;	
			}
			else
			{
				No *filho;
				
				if(arvore->direita)
					filho = arvore->direita;	
				else
					filho = arvore->esquerda;
				
				printf("\n\tAluno %s removido.\n", arvore->aluno.nome);
				
				free(arvore);
				
				return filho;
			}
		}
		
	}
		
		if(comparacao > 0)
			arvore->direita = remover(arvore->direita, rgm);
		else
			arvore->esquerda = remover(arvore->esquerda, rgm);	
		
		return arvore;
}



void esvaziarArvore(No **arvore) {
	
	if (*arvore == NULL)
		return;
	
	esvaziarArvore(&(*arvore)->esquerda);
	esvaziarArvore(&(*arvore)->direita);
	free(*arvore);
	*arvore = NULL;
}


int imprimirPre(No *arvore){
	if(arvore){
		printf("\n\tNome: %s\tRGM: %s", arvore->aluno.nome, arvore->aluno.rgm);
		imprimirPre(arvore->esquerda);
		imprimirPre(arvore->direita);
	}
	return 0;
}

int imprimirIn(No *arvore){
	if(arvore){
		imprimirIn(arvore->esquerda);
		printf("\n\tNome: %s\tRGM: %s", arvore->aluno.nome, arvore->aluno.rgm);
		imprimirIn(arvore->direita);
	}
	return 0;
}

int imprimirPos(No *arvore){
	if(arvore){
		imprimirPos(arvore->esquerda);
		imprimirPos(arvore->direita);
		printf("\n\tNome: %s\tRGM: %s", arvore->aluno.nome, arvore->aluno.rgm);
	}
	return 0;
}

int menuExibir(No *arvore) {
	printf("Exibir em qual ordem?\n\t1 - Pré Ordem\n\t2 - In Ordem\n\t3 - Pós Ordem\n");
	int opc;
	scanf("%d", &opc);
	
	switch(opc) {
		case 1: imprimirPre(arvore); break;
		case 2: imprimirIn(arvore); break;
		case 3: imprimirPos(arvore); break;
		default:
			printf("Opção inválida.");
	}
	
	return 0;
}

void writeAluno(No *arvore, FILE *file) {
	if(arvore) {
			writeAluno(arvore->esquerda, file);
			fprintf(file, "%s|%s\n", arvore->aluno.nome, arvore->aluno.rgm);
			writeAluno(arvore->direita, file);
		}
}

void writeFile(No *arvore) {
	FILE *file = fopen(F, "w+"); 
	
	No *aux = arvore;
	
	if(file) {
		fprintf(file, "Nome\t\tRGM\n\n");
		writeAluno(arvore, file);
		fclose(file);
	}
	else
		printf("Erro ao abrir o arquivo!");
	
}

Aluno readAluno(FILE *file) {
	Aluno aluno;
	
	if(fscanf(file, "%49[^|]|%9[^\n]\n", aluno.nome, aluno.rgm) == 2) 
		return aluno;
		
	else {
		aluno.nome[0] = '\0';
		aluno.rgm[0] = '\0';
		return aluno;
	}
}

No* readFile(int type){
	FILE *file;
	
	if (type == 1) file = fopen(F, "r");
	else file = fopen(Fbase, "r");
	
	No *arvore = NULL;
	
	if(file){
		fscanf(file, "Nome\t\tRGM\n\n");
		
		while(!feof(file)) {
			Aluno aluno = readAluno(file);
			arvore = inserir(arvore, aluno);
		}
		
		fclose(file);
		
		return arvore;
	}
	else
		printf("Erro ao abrir o arquivo...");
	
	return NULL;
}

int main(){
	setlocale(0, "Portuguese");
	
	No *arvore = readFile(1);
	
	if(arvore == NULL)
		arvore = readFile(2);
	
	No *buscado;
	int opc;
	
	char rgm[10];
	
	do{
		printf("\n\t1 - Inserir\n\t2 - Remover\n\t3 - Buscar\n\t4 - Esvaziar árvore\n\t5 - Exibir\n\t0 - Sair\n\n\tInforme: ");
		scanf("%d", &opc);
		cleanBuffer();
		
		switch(opc){
			case 1:
				arvore = inserir(arvore, lerAluno());
				break;
			case 2:
				printf("\n\tDigite o RGM do aluno que quer remover: ");
				scanf("%9[^\n]", &rgm);
				arvore = remover(arvore, rgm);
				break;
			case 3:
				printf("\n\tDigite o RGM do aluno: ");
				scanf("%9[^\n]", rgm);
				buscado = busca_recursiva(arvore, rgm);
				
				if(buscado)
					printf("\n\tAluno de RGM %s encontrado.\n", buscado->aluno.rgm);
				else
					printf("\n\tAluno não encontrado!\n");
					
				break;
			case 4: 
				esvaziarArvore(&arvore);
				printf("\n\tÁrvore esvaziada com sucesso.\n");
				break;
			case 5:
				printf("\n\t");
				menuExibir(arvore);
				printf("\n");
				break;
			case 0: printf("\n\tGood morning, and in case I don't see ya, good afternoon, good evening, and good night.\n"); 
				break;
			default: printf("\n\tOpção inválida.\n"); 
		}
	}while(opc != 0);
	
	writeFile(arvore);
	
	return 0;
}
