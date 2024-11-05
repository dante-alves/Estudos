#include <stdio.h>
#include <stdlib.h>

//Aula 209 - Como ler em um arquivo texto com a função fgetc()

/*Modos de abertura de arquivos:
	w -> Escrita
	r -> Leitura
	a -> Anexar
	r+ -> Leitura e Escrita
	w+ -> Leitura e Escrita (Apaga o conteúdo caso o arquivo exista)
	a+ -> Leitura e Escrita (Anexa o que for escrito no final do arquivo)
*/

int main(){
	FILE *arquivo; //Tipo FILE vem na biblioteca stdio.h
	char letra;
	
	arquivo = fopen("Conto do cagão.txt", "w+");
	
	if(arquivo){
		printf("Arquivo aberto com sucesso. Digite um texto e pressione ENTER para adicioná-lo ao arquivo: ");
		scanf(" %c", &letra);

		/*Para adicionar com string, era só fazer
		scanf("%100[^\n]", texto);
		fputs(texto, arquivo);*/
		
		while(letra != '\n'){
			fputc(letra, arquivo);
			scanf("%c", &letra);
		}
		
		printf("Texto salvo com sucesso! :]");
		
		rewind(arquivo); //Faz o ponteiro voltar para o início do arquivo 
		
		printf("\nTexto lido do arquivo: \n");
		while(!feof(arquivo)){ //Função feof retorna verdadeiro se tiver chegado ao fim do arquivo. Por Isso o uso da negação no while 
			letra = fgetc(arquivo); //Função que pega o texto do arquivo 
			printf("%c", letra);
		}
		
		fclose(arquivo);
	}
	else
		printf("Erro na abertura do arquivo! Finalizando o programa...");
	return 0;
}
