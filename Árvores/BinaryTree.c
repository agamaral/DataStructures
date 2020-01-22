#include <stdio.h>
#include <stdlib.h>

// ED 1s/2019 - Antonio A Z Amaral

struct node
{
    int value;
    int level;
    struct node *left;
    struct node *right;
};

typedef struct node TypeNode;

void initialize(TypeNode **node)
{
    *node = NULL;
}

void addNode(TypeNode **node, int value)
{
    if (*node == NULL)
    {
        TypeNode *new = (TypeNode *)malloc(sizeof(TypeNode));
        new->value = value;
        new->left = NULL;
        new->right = NULL;
        *node = new;
    }
    else if ((*node)->value > value)
    {
        addNode(&(*node)->left, value);
    }
    else if ((*node)->value < value)
    {
        addNode(&(*node)->right, value);
    }
}

void preOrder(TypeNode *p) // print on the order of inserting...
{
    if (p == NULL)
    {
        return;
    }
    printf("%d ", p->value);
    preOrder(p->left);
    preOrder(p->right);
}

void inOrder(TypeNode *p) // printf in order...
{
    if (p == NULL)
    {
        return;
    }
    inOrder(p->left);
    printf("%d ", p->value);
    inOrder(p->right);
}

TypeNode *biggerNodeSubTreeLeft(TypeNode **node) //get the bigger node at our left (and have the greatest name ever)...
{
    if ((*node)->right != NULL)
    {
        return biggerNodeSubTreeLeft(&(*node)->right);
    }
    else
    {
        TypeNode *aux = *node;
        *node = (*node)->left;
        aux->left = NULL;
        return aux;
    }
}

void delete (TypeNode **node, int value) // delete on the 4 cases...
{
    if (*node == NULL) //wasn't found the value...
    {
        return;
    }
    else if (value > (*node)->value)
    {
        delete (&(*node)->right, value);
    }
    else if (value < (*node)->value)
    {
        delete (&(*node)->left, value);
    }
    else //remove the node...
    {
        if ((*node)->right == NULL && (*node)->left == NULL) //i'm in a leaf node...
        {
            TypeNode *aux = *node;
            free(aux);
            *node = NULL;
        }
        else if ((*node)->right == NULL) // a son at our left...
        {
            TypeNode *aux = *node;
            *node = (*node)->left;
            free(aux);
        }
        else if ((*node)->left == NULL) // a son at our right...
        {
            TypeNode *aux = *node;
            *node = (*node)->right;
            free(aux);
        }
        else // we got 2 sons...
        {
            TypeNode *bigger = biggerNodeSubTreeLeft(&(*node)->left);
            TypeNode *aux = *node;
            bigger->left = aux->left;
            bigger->right = aux->right;
            free(aux);
            *node = bigger;
        }
    }
}

int main(void)
{
    TypeNode *root = (TypeNode *)malloc(sizeof(TypeNode));
    initialize(&root);

    addNode(&root, 10);
    addNode(&root, 5);
    addNode(&root, 12);
    addNode(&root, 1);
    addNode(&root, 6);
    addNode(&root, 0);
    addNode(&root, 14);

    printf("Original tree...\n");
    preOrder(root);

    delete (&root, 10);

    printf("\n\nAfter removing...\n");
    preOrder(root);
}