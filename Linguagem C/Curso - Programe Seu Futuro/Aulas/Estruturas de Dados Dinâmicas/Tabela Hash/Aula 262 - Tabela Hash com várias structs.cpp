#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Aula 262 - Tabela Hash com v�rias structs

/*				
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

//---------- structs
typedef struct{
	int dia, mes, ano;
}Data;

typedef struct{
	char rua[50];
	char bairro[50];
	char cidade[50];
	char pais[50];
	int num, cep;
}Endereco;

typedef struct{
	int codigo;
	Data dataAss;
	char cargo[50];
	float salario;
}Contrato;

typedef struct{
	char nome[50];
	int cpf;
	Data dataNas;
	Endereco end;
	Contrato contr;	
}Pessoa;

typedef struct no{
	Pessoa p;
	struct no *proximo;
}No;

//---------- procedimentos e fun��es
//---------- impress�o das informa��es de uma pessoa 
void imprimirData(Data d){
	printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}

void imprimirEndereco(Endereco end){
	printf("\tEndere�o:\n");
	printf("\t\tRua: %s", end.rua);
	printf("\t\tBairro: %s", end.bairro);
	printf("\t\tCidade: %s", end.cidade);
	printf("\t\tPa�s: %s", end.pais);
	printf("\t\tN�mero: %d\n", end.num);
	printf("\t\tCEP: %d\n", end.cep);
}

void imprimirContrato(Contrato c){
	printf("\tContrato %d:\n", c.codigo);
	printf("\t\tCargo: %s", c.cargo);
	printf("\t\tSal�rio R$%.2f\n", c.salario);
	printf("\t\tData de ad.: ");
	imprimirData(c.dataAss);
}

void imprimirPessoa(Pessoa p){
	printf("\n\tNome: %s", p.nome);
	printf("\tCPF: %d", p.cpf);
	printf("\tData de nasc.: ");
	imprimirData(p.dataNas);
	imprimirEndereco(p.end);
	imprimirContrato(p.contr);
}

//---------- leitura dos dados de uma pessoa
Data lerData(){
	Data d;
	printf("\nDigite a data no formato dd/mm/aaaa: ");
	scanf("%d/%d/%d", &d.dia, &d.mes, &d.ano);
	getchar();
	return d;
}

Endereco lerEndereco(){
	Endereco end;
	printf("\nRua: ");
	fgets(end.rua, 49, stdin);
	printf("\nBairro: ");
	fgets(end.bairro, 49, stdin);
	printf("\nCidade: ");
	fgets(end.cidade, 49, stdin);
	printf("\nPa�s: ");
	fgets(end.pais, 49, stdin);
	printf("\nN�mero: ");
	scanf("%d", &end.num);
	printf("\nCEP: ");
	scanf("%d", &end.cep);
	getchar();
	
	return end;
}

Contrato lerContrato(){
	Contrato c;
	printf("\nC�digo do contrato: ");
	scanf("%d", &c.codigo);
	printf("\nData de assinatura: ");
	c.dataAss = lerData();
	printf("\nCargo: ");
	fgets(c.cargo, 49, stdin);
	printf("\nSal�rio: R$");
	scanf("%f", &c.salario);
	getchar();
	return c;
}

Pessoa lerPessoa(){
	Pessoa p;
	getchar();
	printf("\nNome: ");
	fgets(p.nome, 49, stdin);
	printf("\nCPF: ");
	scanf("%d", &p.cpf);
	getchar();
	printf("\nData de nascimento: ");
	p.dataNas = lerData();
	p.contr = lerContrato();
	p.end = lerEndereco();
	
	return p;
}
//---------- fun��es e procedimentos da lista
void iniciar_vet(Pessoa v[]){
	int i;
	
	for(i = 0; i < M; i++)
		v[i].cpf = 0; 
}
int funcao_hash(int chave){
	return chave % M;
}

void inserir(Pessoa v[]){
	Pessoa p = lerPessoa();
	
	int id = funcao_hash(p.cpf); // a chave � o CPF, e o ID vai ser criado a partir desse CPF
	
	
	while(v[id].cpf)
		id = funcao_hash(id + 1);
	
	v[id] = p;
}

void imprimir_tabela(Pessoa v[]){
	int i;
	
	for(i = 0; i < M; i++){
		printf("\n�ndice %d:", i);
		if(v[i].cpf){
			imprimirPessoa(v[i]);
		}
		printf("\n-----------------------------\n");
	}
	
}
	

Pessoa* buscar(Pessoa v[], int chave){
	int id;
	
	id = funcao_hash(chave);
	
	while(v[id].cpf != NULL){
		if(v[id].cpf == chave)
			return &v[id];
		else
			id = funcao_hash(id + 1);
	}
	
	return NULL; 
}
int main(){
	setlocale(0, "Portuguese");
	/*Fazer uma tabela hash para armazenar 10 elementos
	10 * 2 = 20 -> 19 � o n�mero primo mais pr�ximo
	
	10/19 = 0,52 -> Fator de carga
	
	O vetor precisa ter tamanho 19
	*/
	
	//o M seria o 19, no caso de tam ser 10 -> coloquei M como uma constante
	
	int opc, num;
	Pessoa v[M], *buscando;
	iniciar_vet(v);
	
	do{
		printf("\n\n\tTABELA HASH\n");
		printf("\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t0 - Sair\n\n\tInforme: ");
		scanf("%d", &opc);
		
		switch(opc){
			case 1: inserir(v);
			break;
			case 2: imprimir_tabela(v);
			break;
			case 3: 
				printf("\n\tQual elemento deseja buscar? ");
				scanf("%d", &num);
				
				buscando = buscar(v, num);
				if(buscando != 0){
					printf("\n\tO elemento %d foi encontrado.", num);
					imprimirPessoa(*buscando);
				}
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
