/*
 * hash_lista.h
 *
 *  Created on: 10 de jan de 2016
 *      Author: avilapm
 */

#include <stdio.h>
#include <stdlib.h>


#ifndef SRC_HASH_LISTA_H_
#define SRC_HASH_LISTA_H_

struct hash {
	int chave;
	struct hash* prox;
};

typedef struct hash hash;

void inserir(hash *tabela[],int pos,int n);
int funcao_hashing(int num,int tam);
void mostrar_hash(hash *tabela[],int tam);
void excluir_hash(hash *tabela[],int num,int tam);

#endif /* SRC_HASH_LISTA_H_ */
