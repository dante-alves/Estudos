#include <stdio.h>
#include <locale.h>
/*EX02 - Ler 10 n�meros a serem digitados pelo usu�rio e armazene-os em um
VETOR ou ARRAY. Em seguida:
a) Exibir a quantidade de vezes que o n�mero 3 est� presente no vetor.
b) Depois, pergunte ao usu�rio qual n�mero ele quer pesquisar (no
lugar do n�mero 3), e diga quantas vezes este n�mero est� presente
no vetor.
c) Diga qual � o maior dos 10 n�meros.
d) Diga qual � o menor dos 10 n�meros.
*/
int main() {
	setlocale(0, "Portuguese");
	
	//Vari�veis
	int tam = 10;
	int vet[tam], i, num = 3, contador = 0, maior, menor;
	
	//Armazenar os valores no vetor
	for(i = 0; i < tam; i++) {
		printf("Insira o valor na posi��o %d: ", i);
		scanf("%d", &vet[i]);
		
		//Verificar a quantidade de vezes que o n�mero 3 est� presente.
		if(vet[i] == num)
			contador++;
		
	}
	
	//Quest�es
	//A)
	printf("a) Quantidade de vezes que o n�mero 3 est� presente no vetor: %d.\n\n", contador);
	//B)
	printf("b) Qual outro n�mero deseja pesquisar a quantidade? ");
	scanf("%d", &num);
	
	//Verificar o n�mero selecionado
	contador = 0;
	for(i = 0; i < tam; i++) {
		if(vet[i] == num)
			contador++;
	}
	
	printf("O n�mero %d foi encontrado %d vez(es) no vetor.\n\n", num, contador);
	
	//C) e D)
	maior = vet[0];
	menor = vet[0];
	//Verificar o maior e menor
	for(i = 0; i < tam; i++) {
		if(vet[i] > maior)
			maior = vet[i];
		
		if(vet[i] < menor)
			menor = vet[i];
	}

	printf("c) O maior dos 10 n�meros � %d\n\n", maior);
	printf("d) O menor dos 10 n�meros � %d\n\n", menor);
	
	return 0;
	
}
