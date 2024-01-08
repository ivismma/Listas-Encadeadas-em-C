#include <stdio.h>
#include <stdlib.h>

// Desafio 3:
// Criar uma fun��o que, dada duas listas encadeadas ordenadas, rearranje os n�s 
// entre as duas listas de modo que ambas se tornem uma �nica lista ordenada.

// Obs: N�o se deve criar uma nova lista por inser��o, apenas ligar os n�s correspondentes
// entre as duas listas de modo a juntar as duas, ordenadamente. 
// A "Lista3" ter� o novo topo que cont�m o menor elemento entre as duas listas, que j� ter� os n�s
// rearranjados ordenadamente.
// >>> Imagem de demonstra��o no reposit�rio do exerc�cio <<<

typedef struct node{
    int valor;
    struct node *prox;
} Node;

Node *inserirInicio(Node *topo, int novoValor);
void exibirLista(Node *topo);
Node *juntarListasOrdenadas(Node *topo1, Node* topo2);

int main(){
    Node *Lista1 = NULL;
    Node *Lista2 = NULL;
    Node *Lista3 = NULL;
    Lista1 = inserirInicio(Lista1, 1);
    Lista1 = inserirInicio(Lista1, 3);
    Lista1 = inserirInicio(Lista1, 8);
	printf("Lista 1:\n\n");
	exibirLista(Lista1);
    printf("\nLista 2:\n\n");
    Lista2 = inserirInicio(Lista2, 3);
    Lista2 = inserirInicio(Lista2, 5);
    Lista2 = inserirInicio(Lista2, 10);
    exibirLista(Lista2);
    Lista3 = juntarListasOrdenadas(Lista1, Lista2);
    printf("---------------\n");
    printf("\nMerge entre listas ordenadas:\n\n");
    exibirLista(Lista3);
    
    return 0;
}

Node *juntarListasOrdenadas(Node *topo1, Node* topo2){
	if(!topo1) return topo2;
	if(!topo2) return topo1;
	
	Node *atual1 = topo1, *atual2 = topo2;
	Node *novoTopo, *novoAtual;
	
	// Ponteiro novoAtual � quem ter� controle de onde a lista est� no processo de ordena��o, ele ir� rearranjar cada ponteiro pr�x na lista
	// trocando os n�s para fazer com que, ordenadamente, cada n� se ligue ao pr�ximo menor n� entre as duas listas.
	
	// Defini��o do novo topo (Menor elemento entre as duas listas)
	if(atual1->valor <= atual2->valor){
		novoTopo = atual1;
		atual1 = atual1->prox;
	}
	else{
		novoTopo = atual2;
		atual2 = atual2->prox;
	}
	novoAtual = novoTopo; 
	// Controle de fluxo para atualizar posi��o atual das duas listas, rearranjar os n�s e controlar o n� atual.
	while(atual1 != NULL && atual2 != NULL){
		if(atual1->valor < atual2->valor){ // Se elementoL1 < elementoL2
			novoAtual->prox = atual1;      // N� atual aponta para elemento da Lista 1
			novoAtual = atual1;            
			atual1 = atual1->prox;         // Itera (incrementa) n� da lista 1.
		}
		else{
			novoAtual->prox = atual2;      // elementoL2 < elementoL1
			novoAtual = atual2;
			atual2 = atual2->prox;         // Itera (incrementa) n� da lista 2.
		}
	}
	// Se uma lista > que a outra, pega o novoAtual e aponta para o resto da lista restante (j� que ambas est�o ordenadas).
	if(atual1 == NULL)
		novoAtual->prox = atual2;
	else 
		novoAtual->prox = atual1;
	
	return novoTopo;
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
