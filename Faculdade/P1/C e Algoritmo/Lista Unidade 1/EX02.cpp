#include <stdio.h>
#include <locale.h>
/*EX02 - Ler 10 números a serem digitados pelo usuário e armazene-os em um
VETOR ou ARRAY. Em seguida:
a) Exibir a quantidade de vezes que o número 3 está presente no vetor.
b) Depois, pergunte ao usuário qual número ele quer pesquisar (no
lugar do número 3), e diga quantas vezes este número está presente
no vetor.
c) Diga qual é o maior dos 10 números.
d) Diga qual é o menor dos 10 números.
*/
int main() {
	setlocale(0, "Portuguese");
	
	//Variáveis
	int tam = 10;
	int vet[tam], i, num = 3, contador = 0, maior, menor;
	
	//Armazenar os valores no vetor
	for(i = 0; i < tam; i++) {
		printf("Insira o valor na posição %d: ", i);
		scanf("%d", &vet[i]);
		
		//Verificar a quantidade de vezes que o número 3 está presente.
		if(vet[i] == num)
			contador++;
		
	}
	
	//Questões
	//A)
	printf("a) Quantidade de vezes que o número 3 está presente no vetor: %d.\n\n", contador);
	//B)
	printf("b) Qual outro número deseja pesquisar a quantidade? ");
	scanf("%d", &num);
	
	//Verificar o número selecionado
	contador = 0;
	for(i = 0; i < tam; i++) {
		if(vet[i] == num)
			contador++;
	}
	
	printf("O número %d foi encontrado %d vez(es) no vetor.\n\n", num, contador);
	
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

	printf("c) O maior dos 10 números é %d\n\n", maior);
	printf("d) O menor dos 10 números é %d\n\n", menor);
	
	return 0;
	
}
