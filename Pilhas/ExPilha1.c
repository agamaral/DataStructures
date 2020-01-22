#include <stdio.h>
#include <stdlib.h>

struct pilha
{
    int dado;
    int tam;
    struct pilha *proximo;
};

typedef struct pilha Pilha;

void inicializarPilha(Pilha *p)
{
    p->tam = 0;
    p->proximo = NULL;
}

int push(Pilha *p, int v)
{
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    if (novo != NULL)
    {
        novo->dado = v;
        novo->tam = p->tam + 1;
        novo->proximo = p->proximo; //proximo = anterior;
        p->proximo = novo;
        p->tam++;
        return 1;
    }
    return 0;
}

void mostrar(Pilha *p)
{
    Pilha *aux = p->proximo;
    while (aux != NULL)
    {
        printf("%d\n", aux->dado);
        aux = aux->proximo;
    }
}

int main()
{
    Pilha p;

    inicializarPilha(&p);
    push(&p,4);
    push(&p,5);
    mostrar(&p);

    return 0;
}