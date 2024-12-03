#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Aula 162 - Como descobrir o maior valor de um vetor com recursão

//Função para descobrir

int maiorValor(int v[], int i, int maior) {
	if (i == 0)
		return v[maior];
	else if (v[i] > v[maior])
		return maiorValor(v, i - 1, i);
	else
		return maiorValor(v, i - 1, maior);
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	int i, tam;
	
	printf("Qual o tamanho do vetor? ");
	scanf("%d", &tam);
	
	int vet[tam];
	
	for (i = 0; i < tam; i++){
		printf("\nDigite o valor na posição %d: ", i);
		scanf("%d", &vet[i]);
	}

	printf("\nO maior valor no vetor é %d.", maiorValor(vet, tam - 1, 0));
	return 0;
}
