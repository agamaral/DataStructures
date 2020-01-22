#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int dado;
    int tam;
    struct lista *proximo;
    struct lista *anterior;
    struct lista *inicio;
    struct lista *fim;
};

typedef struct lista TipoLista;

void inicializar(TipoLista *lista)
{
    lista->tam = 0;
    lista->inicio = NULL;
    lista->fim = NULL;
}

int inserirInicio(TipoLista *lista, int dado)
{
    TipoLista *novo = (TipoLista *)malloc(sizeof(TipoLista));

    if (novo == NULL)
    {
        return 0;
    }
    novo->dado = dado;
    lista->tam++;
    //inserindo o primeiro elemento;
    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        novo->proximo = NULL;
        novo->anterior = NULL;
        lista->fim = novo;
    }
    else
    {
        TipoLista *primeiro = lista->inicio;
        novo->proximo = primeiro;
        primeiro->anterior = novo;
        novo->anterior = NULL;
        lista->inicio = novo;
    }
    return 1;
}

int inserirFim(TipoLista *lista, int dado)
{
    TipoLista *novo = malloc(sizeof(TipoLista));
    if (novo == NULL)
    {
        return 0;
    }
    novo->dado = dado;
    lista->tam++;

    if (lista->fim == NULL)
    {
        lista->fim = novo;
        lista->inicio = novo;
        novo->proximo = NULL;
        novo->anterior = NULL;
    }
    else
    {
        TipoLista *ultimo = lista->fim;
        novo->anterior = ultimo;
        novo->proximo = NULL;
        ultimo->proximo = novo;
        lista->fim = novo;
    }
    return 1;
}

void imprimir(TipoLista *lista)
{
    TipoLista *elemento = lista->inicio;
    printf("Elementos da lista (tam = %d)\n", lista->tam);
    while (elemento != NULL)
    {
        printf("%d\n", elemento->dado);
        elemento = elemento->proximo;
    }
    printf("\n");
}

void imprimirReverso(TipoLista *lista)
{
    TipoLista *elemento = lista->fim;
    printf("Elementos da lista (tam = %d)\n", lista->tam);
    while (elemento != NULL)
    {
        printf("%d\n", elemento->dado);
        elemento = elemento->anterior;
    }
    printf("\n");
}

void remover(TipoLista *lista, int dado)
{
    TipoLista *elemento = lista->inicio;
    TipoLista *proximo = elemento->proximo;
    TipoLista *anterior = elemento->anterior;

    while (elemento != NULL)
    {
        if (elemento->dado == dado)
        {
            lista->tam--;
            if (elemento == lista->inicio)
            {
                lista->inicio = proximo;
                proximo->anterior = NULL;
                free(elemento);
                elemento = lista->inicio;
                proximo = elemento->proximo;
            }
            else if (elemento == lista->fim)
            {
                anterior->proximo = NULL;
                lista->fim = anterior;
                free(elemento);
            }
            else
            {
                anterior->proximo = proximo;
                proximo->anterior = anterior;
                free(elemento);
                elemento = proximo;
                if (elemento == NULL)
                {
                    break;
                }
                proximo = elemento->proximo;
            }
        }
        else
        {
            anterior = elemento;
            elemento = elemento->proximo;
            if (elemento == NULL)
            {
                break;
            }
            proximo = elemento->proximo;
        }
    }
}

int main()
{
    TipoLista lista;
    inicializar(&lista);
    inserirInicio(&lista, 1);
    inserirInicio(&lista, 4);
    inserirFim(&lista, 3);
    inserirFim(&lista, 5);
    remover(&lista, 5);
    imprimir(&lista);
    //imprimirReverso(&lista);
}