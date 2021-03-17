/*
 * hash_lista.c
 *
 *  Created on: 10 de jan de 2016
 *      Author: avilapm
 */

#include "hash_lista.h"

void inserir(hash *tabela[],int pos,int n){
	hash *novo;
	novo = (hash *) malloc(sizeof(hash));
	novo->chave = n;
	novo->prox = tabela[pos];
	tabela[pos] = novo;
}
int funcao_hashing(int num,int tam){
	return num % tam;
}
void mostrar_hash(hash *tabela[],int tam) {
	hash *aux;
	int i,j;

	for(i=0; i<tam;i++){
		aux=tabela[i];
		j=i;
		while(aux != NULL){
			if(i != j){
				printf("%d: %d", i, aux->chave);
			} else {
			   printf("\nEntrada: %d: %d", i, aux->chave);
			}
			j++;
			aux = aux->prox;
		}
	}
}
void excluir_hash(hash *tabela[],int num,int tam) {
	int pos = funcao_hashing(num,tam);
	hash *aux;

	if(tabela[pos] != NULL){
		if(tabela[pos]->chave==num){
			aux = tabela[pos];
			tabela[pos] = tabela[pos]->prox;
			free(aux);
		} else {
			aux = tabela[pos]->prox;
			hash * ant = tabela[pos];
			while(aux != NULL && aux->chave != num){
				ant = aux;
				aux = aux->prox;
			}
			if(aux != NULL){
				ant->prox = aux->prox;
				free(aux);
			} else {
				printf("Numero nao encontrado!");
			}
		}
	} else {
		printf("Numero nao encontrado!");
	}
}
