#include "Lista.h"
#include "Cachorro.h"
#include "Gato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Celula Celula;

struct Celula
{
    void* item;
    int tipo;
    Celula* prox;
    Celula* ant;
};

struct Lista
{
    Celula *primeiro, *ultimo;
};

Lista* inicializaLista()
{
    Lista* lista = (Lista*)malloc(sizeof(Lista));

    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

//Insere no final
void insereListaCachorro(Lista* lista, void* item)
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
    // lista->ultimo->ant = lista->ultimo;
    lista->ultimo->item = item;
    lista->ultimo->tipo = CACHORRO;
    lista->ultimo->prox = NULL;
}

//Insere no final
void insereListaGato(Lista* lista, void* item)
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
    lista->ultimo->item = item;
    lista->ultimo->tipo = GATO;
    lista->ultimo->prox = NULL;
}

Celula* buscaLista(Lista* lista, char* nome)
{
    Celula* p = lista->primeiro;
    while (p)
    {
        switch (p->tipo)
        {
        case CACHORRO:
            if (!strcmp(getNomeCachorro(p->item), nome))
            {
                return p;
            }
            break;
        case GATO:
            if (!strcmp(getNomeGato(p->item), nome))
            {
                return p;
            }
            break;
        default:
            break;
        }
        p = p->prox;
    }
    return NULL;
}

void retiraLista(Lista* lista, char* nome)
{
    Celula* celula = buscaLista(lista, nome);

    if (!celula)
        return;

    //Caso especial: p é o primeiro item
    if (celula == lista)
    {
        lista = celula->prox;
    }
    else
    {
        //O proximo do anterior vai receber o próximo do produto
        celula->ant->prox = celula->prox;
    }
    
    //Caso especial: vendo se p é o ultimo item
    if (celula->prox)
    {
        //O Anterior do próximo item vai receber o produto anterior
        celula->prox->ant = celula->ant;
    }
    
    desalocaProduto(celula->item);
    free(celula);
    return lista;
}
