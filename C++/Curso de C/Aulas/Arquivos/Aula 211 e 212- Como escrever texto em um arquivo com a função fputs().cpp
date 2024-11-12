#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Aula 210 - Escrita em arquivo com a função fputs() e leitura com fgets()

/*Modos de abertura de arquivos:
	w -> Escrita
	r -> Leitura
	a -> Anexar
	r+ -> Leitura e Escrita
	w+ -> Leitura e Escrita (Apaga o conteúdo caso o arquivo exista)
	a+ -> Leitura e Escrita (Anexa o que for escrito no final do arquivo)
*/

void escrever(char f[]){
	FILE *file = fopen(f, "w");
	char texto[500];
	
	
	if(file){
		printf("Arquivo aberto com sucesso. Digite um texto e pressione ENTER para adicioná-lo ao arquivo.\nDigite 1 caracter se quiser finalizar.\n");
		
		scanf("%500[^\n]", texto);
		scanf("%c");
		while(strlen(texto) > 1){
			
			
			fputs(texto, file);
			fputc('\n', file);
			
			scanf("%500[^\n]", texto);
			scanf("%c");
		}

		
		printf("Texto salvo com sucesso! :]");
		
		fclose(file);
	}
	else 
		printf("Erro ao abrir o arquivo...");
}



void ler(char f[]){
	FILE *file = fopen(f, "r");
	char texto[500];
	
	if(file){
		
		printf("\nTexto lido do arquivo: \n");
		while(!feof(file)){
			if(fgets(texto, 500, file))
				printf("%s", texto);
		}
	}
	else
		printf("Erro ao abrir o arquivo...");
	
	fclose(file);
}

int main(){
	char file_name[50];
	char opc;
	
	printf("Digite o nome do arquivo: ");
	scanf("%50[^\n]", file_name);
	scanf("%c");
	
	strcat(file_name, ".txt");

	escrever(file_name);
	
	printf("\nGostaria de ler o que foi escrito? digite S para sim: ");
	scanf("%c", &opc);
	
	if(opc == 'S')
		ler(file_name);

	return 0;
}
