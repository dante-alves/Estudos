/*Aula 230 - Como criar arquivos de cabeçalho .h na linguagem C
	-> Salve o arquivo como .h
	-> Compile sem rodar
*/

// estrutura do nó
typedef struct no{
	int n;
	struct no *proximo;	
}No;

// função para adicionar item na pilha
No* push(No *pilha, int num){
	No *novo = (No *)malloc(sizeof(No));
	
	if(novo){
		novo->n = num;
		novo->proximo = pilha;
		return novo;
	}
	else
		printf("\nErro ao alocar memória!");
	return NULL;
}

// função para remover item da pilha
No* pop(No **pilha){
	No *remover;
	
	if(*pilha){
		remover = *pilha;
		*pilha = remover->proximo;
		return remover;
	}
	else
		printf("\nPilha Vazia!");
	return NULL;
}

// procedimento imprimir a pilha
void imprimir_pilha(No *pilha){
	if(pilha){
		printf("\nPILHA\n");
		while(pilha){
			printf("%d ", pilha->n);
			pilha = pilha->proximo;
			
			if(pilha != NULL)
				printf("x ");
		}
	}
	else
		printf("\nPilha Vazia!");
}
