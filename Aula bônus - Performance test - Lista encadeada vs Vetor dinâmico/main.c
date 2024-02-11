#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INICIA_CRONO clock_gettime(CLOCK_MONOTONIC, &t1);
#define PARA_CRONO clock_gettime(CLOCK_MONOTONIC, &t2);

// Aula 10:
// Teste de performance - Tempo de realização de tarefa
// Lista encadeada vs Vetor alocado dinâmicamente.

typedef struct node{
	int valor;
	struct node *prox;
} Node;

Node *inserirTopo(Node *topo, int novoValor);
Node *deletarTopo(Node *topo);
void exibeTempo(struct timespec t1, struct timespec t2);

int main(void){
	int qtd_elementos = 3000;
	struct timespec t1, t2;
	
	int *vetor = malloc(qtd_elementos * sizeof(int));
	for(int i = 0; i <= qtd_elementos; ++i)
		vetor[i] = i;
	
	INICIA_CRONO
	for(int i = 1; i < qtd_elementos;++i){
		int *novoVetor = malloc((qtd_elementos - i) * sizeof(int));
		for(int j = 0; j < qtd_elementos - i;++j)
			novoVetor[j] = vetor[j+i];
	free(vetor);
	vetor = novoVetor;
	}
	PARA_CRONO
	printf("Tempo com vetor alocado dinamicamente: ");
	exibeTempo(t1, t2);
	
	Node *Lista = NULL;
	for(int i = 0; i < qtd_elementos; ++i) Lista = inserirTopo(Lista, i);
	
	INICIA_CRONO
	for(int i = 0; i < qtd_elementos; ++i) Lista = deletarTopo(Lista);
	PARA_CRONO
	printf("Tempo com Lista encadeada: ");
	exibeTempo(t1, t2);
	
	return 0;
}


Node *inserirTopo(Node *topo, int novoValor){
	Node *novoNode = calloc(1, sizeof(Node)); // Novo nó.
	novoNode->valor = novoValor;
	if(topo == NULL) return novoNode; // Se lista vazia, o novo nó é o primeiro elemento.
	else{
		novoNode->prox = topo;
		return novoNode;
	}
}

Node *deletarTopo(Node *topo){
	if(topo == NULL) return NULL; // Se lista vazia, retorna ponteiro nulo, não há o que remover nem para onde apontar.
	else{ // Lista não está vazia..
		Node *retorno = topo->prox;  // Topo da lista agora é o sucessor do elemento a ser removido.
		free(topo);                  // Topo antigo removido.
		return retorno;              // Retorna ponteiro para o novo topo da lista.
	}
}

void exibeTempo(struct timespec t1, struct timespec t2){
	double decorrido = (t2.tv_sec - t1.tv_sec) + (t2.tv_nsec - t1.tv_nsec) / 1e9;
	printf("%.9f s.\n", decorrido);
}
