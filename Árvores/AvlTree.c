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

int height(TypeNode *node)
{
    int hLeft, hRight;

    if (node->left == NULL)
    {
        hLeft = 0;
    }
    else
    {
        hLeft = height(node->left);
    }
    if (node->right == NULL)
    {
        hRight = 0;
    }
    else
    {
        hRight = height(node->right);
    }

    if (hRight > hLeft)
    {
        return ++hRight;
    }
    else
    {
        return ++hLeft;
    }
}

int balancingFator(TypeNode *node)
{
    int fb = 0;
    if (node->left != NULL)
    {
        fb = fb + height(node->left);
    }
    if (node->right != NULL)
    {
        fb = fb + height(node->right);
    }
    return fb;
}

void rotateRight(TypeNode **node)
{
    TypeNode *aux = *node;          // z
    TypeNode *left = (*node)->left; //x
    aux->left = left->right;        // w
    left->right = aux;              // x->z
    *node = left;                   // x
}

void rotateLeft(TypeNode **node)
{
    TypeNode *aux = *node;            // z
    TypeNode *right = (*node)->right; //x
    aux->right = right->left;         // w
    right->left = aux;                // x->z
    *node = right;                    // x
}

void doubleRotateLeft(TypeNode **node)
{
    TypeNode *aux = *node;
    TypeNode *right = (*node)->right;
    TypeNode *rightleft = right->left;
    aux->right = rightleft;
    right->left = rightleft->right;
    rightleft->right = right;
    *node = aux;
    rotateLeft(node);
}

void doubleRotateRight(TypeNode **node)
{
    TypeNode *aux = *node;
    TypeNode *left = (*node)->left;
    TypeNode *leftright = left->right;
    aux->left = leftright;
    left->right = leftright->left;
    leftright->left = left;
    *node = aux;
    rotateRight(node);
}

void balance(TypeNode **node)
{
    if ((*node)->left != NULL)
    {
        //balance to left
        balance(&(*node)->left);
    }
    if ((*node)->right != NULL)
    {
        //balance to right
        balance(&(*node)->right);
    }

    int fb = balancingFator(*node);

    if (fb >= 2)
    {
        fb = balancingFator((*node)->left);
        if (fb <= 1)
        {
            doubleRotateRight(node);
        }
        else
        {
            rotateRight(node);
        }
    }
    else if (fb <= -2)
    {
        fb = balancingFator((*node)->right);
        if (fb >= 1)
        {
            doubleRotateLeft(node);
        }
        else
        {
            rotateLeft(node);
        }
    }
}

int main(void)
{
    TypeNode *root = (TypeNode *)malloc(sizeof(TypeNode));
    initialize(&root);

    addNode(&root, 5);
    addNode(&root, 7);
    addNode(&root, 6);
    preOrder(root);
    //addNode(&root, 1);
    //addNode(&root, 6);
    //addNode(&root, 0);
    //addNode(&root, 14);

    int h = height(root);
    int fb = balancingFator(root);

    printf("Altura = %d\n", h);
    printf("Fator de balanceamento = %d\n", fb);

    balance(&root);
    preOrder(root);
    fb = balancingFator(root);
    printf("Fator de balanceamento = %d\n", fb);

    //printf("Original tree...\n");
    // preOrder(root);

    //delete (&root, 10);

    //printf("\n\nAfter removing...\n");
    //preOrder(root);
}