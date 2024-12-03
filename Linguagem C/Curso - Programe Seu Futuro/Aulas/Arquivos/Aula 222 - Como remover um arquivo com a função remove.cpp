#include <stdio.h>
#include <stdlib.h>

//Aula 222 - Como remover um arquivo com a função remove

int main(){
	
	//Variável
	char nome[50]; 
	
	//Criação do arquivo
	
	printf("Digite o nome de um arquivo para deletar. Ex: nome.txt\n"); 
	scanf("%49[^\n]", nome); //Coleta do nome
	getchar();
	
	FILE *file = fopen(nome, "w"); //Abertura do arquivo
	
	printf("\nPressione ENTER para confirmar a remocao do arquivo %s...\n", nome);
	getchar();
	
	if(file){
		fclose(file); //Tem que fechar o arquivo antes de remover	
		remove(nome); //Remoção do arquivo
		printf("Arquivo deletado com sucesso.");
			
	}
	else
		printf("Erro ao identificar o arquivo.");
	
	
	return 0;
}
