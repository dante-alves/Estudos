#include <stdio.h>
#include <stdlib.h>

//Teste de aprendizado abrir e ler arquivo

int main(){
	FILE *arquivo;
	char letra;
	
	arquivo = fopen("Teste de aprendizado.txt", "w+");
	
	if(arquivo){
		printf("Digite um texto a ser salvo no arquivo e pressione ENTER para finalizar.\n");
		scanf("%c", &letra);
		
		while(letra != '\n'){
			fputc(letra, arquivo);
			scanf("%c", &letra);
		}
		
		printf("\nArquivo salvo com sucesso! :]\n");
		rewind(arquivo);
		
		while(!feof(arquivo)){
			letra = fgetc(arquivo);
			printf("%c", letra);
		}
		fclose(arquivo);
		
	}
	else{
		printf("Erro ao abrir o arquivo. Finalizando o programa...");
	}
	
	return 0;
}
