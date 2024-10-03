#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

/*
Escreva um algoritmo em C para ler seu nome completo. Use o
modificador para a m�scara da �%s� para aceitar espa�os e caracteres
especiais. Use tamb�m a fun��o strlen() para saber o tamanho da
string e utiliz�-lo no controle dos loops. Em seguida exiba o nome de
tr�s formas diferentes:

a) texto normal, utilizando a m�scara de formata��o string (%s).
b) caractere a caractere em ordem crescente dos �ndices (do come�o
para o fim).
c) caractere a caractere em ordem decrescente dos �ndices (do fim para
o come�o).
d) converter toda string para letras mai�sculas e mostrar, e depois
para min�sculas e mostrar. Pesquise e utilize as fun��es TOUPPER() e
TOLOWER().
e) exiba cada uma das palavras do seu nome em linhas diferentes.
Ex.: Jo�o da Silva Cavalcanti.
Jo�o
da
Silva
Cavalcanti
f) exiba cada uma das palavras do seu nome do �ltimo para o primeiro
em linhas diferentes.
Ex.: Jo�o da Silva Cavalcanti.
Cavalcanti
Silva
da
Jo�o

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
	printf("a) Seu nome � %s\n", nome);
	
	//B)
	printf("\nb) Seu nome letra por letra em ordem crescente �:\n");
	for (i = 0; i < tam - 1; i++) 
		printf("%c ", nome[i]);
	printf("%c\n", nome[i]);
	
	//C)
	printf("\nc) J� em ordem decrescente, �:\n");
	//Coloquei i = tam - 1 para no in�cio da linha n�o pegar o espa�o que tem como �ltimo caractere. 
	for (i = tam - 1; i > 0; i--)
		printf("%c ", nome[i]);
	printf("%c\n", nome[i]);
	
	//D)
	//Deixando em mai�sculas
	i = 0;
	while (nome[i] != '\0') {
		convertido[i] = toupper(nome[i]); //O toupper s� funciona de caractere por caractere. Por isso usei um while at� chegar ao final da string nome, marcada por '\0'
		i++;
	}
	convertido[i] = '\0';
	printf("\nd) Nome em letras mai�sculas: \n%s\n", convertido);
	
	//Deixando em min�sculas
	i = 0;
	while (nome[i] != '\0') {
		convertido[i] = tolower(nome[i]);
		i++;
	}
	convertido[i] = '\0';
	printf("\nNome em letras min�sculas: \n%s\n", convertido);
	
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
	printf("\nf) Um nome por linha ao contr�rio:\n");
	
	//Verificar quantos espa�os tem no nome
	for (i = 0; i < tam; i++){
		if (nome[i] == ' ')
			espacos++;
	}
	if (espacos == 0)
		printf("%s", nome);
	
	else {
		
		//Definir o array posi��o, que vai armazenar a posi��o em que cada espa�o do nome est�, e tem o como total de valores a quantidade de espa�os existentes.
			int posicao[espacos];
		//Verificar a posi��o de cada espa�o
		j = 0;
		for (i = 0; i < tam; i++){
			if (nome[i] == ' '){
				posicao[j] = i; //O �ndice j come�a em zero, e a cada vez que encontra um espa�o ' ' ele aumenta o �ndice em 1, at� registrar a posi��o de todos os espa�os.
				j++;
			}
		}
		
		//Printar todos os nomes, exceto o primeiro
		int cont = espacos - 1; //Contador para pegar o valor equivalente ao �ltimo �ndice do array posicao
		
	    do {
		    int i = posicao[cont] + 1; //i inicia com a posi��o do espa�o + 1, justamente para n�o iniciar no espa�o
		    //Printa o nome at� chegar num espa�o ou no final do string
		    while (nome[i] != ' ' && nome[i] != '\0') { 
		        printf("%c", nome[i]);
		        i++;
		    }
		    printf("\n"); 
		    cont--; //Diminui 1 no contador da posi��o
		} while (cont >= 0); 
		
		//Printar o primeiro nome
		for (i = 0; i < posicao[0]; i ++) {
			printf("%c", nome[i]);
		}
	}
	

	return 0;
}
