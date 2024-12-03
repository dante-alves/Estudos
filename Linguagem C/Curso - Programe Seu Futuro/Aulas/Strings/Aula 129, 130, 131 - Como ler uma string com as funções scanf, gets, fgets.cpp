#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Aula 129 - Como ler uma string com a fun��o scanf()
//Aula 130 - Fun��o gets()
//Aula 131 - Fun��o fgets()

int main () {
	char palavras[100];
	
	//Utilizando scanf()
	//scanf("%s", palavras) //Dessa forma, s� vai pegar at� o primeiro espa�o, e se for digitado algo maior do que o limite do array palavras, ele vai armazenar na mem�ria, mas em um local aleat�rio. Para isso n�o acontecer, segue a solu��o:
	
	//scanf("%100[^\n]", palavras); //O 100 ap�s o % delimita o total de caracteres, igual ao limite do array. [^\n] faz pegar tudo
	

	//Utilizando gets()
	//gets(palavras); //N�o � recomendado usar esse porque em certos compiladores ele d� um aviso, al�m de n�o ter como delimitar o tamanho da string nele
	
	
	//Utilizando fgets()
	//ESSE PODE USAR
	fgets(palavras, sizeof palavras, stdin); // fgets(Nome do vetor, tamanho do vetor, indicar que a leitura ser� feita a partir do buffer do teclado (entrada padr�o do computador) (stdin);
	printf("%s", palavras);
	return 0;
}
