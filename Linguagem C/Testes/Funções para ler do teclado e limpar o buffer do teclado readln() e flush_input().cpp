#include <stdio.h>
#include <stdlib.h>

//Funções para ler do teclado e limpar o buffer do teclado readln() e flush_input()

void readln(char s[], int maxlen); // procedimento para ler o input e limpar o  buffer
void flush_input(); // procedimento para limpar o buffer

int main(){
	char string[20];
	char string2[20];
	printf("Digite algo: ");
	readln(string, 19);
	
	printf("Digite outra coisa: ");
	readln(string2, 19);

	
	printf("Algo: %s\tOutra coisa: %s", string, string2);
	
	return 0;
}

// procedimento para limpar o buffer
void flush_input(){
	int ch; // getchar(void) retorna um inteiro se for um unsigned char ou EOF. Por isso ch é do tipo int, e não char
	while((ch = getchar()) != '\n' && ch != EOF);
}

// procedimento para ler o input e limpar o  buffer
void readln(char s[], int maxlen){
	char ch;
	int i;
	int chars_remain;
	i = 0;
	chars_remain = 1; // flag para verificar se ainda têm caracteres a serem lidos
	
	while(chars_remain){ // enquanto tiver caracteres sobrando, realiza o loop
		ch = getchar(); // pega o caracter
		
		if((ch == '\n') || (ch == EOF))
			chars_remain = 0; // se o caracter for \n ou EOF a flag recebe 0, indicando que acabou ----> isso garante que o \n seja removido
		else if(i < maxlen - 1){ // se não, se i for menor que o tamanho máximo da string - 1, a string recebe o caracter
			s[i] = ch;
			i++;
		}
	}
	s[i] = '\0'; // adiciona manualmente o final da string
}
