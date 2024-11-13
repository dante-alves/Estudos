#include <stdio.h>
#include <stdlib.h>

/*Aula 218 e 219 - Escrevendo e lendo em arquivo binário com a função fwrite() e fread()
	
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

int main(){
	char nome_arquivo[] = {"agenda.dat"};
	
	escrever(nome_arquivo);
	
	ler(nome_arquivo);
		
	return 0;
}
