#include <stdio.h>
#include <stdlib.h>


// Inser��o de elementos pelo topo e pelo in�cio (head & tail).

typedef struct node{
	int valor;
	struct node *prox;
} Node;

void exibirLista(Node *topo);
Node *inserirTopo(Node *topo, int novoValor);
Node *inserirInicio(Node *topo, int novoValor);

int main(){
	Node *lista1_topo = NULL; // Declara��o de lista vazia.
	
	lista1_topo = inserirTopo(lista1_topo, 5);
	lista1_topo = inserirTopo(lista1_topo, 8);
	lista1_topo = inserirInicio(lista1_topo, 10);
	lista1_topo = inserirInicio(lista1_topo, 20);
	
	exibirLista(lista1_topo);
	return 0;
}

Node *inserirTopo(Node *topo, int novoValor){
	Node *novoNode = calloc(1, sizeof(Node)); // Novo n�.
	novoNode->valor = novoValor;
	if(topo == NULL) return novoNode; // Se lista vazia, o novo n� � o primeiro elemento.
	else{
		novoNode->prox = topo;
		return novoNode;
	}
	
}

Node *inserirInicio(Node *topo, int novoValor){
	Node *novoNode = calloc(1, sizeof(Node)); // Novo n�/elemento
	novoNode->valor = novoValor;
	if (topo == NULL) return novoNode; // Se lista vazia, o novo n� � o primeiro elemento.
	else{
		Node *atual = topo;
		while(atual->prox != NULL) // Enquanto n�o chegou ao fim..
			atual = atual->prox; // Procede para o pr�ximo.
		// Chegou ao fim (IN�CIO da lista encadeada).
		atual->prox = novoNode; // O que era o �ltimo elemento agora aponta para o novo inserido no in�cio.
		return topo;
	}
}

void exibirLista(Node *topo){
	Node *atual;
	atual = topo;
	int i = 0; // Somente para demonstrar o n�mero do n� na exibi��o.
	
	while(atual != NULL){
		printf("Node %d: %d\n", i, atual->valor);
		++i;
		atual = atual->prox;
	}
}

