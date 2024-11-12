#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//Ler ou Escrever

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
		printf("Arquivo aberto com sucesso. Digite um texto e pressione ENTER para pular uma linha.\nDigite 1 caracter se quiser finalizar.\n");
		
		scanf("%500[^\n]", texto);
		scanf("%c");
		while(strlen(texto) > 1){
			
			
			fputs(texto, file);
			fputc('\n', file);
			
			scanf("%500[^\n]", texto);
			scanf("%c");
		}

		
		printf("Texto salvo com sucesso! :]\n");
		
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
	setlocale(0, "Portuguese");
	
	char file_name[50];
	int opc;
	
	
	do{
		printf("Você deseja ler ou criar um novo arquivo?\n[1]Ler arquivo\n[2]Criar novo arquivo\n[3]Sair\n");
		scanf("%d", &opc);
		fflush(stdin);
		
		if(opc != 3){
			printf("Digite o nome do arquivo: ");
			scanf("%50[^\n]", file_name);
			scanf("%c");
			strcat(file_name, ".txt");
		}
		
	
		switch(opc){
			case 1:
				ler(file_name);
			break;
			case 2:
				escrever(file_name);	
		}
		printf("\n");
		
	}while((opc != 3));

	return 0;
}
