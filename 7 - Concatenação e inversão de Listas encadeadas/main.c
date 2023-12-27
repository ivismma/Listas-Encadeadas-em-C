#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Biblioteca p/ valor booleano.

// Aula 7:
// Concatenando duas listas encadeadas (Jun��o de duas listas encadeadas)
// Invertendo uma lista encadeada (Ex: 1 2 4 6  --> 6 4 2 1)

typedef struct node{
	int valor;
	struct node *prox;
} Node;

Node *concatenarLista(Node *topo1, Node* topo2); // Jun��o de duas listas.
Node *inverterLista(Node *topo); // Inverter uma lista encadeada

void exibirLista(Node *topo);
Node *inserirInicio(Node *topo, int novoValor);


Node *concatenarLista(Node *topo1, Node* topo2){
	if(!topo1) return topo2;
	
	Node *atual = topo1;
	while(atual->prox != NULL) 
		atual = atual->prox;
	
	atual->prox = topo2;
	return topo1;
}

Node *inverterLista(Node *topo){
	if(topo == NULL) return NULL; // Lista vazia
	if(topo->prox == NULL) return topo; // Lista s� possui um elemento.
	/////////////////////////////////////////////////////////////////////
	// 3� caso: Lista possui mais de 1 elemento (� poss�vel inverter): //
	Node *atual = topo,
	*prox_node; // Pr�ximo n�.
	prox_node = topo->prox;
	
	atual->prox = NULL; // Novo in�cio da lista.
	while(prox_node != NULL){
		Node *aux = prox_node->prox;
		prox_node->prox = atual;
		atual = prox_node;
		prox_node = aux;	
	}
	return atual; // O que era o in�cio, virou o topo.
}

// MAIN
int main(){
	Node *lista1 = NULL, // Declara��o de lista vazia.
	*lista2 = NULL; // Declara��o de lista vazia.

	// Concatenaa��o de lista encadeada:
	lista1 = inserirInicio(lista1, 1);
	lista1 = inserirInicio(lista1, 2);
	lista1 = inserirInicio(lista1, 3); // Topo da lista 1
	lista2 = inserirInicio(lista2, 4);
	lista2 = inserirInicio(lista2, 5);
	lista2 = inserirInicio(lista2, 6); // Topo da lista 2
	printf("Lista 1:\n");
	exibirLista(lista1); 
	
	printf("Lista 2:\n"); 
	exibirLista(lista2);
	printf("---------------------------\n");
	
	printf("Lista 1 - concatenada:\n");
	lista1 = concatenarLista(lista1, lista2);
	exibirLista(lista1);
	printf("---------------------------\n");
	// Inverter uma lista encadeada:    (Ex: 1 2 4 6  --> 6 4 2 1)
	printf("Lista 1 - concatenada e invertida:\n");
	lista1 = inverterLista(lista1);
	exibirLista(lista1);
	printf("---------------------------");
	
	return 0;
}

//////// Fun��es j� estudadas ////////

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
	int i = 0;
	
	while(atual != NULL){
		printf("Node %d: %d\n", i, atual->valor);
		++i;
		atual = atual->prox;
	}
}
