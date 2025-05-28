#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "lista.h"
#include "produto.h"

typedef struct Lista Lista;

struct Lista
{
    Produto* item;
    Lista* prox;
    Lista* ant;
};

Lista* inicializaLista()
{
    // Lista* lista = (Lista*)malloc(sizeof(Lista));

    // lista->primeiro = NULL;
    // lista->ultimo = NULL;

    // return lista;

    return NULL;
}

Lista* insereLista(Lista* lista, Produto* p)
{
    Lista* novo = (Lista*)malloc(sizeof(Lista));

    novo->item = p;
    novo->prox = lista;
    novo->ant = NULL;

    if (lista)
    {
        lista->ant = novo;
    }

    return novo;
}

Lista* buscaLista(Lista* lista, int codigo)
{
    for (Lista* p = lista; p; p = p->prox)
    {
        if (retornaCodigo(p->item) == codigo)
            return p;
    }
    return NULL;
}

Lista* retiraLista(Lista* lista, int codigo)
{
    //Achando (ou não) o Produto
    Lista* p = buscaLista(lista, codigo);

    if (!p)
    {
        return lista; //Não achou ou lista vazia
    }

    //Caso especial: p é o primeiro item
    if (p == lista)
    {
        lista = p->prox;
    }
    else
    {
        //O proximo do anterior vai receber o próximo do produto
        p->ant->prox = p->prox;
    }
    
    //Caso especial: vendo se p é o ultimo item
    if (p->prox)
    {
        //O Anterior do próximo item vai receber o produto anterior
        p->prox->ant = p->ant;
    }
    
    desalocaProduto(p->item);
    free(p);
    return lista;
}

void imprimeLista(Lista* lista)
{
    Lista* aux;
    aux = lista;
    printf("Codigo,Nome,Preco\n");
    while (aux)
    {
        imprimeProduto(aux->item);
        aux = aux->prox;
    }
    printf("\n");
}

void desalocaLista(Lista* lista)
{
    if (lista)
    {
        Lista* aux;
        Lista* prox;
        aux = lista;
        while (aux)
        {
            prox = aux->prox;
            desalocaProduto(aux->item);
            free(aux);
            aux = prox;
        }
        // free(lista);
    }
    lista = NULL;
}