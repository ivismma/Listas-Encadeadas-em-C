#include <stdio.h>
#include <stdlib.h>

// Aula 9:
// Inser��o de um dado valor ap�s a 1� ocorr�ncia na lista
// Apagando uma lista encadeada por completo.

typedef struct node{
    int valor;
    struct node *prox;
} Node;

Node *inserirInicio(Node *topo, int novoValor);
void exibirLista(Node *topo);
Node *inserirAposOcorrencia(Node *topo, int inserir, int busca);
Node *apagarLista(Node* node);

int main(){
    Node *Lista1 = NULL;
    //                                  2 4 4 6 3 9 0
    Lista1 = inserirInicio(Lista1, 2);
    Lista1 = inserirInicio(Lista1, 4);
    Lista1 = inserirInicio(Lista1, 4);
    Lista1 = inserirInicio(Lista1, 6);
    Lista1 = inserirInicio(Lista1, 3);
    Lista1 = inserirInicio(Lista1, 9);
    Lista1 = inserirInicio(Lista1, 0);
	printf("Lista antes:\n");
	exibirLista(Lista1);
    Lista1 = inserirAposOcorrencia(Lista1, 10, 6);
    printf("Lista depois de insercao de um 10 apos o valor 6:\n");
    exibirLista(Lista1);
    Lista1 = apagarLista(Lista1);
    printf("\n\nLista apagada.");
    exibirLista(Lista1);
    
    return 0;
}

Node *inserirAposOcorrencia(Node *topo, int inserir, int busca){
	// Criando novo n�.
	Node *novoNode = (Node*) calloc(1,sizeof(Node));
	novoNode->valor = inserir;
	// 1� caso: Lista vazia, ent�o apenas inserir.
	if(topo == NULL) return novoNode;
	//2� caso: Ocorr�ncia no meio da lista (?).
	else{
		Node *atual = topo;
		while(atual->prox != NULL){
		if(atual->valor == busca){ 
			novoNode->prox = atual->prox;
			atual->prox = novoNode;
			return topo;
		}
		else atual = atual->prox; 
	}
	//3� caso: Valor buscado n�o encontrado, inserir no fim da lista.
	novoNode->prox = atual->prox;
	atual->prox = novoNode;
	return topo;
	}
}

Node *apagarLista(Node* node){ // Libera todos os n�s da heap, limpando a lista por completo.
	if(node != NULL){
		apagarLista(node->prox);
		free(node);
	} 
	return NULL;
}









Node *inserirInicio(Node *topo, int novoValor){
	Node *novoNode = calloc(1, sizeof(Node)); 
	novoNode->valor = novoValor;
	if (topo == NULL) return novoNode;
	else{
		Node *atual = topo;
		while(atual->prox != NULL) 
			atual = atual->prox; 
		atual->prox = novoNode; 
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
