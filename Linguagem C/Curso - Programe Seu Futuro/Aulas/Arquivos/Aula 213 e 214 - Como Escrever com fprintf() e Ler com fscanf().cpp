#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//Aula 213 e 214 - Como Escrever com fprintf() e Ler com fscanf()

/*Modos de abertura de arquivos:
	w -> Escrita
	r -> Leitura
	a -> Anexar
	r+ -> Leitura e Escrita
	w+ -> Leitura e Escrita (Apaga o conteúdo caso o arquivo exista)
	a+ -> Leitura e Escrita (Anexa o que for escrito no final do arquivo)
*/

void escrever(char f[]){
	
	FILE *file = fopen(f, "w");//Inicializando variável do tipo FILE e abrindo o arquivo de nome f nessa variável

	char nome[100];
	int idade;
	float altura;
	int opc;
	
	if(file){
		fputs("Nome|Idade|Altura\n\n", file);
		
		do{
			
			printf("Digite nome, idade e altura: ");
			
			scanf("%100[^\n]", nome);
			getchar();
			
			scanf("%d", &idade);
			getchar();
			
			scanf("%f", &altura);
			getchar();
			
			//Salvar as variáveis no arquivo
			fprintf(file, "%s|%d|%.2f\n", nome, idade, altura); 
	
			printf("\nDados salvos com sucesso! :]\nDigite 1 para inserir outro registro: ");
			scanf("%d", &opc);
			scanf("%c");
			printf("\n");
			
		}while(opc == 1);
		
		fclose(file);
	}
	else 
		printf("Erro ao abrir o arquivo...");
}



void ler(char f[]){
	
	FILE *file = fopen(f, "r");
	
	char nome[100];
	int idade;
	float altura;
	
	if(file){
		
		printf("\nTexto lido do arquivo:\n\n");
		
		while(fscanf(file, "%99[^|]|%d|%f\n", nome, &idade, &altura) == 3)
			printf("Nome: %s\nIdade: %d\nAltura: %.2f\n\n", nome, idade, altura);
		
		
		fclose(file);
	}
	else
		printf("Erro ao abrir o arquivo...");
}

int main(){
	setlocale(0, "Portuguese");
	
	char file_name[50];
	int opc;
	
	
	do{

		printf("Você deseja ler ou criar um novo arquivo?\n[1]Ler arquivo\n[2]Criar novo arquivo\n[3]Sair\n");
		scanf("%d", &opc);
		getchar();
		
		if(opc != 3){
			printf("Digite o nome do arquivo: ");
			scanf("%50[^\n]", file_name);
			getchar();
			strcat(file_name, ".txt");
			printf("\n");
		}
		
	
		switch(opc){
			case 1:
				ler(file_name);
				printf("\n\nPressione ENTER para continuar...");
				getchar(); //Esperar o ENTER
			break;
			case 2:
				escrever(file_name);	
		}
		
		system("cls"); //Limpar o terminal
	}while((opc != 3));

	printf("Operação finalizada. Goodbye my friend!");

	return 0;
}
