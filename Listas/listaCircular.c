#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int dado;
    int tam;
    struct lista *fim;
    struct lista *inicio;
    struct lista *prox;
};

typedef struct lista L;

void inicializar(L *lista)
{
    lista->tam = 0;
    lista->inicio = NULL;
    lista->fim = NULL;
}

int inserirInicio(L *lista, int dado)
{
    L *novo = (L *)malloc(sizeof(L));

    if (novo == NULL)
        return 0;
    novo->dado = dado;
    lista->tam++;

    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        lista->fim = novo;
        novo->prox = lista->inicio;
        //lista->fim->prox = lista->inicio;
    }
    else
    {
        L *primeiro = lista->inicio;
        lista->inicio = novo;
        novo->prox = primeiro;
        lista->fim->prox = lista->inicio;
    }
    return 1;
}

int inserirFim(L *lista, int dado)
{
    L *novo = (L *)malloc(sizeof(L));

    if (novo == NULL)
        return 0;
    novo->dado = dado;
    lista->tam++;

    if (lista->fim == NULL)
    {
        lista->fim = novo;
        lista->inicio = novo;
        lista->fim->prox = lista->inicio;
    }
    else
    {
        L *ultimo = lista->fim;
        lista->fim = novo;
        ultimo->prox = novo;
        novo->prox = lista->inicio;
    }
    return 1;
}

void imprimir(L *lista)
{
    L *elemento = lista->inicio;
    int conta = 0;
    while (conta < lista->tam)
    {
        printf("%d ", elemento->dado);
        elemento = elemento->prox;
        conta++;
    }
}

int remover(L *lista, int dado)
{
    int i = 0;
    L *elemento = lista->inicio;
    L *anterior = NULL;
    int tam = lista->tam;
    for (i = 0; i < tam; i++)
    {
        if (elemento->dado == dado)
        {
            lista->tam--;
            if (elemento == lista->inicio)
            {
                lista->inicio = elemento->prox;
                free(elemento);
                elemento = lista->inicio;
            }
            else if (elemento == lista->fim)
            {
                lista->fim = anterior;
                free(elemento);
                lista->fim->prox = lista->inicio;
            }
            else
            {
                anterior->prox = elemento->prox;
                free(elemento);
                elemento = anterior->prox;
            }
        }
        else
        {
            anterior = elemento;
            elemento = elemento->prox;
        }
    }
}
int main()
{
    L lista;
    inicializar(&lista);
    int n[6];
    int i;
    int tam;
    scanf("%d", &tam);
    for (i = 0; i < tam; i++)
    {
        scanf("%d", &n[i]);
        inserirInicio(&lista, n[i]);
        inserirFim(&lista, n[i]);
    }
    remover(&lista, 3);
    imprimir(&lista);
}