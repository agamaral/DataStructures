
/*
 * arvore.c
 *
 *  Created on: 29 de dez de 2015
 *      Author: avilapm
 */

#include "arvore.h"

#define max(a,b) ((a) > (b) ? (a) : (b))

void makeTree(node **root){
	*root = NULL;
}

/*********** inserir *****************/
void insertNode(node **leaf, int key_value){
	if(*leaf == NULL){
		*leaf = (node *) malloc(sizeof(node));
		(*leaf)->esq = NULL;
		(*leaf)->dir = NULL;
		(*leaf)->key = key_value;
	}else{
		if(key_value < (*leaf)->key)
			insertNode(&(*leaf)->esq, key_value);
		if(key_value > (*leaf)->key)
			insertNode(&(*leaf)->dir, key_value);
	}
}

/********** Remover *********************/
node *find_max_right(node **left){
	if((*left)->dir != NULL)
		return find_max_right(&(*left)->dir);
	else{
		node *aux = *left;
		if((*left)->esq != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
			*left = (*left)->esq;
		else
			*left = NULL;
		return aux;
	}
}

node *find_min_left(node **left){
	if((*left)->esq != NULL)
		return find_min_left(&(*left)->esq);
	else{
		node *aux = *left;
		if((*left)->dir != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
			*left = (*left)->dir;
		else
			*left = NULL;
		return aux;
	}
}

void removeNode(node **root, int key_value){
	if(*root == NULL){   // esta verificacao serve para caso o numero nao exista na arvore.
		printf("Numero nao existe na arvore!");
		getchar();
		return;
	}
	if(key_value < (*root)->key)
		removeNode(&(*root)->esq, key_value);
	else
		if(key_value > (*root)->key)
			removeNode(&(*root)->dir, key_value);
		else{    // se nao eh menor nem maior, logo, eh o numero que estou procurando!
			node *pAux = *root;
			if (((*root)->esq == NULL) && ((*root)->dir == NULL)){
				 // se nao houver filhos...
				free(pAux);
				(*root) = NULL;
			}
			else{     // so tem o filho da direita
				if ((*root)->esq == NULL){
					(*root) = (*root)->dir;
					pAux->dir = NULL;
					free(pAux); pAux = NULL;
				}
				else{            //so tem filho da esquerda
					if ((*root)->dir == NULL){
						(*root) = (*root)->esq;
						pAux->esq = NULL;
						free(pAux); pAux = NULL;
					}
					else{
						//Escolhi fazer o maior filho direito da subarvore esquerda.
						pAux = find_max_right(&(*root)->esq); //se vc quiser usar o Menor da esquerda, so o que mudaria seria isso:
						pAux->esq = (*root)->esq;          //   pAux = MenorEsquerda(&(*pRaiz)->direita);
						pAux->dir = (*root)->dir;
						(*root)->esq = NULL;
						(*root)->dir = NULL;
						free((*root));
						*root = pAux;
						pAux = NULL;
					}
				}
			}
		}
}


void destroyTree(node *root)
{
	if( root != 0 )
	{
		destroyTree(root->esq);
		destroyTree(root->dir);
		free( root );
	}
}

/******** Percurso *****************/
void preOrder(node *root){
	if(!root)
		return;
	if(root->key){
		printf("%d ", root->key);
	}

	preOrder(root->esq);
	preOrder(root->dir);
}


void inOrder(node *root){
	if(!root)
		return;

	inOrder(root->esq);

	if(root->key){
		printf("%d ", root->key);
	}


	inOrder(root->dir);
}

void postOrder(node *root){
	if(!root)
		return;

	postOrder(root->esq);
	postOrder(root->dir);

	if(root->key){
		printf("%d ", root->key);
	}
}
