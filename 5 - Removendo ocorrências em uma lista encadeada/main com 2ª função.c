#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Biblioteca p/ valor booleano.

// Aula 5:
// Removendo ocorr�ncias de um valor em uma lista encadeada (1� f.) e ...
// removendo de uma lista encadeada todos os n�s com o valor dado (2� f.).
// Pr�xima aula: M�todo eficiente da 2� fun��o.

typedef struct node{
	int valor;
	struct node *prox;
} Node;

Node *del_primeiroEncontrado(Node *topo, int valor, bool *foiDeletado); // 1�
Node *del_todasOcorrencias(Node *topo, int valor, int *qtd_deletada); // 2�

void exibirLista(Node *topo);
Node *inserirTopo(Node *topo, int novoValor);

// Apaga da lista encadeada o primeiro valor encontrado que foi inserido para remo��o.
Node *del_primeiroEncontrado(Node *topo, int valor, bool *foiDeletado){
	if(topo == NULL){ // 1� caso: Lista vazia.
		*foiDeletado = false;
		return NULL;
	} //2� caso: Primeiro valor (o topo) da lista � o valor a ser removido.
	if(topo->valor == valor){
		Node *aux = topo->prox; // Guarda o ponteiro para o pr�x. antes de liberar o topo a ser deletado.
		free(topo);             // Topo apagado.
		*foiDeletado = true;
		return aux;             // Retorna para onde o topo apagado apontava.
	} 
	//3� caso: O valor est� no meio da lista.
	Node *atual = topo->prox;
	Node *anterior = topo;
	while(atual != NULL){
		if(atual->valor == valor){
			anterior->prox = atual->prox;
			free(atual);
			*foiDeletado = true;
			return topo;   // Topo permanece o mesmo, altera��o foi no meio da lista.
		}
		anterior = atual;
		atual = atual->prox;
	}
	// 4� caso: A lista foi percorrida e o valor inserido n�o est� na lista.
	*foiDeletado = false;
	return topo; // A lista encadeada permanece como estava.
}

// Apaga da lista encadeada todas os n�s que possuem um dado valor.
Node *del_todasOcorrencias(Node *topo, int valor, int *qtd_deletada){
	Node *atual = topo;
	bool apagado = false;
	*qtd_deletada = 0;
	do{
		atual = del_primeiroEncontrado(atual, valor, &apagado);
		if(apagado) ++(*qtd_deletada);
	} while(apagado); // Enquanto n�o encontrar mais ocorr�ncias na lista, continuar apagando.
	
	return atual; // Retorna topo/novo topo da lista que a fun��o del_PrimeiroEncontrado retorna.
}

//////// Fun��es j� estudadas ////////

Node *inserirTopo(Node *topo, int novoValor){
	Node *novoNode = calloc(1, sizeof(Node));
	novoNode->valor = novoValor;
	if(topo == NULL) return novoNode;
	else{
		novoNode->prox = topo;
		return novoNode;
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
// MAIN
int main(){
	Node *lista1_topo = NULL; // Declara��o de lista vazia.
	
	exibirLista(lista1_topo);
	lista1_topo = inserirTopo(lista1_topo, 4);
	lista1_topo = inserirTopo(lista1_topo, 4);
	lista1_topo = inserirTopo(lista1_topo, 2);
	lista1_topo = inserirTopo(lista1_topo, 4);
	lista1_topo = inserirTopo(lista1_topo, 5);
	
	exibirLista(lista1_topo); // Antes
	int qtd_del;                           // Apagar todos os 4's da lista.
	lista1_topo = del_todasOcorrencias(lista1_topo, 4, &qtd_del);
	printf("----------\n");
	exibirLista(lista1_topo); // Depois
	printf("Quantidade de 4's removidos da lista: %d", qtd_del);
	
	return 0;
}
