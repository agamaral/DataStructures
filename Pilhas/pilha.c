/*
 * pilha.c
 *
 *  Created on: 4 de abr de 2016
 *      Author: avilapm
 */

#include <stdio.h>
#include <stdlib.h>

struct stack {
	int tam;
	int dado;
	struct stack *prox;
};

typedef struct stack Pilha;

void inicializar(Pilha *pilha);
int estaVazia(Pilha *pilha);
int push(Pilha *pilha,int dado);
int pop(Pilha *pilha);
int imprimeTopo(Pilha pilha);
void imprimeTudo(Pilha pilha);

int main() {

	int remove;
	Pilha p1;
	inicializar(&p1);
	
	if(estaVazia(&p1)){
		printf("\nPilha esta vazia !\n");
	}
	
	imprimeTudo(p1);
	
	push(&p1,5);
	printf("\nPilha Topo: %d",imprimeTopo(p1));
	
	push(&p1,9);
	printf("\nPilha Topo: %d",imprimeTopo(p1));
	
	push(&p1,11);
	printf("\nPilha Topo: %d",imprimeTopo(p1));
	
	imprimeTudo(p1);
	
	if(! estaVazia(&p1)) {
		remove = pop(&p1);
		printf("\nRemovido: %d",remove);
	} else {
	 	printf("\nPiha esta vazia !");
	}
	
	if(! estaVazia(&p1)){
		remove = pop(&p1);
		printf("\nRemovido: %d ",remove);
	}else {
	 	printf("\nPiha esta vazia !");
	}
	
	if(! estaVazia(&p1)){
		remove = pop(&p1);
		printf("\nRemovido: %d",remove);
	}else {
	 	printf("\nPiha esta vazia !");
	}
	
	if(! estaVazia(&p1)){
		remove = pop(&p1);
		printf("\nRemovido: %d",remove);
	}else {
		printf("\nPiha esta vazia !");
	}

}


void inicializar(Pilha *pilha) {
	pilha->tam = 0;
	pilha->prox = NULL;
}

int estaVazia(Pilha *pilha){
	return pilha->prox == NULL ? 1 : 0;
}

int push(Pilha *pilha,int dado){
	Pilha *novo = (Pilha *) malloc(sizeof(Pilha));
	if(novo == NULL)
	   return 0;

	novo->dado = dado;
	novo->prox = pilha->prox;
	pilha->prox = novo;

	pilha->tam++;

	return 1;
}

int pop(Pilha *pilha){
    Pilha *aux = pilha->prox;
    int rem = aux->dado;

    pilha->prox = pilha->prox->prox;
    free(aux);

    pilha->tam--;
    return rem;
}

int imprimeTopo(Pilha pilha){

    Pilha *aux = pilha.prox;
    
	return aux->dado;
}

void imprimeTudo(Pilha pilha){
	
	Pilha *aux = pilha.prox;
	
	if(aux == NULL)
	{
		printf("\nPilha esta vazia !");
	   return;
	}
	
	printf("\nPilha\n");
	
	while(aux != NULL){
		printf("%d  "  , aux->dado);
		aux = aux->prox;
	}
	printf("\n");
}
