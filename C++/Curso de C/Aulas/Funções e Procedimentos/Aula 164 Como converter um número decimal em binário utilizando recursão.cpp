#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Aula 164 Como converter um n�mero decimal em bin�rio utilizando recurs�o
/*Como converte?
	Divide o n�mero por 2 sucessivamente e pega o resto da divis�o a cada vez que dividir, e depois anota todos + o �ltimo quociente das divis�es
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
