#include <stdio.h>
#include <stdlib.h>

//Aula 210 - Leitura e escrita em arquivo com funções e procedimentos

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
	char letra;
	
	
	if(file){
		printf("Arquivo aberto com sucesso. Digite um texto e pressione ENTER para adicioná-lo ao arquivo: ");
		scanf(" %c", &letra);

		/*Para adicionar com string, era só fazer
		scanf("%100[^\n]", texto);
		fputs(texto, arquivo);*/
		
		while(letra != '\n'){
			fputc(letra, file);
			scanf("%c", &letra);
		}
		
		printf("Texto salvo com sucesso! :]");
		fclose(file);
	}
	else 
		printf("Erro ao abrir o arquivo...");
}

void ler(char f[]){
	FILE *file = fopen(f, "r");
	char letra;
	
	if(file){
		
		printf("\nTexto lido do arquivo: \n");
		
		while(!feof(file)){ //Função feof retorna verdadeiro se tiver chegado ao fim do arquivo. Por Isso o uso da negação no while 
			letra = fgetc(file); //Função que pega o texto do arquivo 
			printf("%c", letra);
		}
	}
	else
		printf("Erro ao abrir o arquivo...");
	
	fclose(file);
}

int main(){
	char file_name[] = {"Conto"};
	
	escrever(file_name);
	
	ler(file_name);
	

	return 0;
}
