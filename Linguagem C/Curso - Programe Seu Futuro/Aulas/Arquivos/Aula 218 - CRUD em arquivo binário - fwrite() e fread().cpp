#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Aula 218 e 219 - Escrevendo e lendo em arquivo binário com a função fwrite() e fread() 

CRUD COMPLETO COM ARQUIVO BINÁRIO
	
	Modos de abertura de arquivos:
	wb -> Escrita
	rb -> Leitura
	ab -> Anexar
	rb+ -> Leitura e Escrita
	wb+ -> Leitura e Escrita (Apaga o conteúdo caso o arquivo exista)
	ab+ -> Leitura e Escrita (Adiciona ao final do arquivo)

*/

typedef struct{
	char nome[50];
	int dia, mes, ano;
}t_Contato;

void escrever(char f[]){
	t_Contato c;
	FILE *file = fopen(f, "ab");
	
	if(file){
		printf("Digite o nome e a data de nascimento dd/mm/aaaa: ");
		scanf("%49[^\n]%d/%d/%d", c.nome, &c.dia, &c.mes, &c.ano);
		fwrite(&c, sizeof(t_Contato), 1, file);
		fclose(file);
	}
	else
		printf("\nErro ao abrir arquivo!\n");
}

void ler(char f[]){
	t_Contato c;
	FILE *file = fopen(f, "rb");
	
	if(file){
		while(!feof(file)){
			if(fread(&c, sizeof(t_Contato), 1, file)) //Se o retorno da função fread for 1, significa que tem mais coisas a serem printadas
				printf("\nNome: %s\nData: %d/%d/%d\n", c.nome, c.dia, c.mes, c.ano);
		}
		fclose(file);
	}
	else
		printf("\nErro ao abrir arquivo!\n");
}
void atualizar(char f[]){
	t_Contato c;
	t_Contato novo_c;
	
	FILE *file = fopen(f, "rb");
	FILE *temp = fopen("temp.dat", "wb");
	
	char nome_atualizar[100];
	
	if(file && temp){
		// selecionar nome já existente na lista para modificar
		printf("Insira o nome do contato que deseja modificar: ");
		scanf(" %99[^\n]", nome_atualizar);
		
		// coletando novos dados
		printf("Insira o novo nome: ");
		scanf(" %99[^\n]", novo_c.nome);
		printf("Insira a nova data de nascimento: ");
		scanf("%d/%d/%d", &novo_c.dia, &novo_c.mes, &novo_c.ano);
		
		while(fread(&c, sizeof(t_Contato), 1, file)){
			if(strcmp(c.nome, nome_atualizar) != 0)
				fwrite(&c, sizeof(t_Contato), 1, temp);
			else
				fwrite(&novo_c, sizeof(t_Contato), 1, temp); // quando o nome for igual ao que foi selecionado para ser alterado, ele vai passar os dados de novo_c.
		}
		
		fclose(file);
		fclose(temp);
		
		remove(f);
		rename("temp.dat", f);
		printf("Contato atualizado com sucesso!");
	}
	else{
		printf("\nErro ao abrir arquivo!");
		if(file) fclose(file);
		if(temp) fclose(temp);
	}
}
void remover(char f[]){
	t_Contato c;
	FILE *file = fopen(f, "rb"); // abrir o arquivo principal
	FILE *temp = fopen("temp.dat", "wb"); // arquivo temporário que vai substituir o principal no futuro

	char nome_removido[100]; // variável para armazenar o nome que será removido
	
	
	if(file && temp){
		// ler o nome
		printf("Digite o nome a ser removido: ");
		scanf(" %99[^\n]", nome_removido);
		
		// adicionar os dados para o novo arquivo, removendo o nome escolhido
		while(fread(&c, sizeof(t_Contato), 1, file)){ // enquanto fread() retorna 1, significa que ainda tem dados a serem lidos
			if(strcmp(c.nome, nome_removido) != 0) // se os nomes forem diferentes, executa o fwrite no arquivo temporário
				fwrite(&c, sizeof(t_Contato), 1, temp);
		}
		// fechar ambos os arquivos
		fclose(file);
		fclose(temp);
		
		remove(f); // remover o arquivo anterior
		rename("temp.dat", f); // renomear o arquivo temporário para se tornar o principal
		
		printf("\nContato removido com sucesso!");
	}
	else{
		printf("\nErro ao abrir o arquivo.");
		fclose(file);
		fclose(temp);
	}
}
int main(){
	char nome_arquivo[] = {"agenda.dat"};
	
	escrever(nome_arquivo);
	
	ler(nome_arquivo);
	
	remover(nome_arquivo);
	
	ler(nome_arquivo);
	
	atualizar(nome_arquivo);
	
	ler(nome_arquivo);
	
	return 0;
}
