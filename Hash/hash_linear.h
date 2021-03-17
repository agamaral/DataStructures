/*
 * hash_linear.h
 *
 *  Created on: 9 de jan de 2016
 *      Author: avilapm
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef SRC_HASH_LINEAR_H_
#define SRC_HASH_LINEAR_H_



enum status {
	LIVRE=0,
	OCUPADO=1,
	REMOVIDO=2
};

typedef enum status status;

struct hash {
	int chave;
	status st;
};

typedef struct hash hash;

int funcao_hashing(int num,int tam);
void mostrar_hash(hash tabela[],int tam);
void inserir(hash tabela[],int pos,int n,int tam);
int buscar(hash tabela[], int n, int tam);
void remover(hash tabela[],int n, int tam);


#endif /* SRC_HASH_LINEAR_H_ */
