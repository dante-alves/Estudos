#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*EX08 - O m�ximo divisor comum dos inteiros x e y � o maior inteiro que � divis�vel por x e
y. Escreva uma fun��o recursiva mdc em C, que retorna o m�ximo divisor comum de x
e y. O mdc de x e y � definido como segue: se y � igual a 0, ent�o mdc(x,y) � x; caso
contr�rio, mdc(x,y) � mdc (y, x%y), onde % � o operador resto.*/

//Fun��o que retorna o m�ximo divisor comum entre dois inteiros 
int mdc(int n1, int n2){
	//Se o resto da divis�o do maior valor pelo menor for 0, ent�o o menor valor � o m�ximo divisor comum. Se n�o, tem que dividir o menor valor pelo resto da divis�o at� chegar ao resto 0. 
	if(n2 == 0)
		return n1;
	else 
		return mdc(n2, n1 % n2);
}

int main(){
	int x, y;
	
	printf("Digite o valor de x e y: ");
	scanf("%d%d", &x, &y);
	
	printf("O m�ximo divisor comum de %d e %d �: %d", x, y, mdc(x, y));
	
	return 0;
}
