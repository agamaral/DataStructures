#include <stdio.h>
#include <stdlib.h>

struct fila
{
    int dado;
    int tam;
    struct fila *inicio;
    struct fila *fim;
    struct fila *prox;
};

typedef struct fila F;

void inicializar(F *fila)
{
    fila->tam = 0;
    fila->inicio = NULL;
    fila->fim = NULL;
}

int inserir(F *fila, int elemento)
{

    F *novo = (F *)malloc(sizeof(F));
    if (novo == NULL)
        return 0;
    novo->dado = elemento;
    novo->prox = NULL;

    if (fila->inicio == NULL)
    {
        fila->inicio = novo;
        fila->fim = novo;
    }
    else
    {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
    fila->tam++;
    return 1;
}

int remover(F *fila)
{
    F *inicio = fila->inicio;
    int r = inicio->dado;
    fila->inicio = fila->inicio->prox;
    free(inicio);
    fila->tam--;
    return r;
}

void imprimir(F *fila)
{

    F *elemento = fila->inicio;
    while (elemento != NULL)
    {
        printf("%d\n", elemento->dado);
        elemento = elemento->prox;
    }
    printf("\n");
}

int main()
{

}