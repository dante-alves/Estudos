#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

/*
Escreva um algoritmo em C para ler seu nome completo. Use o
modificador para a máscara da “%s” para aceitar espaços e caracteres
especiais. Use também a função strlen() para saber o tamanho da
string e utilizá-lo no controle dos loops. Em seguida exiba o nome de
três formas diferentes:

a) texto normal, utilizando a máscara de formatação string (%s).
b) caractere a caractere em ordem crescente dos índices (do começo
para o fim).
c) caractere a caractere em ordem decrescente dos índices (do fim para
o começo).
d) converter toda string para letras maiúsculas e mostrar, e depois
para minúsculas e mostrar. Pesquise e utilize as funções TOUPPER() e
TOLOWER().
e) exiba cada uma das palavras do seu nome em linhas diferentes.
Ex.: João da Silva Cavalcanti.
João
da
Silva
Cavalcanti
f) exiba cada uma das palavras do seu nome do último para o primeiro
em linhas diferentes.
Ex.: João da Silva Cavalcanti.
Cavalcanti
Silva
da
João

Tive dificuldade na letra F
*/

int main() {
	setlocale(0, "Portuguese");
	char nome[100], convertido[100];
	int i, j, tam, espacos = 0;
	
	//Pegar o nome e calcular seu tamanho
	printf("Qual o seu nome completo? ");
	scanf("%100[^\n]", &nome);
	tam = strlen(nome);
	
	//A)
	printf("a) Seu nome é %s\n", nome);
	
	//B)
	printf("\nb) Seu nome letra por letra em ordem crescente é:\n");
	for (i = 0; i < tam - 1; i++) 
		printf("%c ", nome[i]);
	printf("%c\n", nome[i]);
	
	//C)
	printf("\nc) Já em ordem decrescente, é:\n");
	//Coloquei i = tam - 1 para no início da linha não pegar o espaço que tem como último caractere. 
	for (i = tam - 1; i > 0; i--)
		printf("%c ", nome[i]);
	printf("%c\n", nome[i]);
	
	//D)
	//Deixando em maiúsculas
	i = 0;
	while (nome[i] != '\0') {
		convertido[i] = toupper(nome[i]); //O toupper só funciona de caractere por caractere. Por isso usei um while até chegar ao final da string nome, marcada por '\0'
		i++;
	}
	convertido[i] = '\0';
	printf("\nd) Nome em letras maiúsculas: \n%s\n", convertido);
	
	//Deixando em minúsculas
	i = 0;
	while (nome[i] != '\0') {
		convertido[i] = tolower(nome[i]);
		i++;
	}
	convertido[i] = '\0';
	printf("\nNome em letras minúsculas: \n%s\n", convertido);
	
	//E)
	printf("\ne) Um nome por linha:\n");
	for (i = 0; i < tam; i++) {
		if (nome[i] != ' ')
			printf("%c", nome[i]);
		else 
			printf("\n");
	}
	printf("\n");
	
	//F)
	printf("\nf) Um nome por linha ao contrário:\n");
	
	//Verificar quantos espaços tem no nome
	for (i = 0; i < tam; i++){
		if (nome[i] == ' ')
			espacos++;
	}
	if (espacos == 0)
		printf("%s", nome);
	
	else {
		
		//Definir o array posição, que vai armazenar a posição em que cada espaço do nome está, e tem o como total de valores a quantidade de espaços existentes.
			int posicao[espacos];
		//Verificar a posição de cada espaço
		j = 0;
		for (i = 0; i < tam; i++){
			if (nome[i] == ' '){
				posicao[j] = i; //O índice j começa em zero, e a cada vez que encontra um espaço ' ' ele aumenta o índice em 1, até registrar a posição de todos os espaços.
				j++;
			}
		}
		
		//Printar todos os nomes, exceto o primeiro
		int cont = espacos - 1; //Contador para pegar o valor equivalente ao último índice do array posicao
		
	    do {
		    int i = posicao[cont] + 1; //i inicia com a posição do espaço + 1, justamente para não iniciar no espaço
		    //Printa o nome até chegar num espaço ou no final do string
		    while (nome[i] != ' ' && nome[i] != '\0') { 
		        printf("%c", nome[i]);
		        i++;
		    }
		    printf("\n"); 
		    cont--; //Diminui 1 no contador da posição
		} while (cont >= 0); 
		
		//Printar o primeiro nome
		for (i = 0; i < posicao[0]; i ++) {
			printf("%c", nome[i]);
		}
	}
	

	return 0;
}
