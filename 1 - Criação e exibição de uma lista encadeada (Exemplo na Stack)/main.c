#include <stdio.h>

// Introdu��o/Demonstra��o b�sica
// Criando uma lista encadeada (na stack) e exibindo a lista.

typedef struct node{
	int valor;
	struct node *prox;
} Node;

void exibirLista(Node *topo);

int main(){
	Node a, b ,c; // a = topo | c = in�cio.
	a.valor = 5;
	b.valor = 6;
	c.valor = 7;
	a.prox = &b;
	b.prox = &c;
	c.prox = NULL; // In�cio da lista, n�o aponta para nada.

	exibirLista(&a); // &a - topo.
	return 0;
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




