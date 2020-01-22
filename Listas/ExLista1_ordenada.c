#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int dado;             //dado q vai ser armazenado
    int tam;              // tam da lista
    struct lista *prox;   // prox elemento da lista
    struct lista *inicio; //primeiro elemento da lista
    struct lista *fim;    //ultimo elemento da lista
};

typedef struct lista TipoLista;

void inicializar(TipoLista *lista)
{
    lista->prox = NULL;
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

/*
//retorna 1 se inserir no começo da lista e 0 caso contrário
int inserirInicio(TipoLista *lista, int dado)
{
    TipoLista *novo = malloc(sizeof(TipoLista));
    if (novo != NULL)
    {
        //nao ha elementos no inicio?
        novo->dado = dado;
        if (lista->inicio == NULL)
        {
            lista->inicio = novo;
            lista->fim = novo;
            novo->prox = NULL;
            lista->tam++;
        }
        else
        {
            //pega o primeiro elemento da lista;
            TipoLista *primeiro = lista->inicio;
            novo->prox = primeiro;
            lista->inicio = novo;
            lista->tam++;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}


//retorna 1 se  inserir no final da lista e 0 caso contrário
int inserirFim(TipoLista *lista, int dado)
{
    TipoLista *novo = malloc(sizeof(TipoLista));
    if (novo != NULL)
    {
        novo->dado = dado;
        if (lista->fim == NULL)
        {
            lista->fim = novo;
            lista->inicio = novo;
            lista->tam++;
        }
        else
        {
            TipoLista *ultimo = lista->fim;
            lista->fim = novo;
            novo->prox = NULL;
            ultimo->prox = novo;
            lista->tam++;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
*/

void remover(TipoLista *lista, int dado)
{

    TipoLista *aux = lista->inicio;
    TipoLista *anterior = NULL;

    while (aux != NULL)
    {
        //é para remover aux?
        if (aux->dado == dado)
        {
            // *aux é o primeiro elemento da lista...
            if (aux == lista->inicio)
            {
                lista->inicio = aux->prox;
                free(aux);
                aux = lista->inicio;
            }
            else if (aux == lista->fim)
            {
                lista->fim = anterior;
                anterior->prox = NULL;
                free(aux);
            }
            else
            {
                anterior->prox = aux->prox;
                free(aux);
                aux = anterior->prox;
            }
        }
        anterior = aux;
        aux = aux->prox;
    }
}

//insere e ordena
int inserir(TipoLista *lista, int dado)
{

    TipoLista *novo = malloc(sizeof(TipoLista));

    if (novo == NULL)
    {
        return 0;
    }
    else
    {
        novo->dado = dado;

        if (lista->inicio == NULL)
        {
            lista->inicio = novo;
            lista->fim = novo;
            novo->prox = NULL;
        }
        else
        {
            TipoLista *anterior = NULL;
            TipoLista *atual = lista->inicio;
            while (novo->dado > atual->dado)
            {
                anterior = atual;
                atual = atual->prox;
                if (atual == NULL)
                {
                    break;
                }
            }
            //1° caso: o elemento deve ser inserido no inicio
            if (anterior == NULL)
            {
                novo->prox = atual;
                lista->inicio = novo;
            }
            //2 caso : o elemento deve ser inserido no final
            else if (atual == NULL)
            {
                anterior->prox = novo;
                novo->prox = NULL;
            }
            else
            {
                anterior->prox = novo;
                novo->prox = atual;
            }
        }
    }
}

void imprimir(TipoLista *lista)
{
    TipoLista *elemento = lista->inicio;
    printf("Tam lista = %d\n", lista->tam);
    while (elemento != NULL)
    {
        printf("%d\n", elemento->dado);
        elemento = elemento->prox;
    }
}

int main()
{
    TipoLista lista;

    inicializar(&lista);
    inserir(&lista, 1);
    inserir(&lista, 2);
    inserir(&lista, 5);
    inserir(&lista, 0);
    inserir(&lista, 5);
    imprimir(&lista);

    return 0;
}