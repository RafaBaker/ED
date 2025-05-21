#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "lista.h"
#include "produto.h"

typedef struct Celula Celula;

struct Celula
{
    Produto* item;
    Celula* prox;
};

struct Lista
{
    Celula* primeiro, *ultimo;
};

Lista* inicializaLista()
{
    Lista* lista = (Lista*)malloc(sizeof(Lista));

    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

void insereLista(Lista* lista, Produto* p)
{
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    
    if (lista->ultimo == NULL)
    {
        lista->primeiro = lista->ultimo = nova;
    }
    else
    {
        lista->ultimo->prox = nova;
        lista->ultimo = lista->ultimo->prox;
    }
    lista->ultimo->item = p;
    lista->ultimo->prox = NULL;
}

void retiraLista(Lista* lista, int codigo)
{

}

void imprimeLista(Lista* lista)
{
    Celula* aux;
    aux = lista->primeiro;
    while (aux)
    {
        imprimeProduto(aux->item);
        aux = aux->prox;
    }
}

void desalocaLista(Lista* lista)
{
    if (lista)
    {
        Celula* aux;
        Celula* prox;
        aux = lista->primeiro;
        while (aux)
        {
            prox = aux->prox;
            desalocaProduto(aux->item);
            free(aux);
            aux = prox;
        }
        lista->primeiro = NULL;
        lista->ultimo = NULL;
        free(lista);
    }
    lista = NULL;
}