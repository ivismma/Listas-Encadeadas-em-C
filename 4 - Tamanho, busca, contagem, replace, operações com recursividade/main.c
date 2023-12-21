#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Biblioteca p/ valor booleano.

// Inser��o de elementos pelo topo e pelo in�cio (head & tail).

typedef struct node{
	int valor;
	struct node *prox;
} Node;

void exibirLista(Node *topo);
Node *inserirTopo(Node *topo, int novoValor);
Node *inserirInicio(Node *topo, int novoValor);
int tamanhoLista(Node *topo);
int tamanhoListaRec(Node *topo); // Fun��o recursiva do Tamanho da lista.
bool verifica_Lista(Node *topo, int busca);
int contagem_Lista(Node *topo, int busca);	
void trocar_Lista(Node *topo, int busca, int troca); // busca: antes | troca: depois

int main(){
	Node *lista1_topo = NULL; // Declara��o de lista vazia.
	int busca;
	
	lista1_topo = inserirTopo(lista1_topo, 5);
	lista1_topo = inserirTopo(lista1_topo, 4);
	lista1_topo = inserirTopo(lista1_topo, 3);
	lista1_topo = inserirTopo(lista1_topo, 3);
	lista1_topo = inserirTopo(lista1_topo, 3);
	lista1_topo = inserirTopo(lista1_topo, 1);
	
	/*
	printf("Digite um n�mero de 1 a 5 para obter as ocorrencias na lista: ");
	scanf("%d", &busca);
	printf("Quantidade de %d's na lista encadeada: %d.\n\n", busca, contagem_Lista(lista1_topo, busca));
	exibirLista(lista1_topo);
	*/
	printf("Lista antes da troca: \n"); exibirLista(lista1_topo);
	printf("Digite um numero CONTIDO na lista seguido por espaco do numero a substitui-lo: ");
	scanf("%d", &busca);
	if(!verifica_Lista(lista1_topo, busca)){
		printf("O numero inserido nao esta na lista encadeada.");
		return -1;
	}
	int n;
	scanf("%d", &n);
	trocar_Lista(lista1_topo, busca, n);
	printf("\nLista depois da troca: \n"); exibirLista(lista1_topo);
	
	return 0;
}

/////////////////////////////////////////
////  NOVAS FUN��ES E RECURSIVIDADE  ////

int tamanhoLista(Node *topo){ // Vers�o ITERATIVA - Tamanho da lista.
	Node *atual = topo;
	int i = 0;
	
	while(atual){ // Enquanto n� existe.
		++i;
		atual = atual->prox;
	}
	return i;
}

// Vers�o RECURSIVA - Tamanho da lista.
int tamanhoListaRec(Node *topo){ // Fun��o recursiva do Tamanho da lista.
	if(topo == NULL) return 0; // Se lista vazia, retorna tamanho 0.
	else return 1 + tamanhoListaRec(topo->prox); // Conta elementos da lista recursivamente at� retornar caso base (zero).
}

// Recursiva.
bool verifica_Lista(Node *topo, int busca){ // Busca um valor na lista e retorna se est� contido ou n�o (true/false).
	if(topo == NULL) return false; // 1� caso: Lista vazia OU chegou at� �ltimo elemento (caso base).
	else if(topo->valor == busca) return true; // 2� caso: O elemento buscado est� na itera��o atual.
	else{ // Percorre a lista recursivamente at� atingir caso base.
		return verifica_Lista(topo->prox, busca);
	}
}
// Existem dois casos bases na fun��o acima, 1�: Lista estar vazia/chegar no �ltimo elemento (n�o encontrou) | 2�: encontrou valor buscado.

// Recursiva.
int contagem_Lista(Node *topo, int busca){ // Parecida com a fun��o acima, por�m esta CONTA quantas vezes o valor buscado aparece na lista.
	if(topo == NULL) return 0; // 1� caso: Lista vazia ou chegou no �ltimo elemento.
	else if(topo->valor == busca) // 2� caso: Itera��o atual encontrou o valor.
		return 1 + contagem_Lista(topo->prox, busca); // 3� caso Elemento buscado encontrado, incrementa 1 e segue procurando poss�veis pr�ximas apari��es do valor.
	else // 4� caso N�o encontrou na itera��o atual, segue procurando poss�veis pr�ximas apari��es e N�O incrementa na contagem.
		return contagem_Lista(topo->prox, busca);
}
// na fun��o acima, o caso base agora � somente o primeiro pois somente ele TERMINA a continua��o da recurs�o.

// Recursiva.
void trocar_Lista(Node *topo, int busca, int troca){ // Recebe al�m da lista, valor a procurar e valor a substituir todas as apari��es da busca pelo novo elemento "troca".
	if(topo){ // topo != NULL 
		if(topo->valor == busca) topo->valor = troca; // Se valor da itera��o atual � o valor buscado, troca ele pelo novo.
		trocar_Lista(topo->prox, busca, troca); // DE QUALQUER FORMA, procede at� caso base (topo == NULL) preenchendo as poss�veis apari��es da busca pelo novo.
	}
	// Quando a recurs�o da lista chegar at� onde topo == NULL, return ser� chamado finalizando a recurs�o.
	return; // N�o retorna nada.
}

// Fun��es j� antes estudadas.

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

