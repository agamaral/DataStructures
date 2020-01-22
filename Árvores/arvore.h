/*
 * arvore.h
 *
 *  Created on: 29 de dez de 2015
 *      Author: avilapm
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef ARVORE_H_
#define ARVORE_H_

typedef struct No{
    int key;
    struct No *esq;
    struct No *dir;
} node;



void makeTree(node **root);
void destroyTree(node *root);


void insertNode(node **leaf, int key_value);

node *find_max_right(node **root);
node *find_min_left(node **root);
void removeNode(node **leaf, int key_value);

void preOrder(node *root);
void inOrder(node *root);
void postOrder(node *root);

int countNodes(node *root);
int countLeafs(node *root);

int depth(node *root);


#endif /* ARVORE_H_ */
