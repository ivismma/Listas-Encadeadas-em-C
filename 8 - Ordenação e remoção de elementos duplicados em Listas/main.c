#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Biblioteca p/ valor booleano.

// Aula 8:
// Ordenando uma lista encadeada.      (com Bubble Sort)
// Removendo elementos duplicados em uma lista encadeada.

typedef struct node{
	int valor;
	struct node *prox;
} Node;

void swap(int *a, int *b); // Swap p/ Bubble Sort de ponteiros de struct.
bool ordenarLista(Node *topo);
void removerDuplicados(Node *topo);

void exibirLista(Node *topo);
Node *inserirInicio(Node *topo, int novoValor);

bool ordenarLista(Node *topo){
	if(topo == NULL) return false;
	if(topo->prox == NULL) return false;
	bool trocou;
	
	do{
		trocou = false; // Presuma que est� ordenado
		Node *atual = topo;
		Node *anterior = NULL;
		
		while(atual->prox != NULL){
			anterior = atual;
			atual = atual->prox;
			if(atual != NULL)
				if(atual->valor < anterior->valor){ // Caso queira ordenar decrescente, basta mudar '<' para '>'.
					swap(&anterior->valor, &atual->valor);
					trocou = true;
				}
		}
	} while(trocou);
	return true;
}

void swap(int *a, int *b){
	int aux = *a;
	*a = *b;      *b = aux;
}

void removerDuplicados(Node *topo){
	if(topo == NULL) return;
	if(topo->prox == NULL) return;
	
	Node *atual1, *atual2, *duplicado;
	atual1 = topo;   
	// atual1: N� exterior   <-- como se fosse i | n� exterior � como se fosse j
	// atual2: N� interior (percorre toda lista buscando por n�meros que correspondem a atual1 p/ remover duplicados).
	while(atual1 != NULL && atual1->prox != NULL){
		atual2 = atual1;                            // <- Incrementa n� EXTERIOR para o pr�ximo da vez
		while(atual2->prox != NULL){                // <- Loop para comparar n� atual com todo o resto da lista
			if(atual1->valor == atual2->prox->valor){
				duplicado = atual2->prox;           // <- var auxiliar p/ armazenar o duplicado
				atual2->prox = atual2->prox->prox;  // <- Pula para o pr�x do pr�x (pr�ximo depois do duplicado)
				free(duplicado);                    // <- Apaga n� duplicado
 			}
			else atual2 = atual2->prox;             // <-Incrementa n� INTERIOR p/ resto da lista
		}
		atual1 = atual1->prox; // Incrementa n� interior.
	}
}

// MAIN
int main(){
	Node *lista1 = NULL; // Declara��o de lista vazia.

	// Concatenaa��o de lista encadeada:
	lista1 = inserirInicio(lista1, 1);
	lista1 = inserirInicio(lista1, 3);
	lista1 = inserirInicio(lista1, 5);
	lista1 = inserirInicio(lista1, 5);
	lista1 = inserirInicio(lista1, 1);
	lista1 = inserirInicio(lista1, 5);
	lista1 = inserirInicio(lista1, 9);
	printf("Lista:\n");
	exibirLista(lista1);
	ordenarLista(lista1);
	printf("Lista ordenada:\n");
	exibirLista(lista1);
	printf("-------------------\nLista ordenada e remocao elementos duplicados:\n");
	removerDuplicados(lista1);
	exibirLista(lista1);
		
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
