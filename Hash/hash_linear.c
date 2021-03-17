/*
 * hash_linear.c
 *
 *  Created on: 9 de jan de 2016
 *      Author: avilapm
 */

#include "hash_linear.h"



int funcao_hashing(int num,int tam){
	return num % tam;
}

void mostrar_hash(hash tabela[],int tam){
	int i;
	for(i=0;i<tam;i++){
		if(tabela[i].st == OCUPADO){
			printf("\nEntrada %d: %d", i, tabela[i].chave);
		}
	}
}
void inserir(hash tabela[],int pos,int n,int tam) {
	int i=0;
	while(i < tam && tabela[(pos+i)%tam].st != LIVRE
			&& tabela[(pos+i)%tam].st != REMOVIDO){
		i = i+1;
	}

	if(i < tam){
		printf("Posicao: %d", (pos+i)%tam);
		tabela[(pos+i)%tam].chave = n;
		tabela[(pos+i)%tam].st = OCUPADO;
	} else {
		printf("\nTabela Cheia !");
	}
}
int buscar(hash tabela[], int n,int tam){
	int i=0;
	int pos=funcao_hashing(n,tam);

	while(i<tam && tabela[(pos+i)%tam].st!=LIVRE &&
			tabela[(pos+i)%tam].chave != n){
		i = i + 1;
	}

	if(tabela[(pos+i)%tam].chave == n &&
			tabela[(pos+1)%tam].st!=REMOVIDO){
		return(pos+i)%tam;
	} else {
		return tam;
	}
}
void remover(hash tabela[],int n,int tam){
	int posicao = buscar(tabela,n,tam);

	if(posicao < tam){
		tabela[posicao].st = REMOVIDO;
	} else {
		printf("\n%s", "Elemento nao existe na tabela !" );
	}
}
