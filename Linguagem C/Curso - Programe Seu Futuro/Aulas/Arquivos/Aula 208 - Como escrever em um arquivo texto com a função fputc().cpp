#include <stdio.h>
#include <stdlib.h>

//Aula 208 - Como escrever em um arquivo texto com a funÁ„o fputc()?

/*Modos de abertura de arquivos:
	w -> Escrita
	r -> Leitura
	a -> Anexar
	r+ -> Leitura e Escrita
	w+ -> Leitura e Escrita (Apaga o conte˙do caso o arquivo exista)
	a+ -> Leitura e Escrita (Anexa o que for escrito no final do arquivo)
*/
int main(){
	FILE *arquivo; //Tipo FILE vem na biblioteca stdio.h
	char letra;
	
	arquivo = fopen("Conto do cag„o.txt", "w");
	
	if(arquivo){
		printf("Arquivo aberto com sucesso. Digite um texto e pressione ENTER para adicion·-lo ao arquivo.");
		scanf("%c", &letra);

		/*Para adicionar com string, era s√≥ fazer
		scanf("%100[^\n]", texto);
		fputs(texto, arquivo);*/

		while(letra != '\n'){
			fputc(letra, arquivo);
			scanf("%c", &letra);
		}
		printf("Texto salvo com sucesso! :]");
		fclose(arquivo); //Fechar o arquivo e evitar de corromper
	}
	else
		printf("Erro na abertura do arquivo! Finalizando o programa...");
	return 0;
}
