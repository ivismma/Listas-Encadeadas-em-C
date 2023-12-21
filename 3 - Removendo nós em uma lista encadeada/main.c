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
Node *deletarTopo(Node *topo);
Node *deletarInicio(Node *topo);

int main(){
	Node *lista1_topo = NULL; // Declara��o de lista vazia.
	
	lista1_topo = inserirTopo(lista1_topo, 5);
	lista1_topo = inserirTopo(lista1_topo, 8);
	lista1_topo = inserirTopo(lista1_topo, 10);
	lista1_topo = inserirTopo(lista1_topo, 2);
	
	exibirLista(lista1_topo);
	lista1_topo = deletarInicio(lista1_topo); // Deleta o elemento 5.
	printf("Apos a remocao do inicio da lista:\n");
	exibirLista(lista1_topo);
	printf("----------\nNumero deletado: 5");
	
	return 0;
}

Node *deletarTopo(Node *topo){
	if(topo == NULL) return NULL; // Se lista vazia, retorna ponteiro nulo, n�o h� o que remover nem para onde apontar.
	else{ // Lista n�o est� vazia..
		Node *retorno = topo->prox;  // Topo da lista agora � o sucessor do elemento a ser removido.
		free(topo);                  // Topo antigo removido.
		return retorno;              // Retorna ponteiro para o novo topo da lista.
	}
}

Node *deletarInicio(Node *topo){
	if(topo == NULL) return NULL; // 1� caso: lista vazia
	else if(topo->prox == NULL){ // 2� caso: S� existe um elemento na lista (o pr�ximo aponta para nulo).
		free(topo);
		return NULL;
	} // 3� caso: A lista possui mais de um elemento, percorrer a lista..
	Node *atual = topo;
	Node *anterior = NULL; // Percorre a lista at� o in�cio sempre armazenando "anterior" para saber quem � o n� antes do �ltimo.
	
	while(atual->prox != NULL){
		anterior = atual;     // <-- Exemplo do coment�rio acima.
		atual = atual->prox;
	}
	anterior->prox = NULL; // O pen�ltimo passa a ser o �ltimo (�ltimo ent�o n�o aponta para ningu�m).
	free(atual); // Deleta o in�cio (tail);
	return topo;
}

Node *inserirTopo(Node *topo, int novoValor){
	Node *novoNode = calloc(1, sizeof(Node));
	novoNode->valor = novoValor;
	if(topo == NULL) return novoNode; // Se lista vazia, o novo n� ent�o � o primeiro.
	else{ // Lista n�o vazia
		novoNode->prox = topo;
		return novoNode;
	}
	
}

Node *inserirInicio(Node *topo, int novoValor){
	Node *novoNode = calloc(1, sizeof(Node));
	novoNode->valor = novoValor;
	if (topo == NULL) return novoNode; // Se lista vazia, o novo n� ent�o � o primeiro.
	else{ // Lista n�o vazia
		Node *atual = topo;
		while(atual->prox != NULL) // Enquanto n�o chegou no IN�CIO da lista..
			atual = atual->prox;   // Percorre at�.
		atual->prox = novoNode;    // Atual in�cio da lista vira pen�ltimo e aponta para o novo inserido que � o �ltimo (in�cio).
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
