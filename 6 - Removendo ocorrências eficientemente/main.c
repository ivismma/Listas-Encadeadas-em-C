#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Biblioteca p/ valor booleano.
#include <time.h> // Biblioteca para calcular efici�ncia das fun��es em termos de tempo.

// Aula 6:
// Removendo ocorr�ncias de um valor em uma lista encadeada 
// de maneira eficiente (Percorrer lista uma �nica vez).
// Comparando tempo em segundos da fun��o eficiente e n�o eficiente.

typedef struct node{
	int valor;
	struct node *prox;
} Node;

Node *del_todasOcorrencias(Node *topo, int valor, int *qtd_deletada); 
Node *funcaoNaoEficiente(Node *topo, int valor, int *qtd_deletada);

void exibirLista(Node *topo);
Node *inserirTopo(Node *topo, int novoValor);


// M�todo eficiente
Node *del_todasOcorrencias(Node *topo, int valor, int *qtd_deletada){
	*qtd_deletada = 0;
	if(!topo) return NULL;
	
	Node *atual = topo, 
	*aux, // Esse ponteiro armazenar� como var. auxiliar o n� a ser deletado na itera��o.
	*novoTopo;
	while(atual->valor == valor){ // 1� Loop: 
		aux = atual;
		atual = atual->prox;
		free(aux);
		++(*qtd_deletada);
		// Caso a lista inteira seja composta pelo valor a ser deletado..
		if(atual == NULL) return NULL; // Ficou vazia.
	}
	novoTopo = atual; // Caso o topo n�o for o valor buscado, continuar� o mesmo, sen�o, recebe o novo.
	// 2� Loop: Apagar n�s at� que o pr�ximo n seja o valor buscado, ap�s isso, o n� ATUAL aponta para o pr�x n� n�o remov�vel (tratar sequ�ncias de valor buscado).
	// >>> Demonstra��o no arquivo de imagem no reposit�rio <<<
	while(atual->prox != NULL){ 
		if(atual->prox->valor == valor){ // Se, no pr�ximo n�, o valor dele for valor a ser deletado, apaga e continua checando.
			aux = atual->prox;
			atual->prox = atual->prox->prox; // O pr�ximo n� ser� deletado, ent�o ele apontar� para o pr�ximo n� DO pr�ximo n� a ser deletado.
			free(aux); // Apaga pr�ximo n� (que � o n� a ser deletado).
			++(*qtd_deletada);
		}
		else atual = atual->prox;
	}
	return novoTopo;
}


// MAIN
int main(){
	Node *lista1 = NULL; // Declara��o de lista vazia.
	Node *lista2 = NULL; // Declara��o de lista vazia.
	int qtd_del;
	
	// Criando duas listas encadeadas com um volume imenso de dados.
	// Existem 40000 6's em cada lista encadeada.
	for(int i = 0; i < 400000;++i)
		lista1 = inserirTopo(lista1, i%10);
	for(int i = 0; i < 400000;++i)
		lista2 = inserirTopo(lista2, i%10);
	clock_t tic, toc; // tic = tempo 1 | toc = tempo 2
	printf("1o metodo - Deletando todas as buscas do valor 6...\n");
	tic = clock();
	lista1 = funcaoNaoEficiente(lista1, 6, &qtd_del);
	toc = clock();
	printf("Total de ocorrencias apagadas: %d\nTempo de execucao: %fs", qtd_del,
	(double) (toc - tic) / CLOCKS_PER_SEC);
	
	printf("\nMetodo eficiente - Deletando todas as buscas do valor 6...\n");
	tic = clock();
	lista2 = del_todasOcorrencias(lista2, 4, &qtd_del);
	toc = clock();
	printf("Total de ocorrencias apagadas: %d\nTempo de execucao: %fs", qtd_del,
	(double) (toc - tic) / CLOCKS_PER_SEC);
	// Se for mostrado valores redondos, sem sentido ou 0.000..s | Possivelmente problema de compat. do compilador usado.
	return 0;
}

//////// Fun��es j� estudadas ////////

// Metodo anterior:
Node *funcaoNaoEficiente(Node *topo, int valor, int *qtd_deletada){
	if(topo == NULL) return NULL; 	
	*qtd_deletada = 0;
	Node *atual = topo;
	Node *anterior = NULL; // Adicionei esta linha para garantir que anterior seja inicializado corretamente

	while(atual != NULL){
		if(atual->valor == valor){
			if(anterior == NULL) { // Se for o primeiro n�
				topo = atual->prox;
			} else {
				anterior->prox = atual->prox;
			}
			free(atual);
			atual = anterior ? anterior->prox : topo;
			++(*qtd_deletada);
		}
		else{
			anterior = atual;
			atual = atual->prox;
		}
	}

	return topo;
}

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
