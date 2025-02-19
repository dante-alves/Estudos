#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Aula 259 e 260 - Tabela Hash

/*A Tabela Hash � uma estrutura de dados muito utilizada para realizar buscas

	- Ela utiliza de chaves para dividir os dados entre os �ndices
		- EX: as chaves 4890 e 3722 em um vetor de 100 elementos
			-  s�o 100 elementos, ent�o multiplica 100 * 2 = 200, o n�mero primo mais pr�ximo de 200 � 199
			- a fun��o de espalhamento ser� 199, dividindo ent�o 4890 por 199 e 3722 por 199
			- fator de carga = quantidade de elementos/fun��o de espalhamento
				- 100/199 = 0,50 -> 0,50 da tabela ser� preenchida 
				- a fun��o de espalhamento ser� o tamanho do meu vetor
			
			- 4890 % 199 = 114 -> ent�o o elemento de chave 4890 ocuparia o �ndice 114 no vetor da tabela hash
			- 3722 % 199 = 140 -> chave 3722 ocupa o �ndice 140 no vetor da tabela hash
			
			FORMAS DE RESOLVER COLIS�ES
			- Pr�xima posi��o
				- 140 % 199 = 140 -> o �ndice 140 j� foi ocupado, ent�o a chave 140 vai ocupar a pr�xima posi��o do vetor, ou seja, a posi��o 141
			- Vetor de listas encadeadas
				- cria um vetor de ponteiros de lista encadeada
					- a chave 3722 apontaria para a chave 140 que estaria no �ndice 140 do vetor
					
					
	- CONCEITOS ESSENCIAIS
		- Tamanho
		- Fun��o de Espalhamento 
			- fun��o que gera um c�digo a ser utilizado como �ndice de acesso na tabela
		- Colis�es
			- ocorre uma colis�o quando a fun��o de espalhamento gera o mesmo c�digo para chaves diferentes
		- Fator de Carga
			- Quantidade de elementos dividido pelo tamanho da tabela
	*/

#define M 19
int funcao_hash(int chave){
	return chave % M;
}

void inserir(int v[], int chave){
	int id = funcao_hash(chave);
	
	
	while(v[id])
		id = funcao_hash(id + 1);
	
	v[id] = chave;
}

void coletar_chaves(int v[]){
	int i;
	int chave;
	
	printf("\n\tInsira a chave a ser armazenada no vetor: ");
	scanf("%d", &chave);
	inserir(v, chave);
}

void imprimir_tabela(int v[]){
	int i;
	
	for(i = 0; i < M; i++)
		printf("\n\t�ndice %d: %d", i, v[i]);
	
}
	
void iniciar_vet(int v[]){
	int i;
	
	for(i = 0; i < M; i++)
		v[i] = NULL;
}

int buscar(int v[], int num){
	int id;
	
	id = funcao_hash(num);
	
	while(v[id] != NULL){
		if(v[id] == num)
			return v[id];
		else
			id = funcao_hash(id + 1);
	}
	
	return 0;
}
int main(){
	setlocale(0, "Portuguese");
	/*Fazer uma tabela hash para armazenar 10 elementos
	10 * 2 = 20 -> 19 � o n�mero primo mais pr�ximo
	
	10/19 = 0,52 -> Fator de carga
	
	O vetor precisa ter tamanho 19
	*/
	int tam = 10;
	
	//o M seria o 19, no caso de tam ser 10 -> coloquei M como uma constante
	
	int v[M], buscando, opc, num;
	
	iniciar_vet(v);
	
	do{
		printf("\n\n\tTABELA HASH\n");
		printf("\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t0 - Sair\n\n\tInforme: ");
		scanf("%d", &opc);
		
		switch(opc){
			case 1: coletar_chaves(v);
			break;
			case 2: imprimir_tabela(v);
			break;
			case 3: 
				printf("\n\tQual elemento deseja buscar? ");
				scanf("%d", &num);
				
				buscando = buscar(v, num);
				if(buscando != 0)
					printf("\n\tO elemento %d foi encontrado.", buscando);
				else
					printf("\n\tElemento %d n�o encontrado.", num);
			break;
			case 0:
				printf("\n\tAt� a pr�xima! :]");
			break;
			default:
				printf("\n\tValor inv�lido!");
		}
	}while(opc != 0);
	
	return 0;
}
