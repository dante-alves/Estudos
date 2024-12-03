#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Aula 164 Como converter um número decimal em binário utilizando recursão
/*Como converte?
	Divide o número por 2 sucessivamente e pega o resto da divisão a cada vez que dividir, e depois anota todos + o último quociente das divisões
*/

void converter(int n) {

	if (n == 0) {
		printf("%d", n);
	} else {
		converter(n / 2);
		printf("%d", n % 2);
	} 
}
int main() {
	setlocale(0, "Portuguese");
	char str[20] = {' '};
	int n = 1365;
	
	converter(n);
	
	return 0;
}
