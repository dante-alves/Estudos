#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Aula 152 - Como transformar n�mero em texto	  |

int main() {
	setlocale(0, "Portuguese");					//|
	
	int tam;
	char str1[] = {"%"}, str2[10];				//|
	
	//Perguntar o tamanho
	printf("Qual o tamanho do vetor? ");		//|
	scanf("%d", &tam);
	scanf("%c");
	//Declarando a vari�vel com o tamanho definido
	char palavras[tam];							//|
	
	snprintf(str2, 10, "%d[^\n]", tam); 		//Com essa fun��o snprintf(primeiro, eu coloco a string que eu quero inserir o n�mero(str2)
	//Concatenar as strings
	strcat(str1, str2);							//Depois o valor limite que pode ser inserido (10), depois o texto que vai ser inserido, juntamente ao n�mero com a m�scara de formata��o
												//que � (%d), nesse caso, e no fim, o n�mero, que nesse caso, � a vari�vel (tam)
	printf("Digite um texto: ");			
	scanf(str1, palavras);
	printf("%s", palavras);
	return 0;
}
