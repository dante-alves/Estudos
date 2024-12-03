#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Aula 152 - Como transformar número em texto	  |

int main() {
	setlocale(0, "Portuguese");					//|
	
	int tam;
	char str1[] = {"%"}, str2[10];				//|
	
	//Perguntar o tamanho
	printf("Qual o tamanho do vetor? ");		//|
	scanf("%d", &tam);
	scanf("%c");
	//Declarando a variável com o tamanho definido
	char palavras[tam];							//|
	
	snprintf(str2, 10, "%d[^\n]", tam); 		//Com essa função snprintf(primeiro, eu coloco a string que eu quero inserir o número(str2)
	//Concatenar as strings
	strcat(str1, str2);							//Depois o valor limite que pode ser inserido (10), depois o texto que vai ser inserido, juntamente ao número com a máscara de formatação
												//que é (%d), nesse caso, e no fim, o número, que nesse caso, é a variável (tam)
	printf("Digite um texto: ");			
	scanf(str1, palavras);
	printf("%s", palavras);
	return 0;
}
