#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Aula 129 - Como ler uma string com a função scanf()
//Aula 130 - Função gets()
//Aula 131 - Função fgets()

int main () {
	char palavras[100];
	
	//Utilizando scanf()
	//scanf("%s", palavras) //Dessa forma, só vai pegar até o primeiro espaço, e se for digitado algo maior do que o limite do array palavras, ele vai armazenar na memória, mas em um local aleatório. Para isso não acontecer, segue a solução:
	
	//scanf("%100[^\n]", palavras); //O 100 após o % delimita o total de caracteres, igual ao limite do array. [^\n] faz pegar tudo
	

	//Utilizando gets()
	//gets(palavras); //Não é recomendado usar esse porque em certos compiladores ele dá um aviso, além de não ter como delimitar o tamanho da string nele
	
	
	//Utilizando fgets()
	//ESSE PODE USAR
	fgets(palavras, sizeof palavras, stdin); // fgets(Nome do vetor, tamanho do vetor, indicar que a leitura será feita a partir do buffer do teclado (entrada padrão do computador) (stdin);
	printf("%s", palavras);
	return 0;
}
