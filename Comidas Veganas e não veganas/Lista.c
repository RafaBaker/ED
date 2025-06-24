#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "Lista.h"

typedef struct Celula Celula;

struct Celula
{
    void* item;
    int tipo;
    Celula* prox;
};

struct Lista
{
    Celula* primeiro, *ultimo;
};

Lista* inicializaLista()
{
    Lista* lista = malloc(sizeof(Lista));

    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

void insereLista(Lista* lista, void* item, int tipo)
{
    Celula* nova = malloc(sizeof(Celula));
    nova->item = item;
    nova->tipo = tipo;
    nova->prox = NULL;

    if (lista->primeiro == NULL && lista->ultimo == NULL)
    {
        lista->primeiro = lista->ultimo = nova;
    }
    else
    {
        lista->ultimo->prox = nova;
        lista->ultimo = nova;
    }
}


int buscaLista(Lista* lista, char* nome)
{
    Celula* aux = lista->primeiro;
    int achou = 0;

    while (aux && !achou)
    {
        switch (aux->tipo)
        {
        case VEGANO:
            if (!strcmp(retornaNomeComidaVegana(aux->item), nome))
            {
                achou = 1;
            }
            break;
        case NAOVEGANO:
            if (!strcmp(retornaNomeComidaNaoVegana(aux->item), nome))
            {
                achou = 1;
            }
            break;
        default:
            break;
        }
        aux = aux->prox;
    }

    return achou;
}

void removeLista(Lista* lista, char* nome)
{
    Celula* aux = lista->primeiro;
    Celula* ant = aux;
    int achou = 0;

    while (aux && !achou)
    {
        switch (aux->tipo)
        {
        case VEGANO:
            if (!strcmp(retornaNomeComidaVegana(aux->item), nome))
            {
                achou = 1;
            }
            break;
        case NAOVEGANO:
            if (!strcmp(retornaNomeComidaNaoVegana(aux->item), nome))
            {
                achou = 1;
            }
            break;
        default:
            break;
        }
        ant = aux;
        aux = aux->prox;
    }

    if (!achou)
    {
        return;
    }

    if (lista->primeiro == lista->ultimo)
    {
        lista->primeiro = lista->ultimo = NULL;
    }
    else if (aux == lista->primeiro)
    {
        lista->primeiro = aux->prox;
    }
    else if (aux == lista->ultimo)
    {
        lista->ultimo = ant;
        ant->prox = NULL;
    }
    else
    {
        ant->prox = aux->prox;
    }
    free(aux);
}

float retornaValorLista(Lista* lista)
{
    if (!lista)
    {
        return 0;
    }

    Celula* aux = lista->primeiro;
    float valor = 0;
    while (aux)
    {
        switch (aux->tipo)
        {
        case VEGANO:
            valor += 30;
            break;
        case NAOVEGANO:
            valor += retornaValorComidaNaoVegana(aux->item);
        default:
            break;
        }
        aux = aux->prox;
    }

    return valor;
}

int quantidadeLista(Lista* lista)
{
    Celula* aux = lista->primeiro;
    int count = 0;
    while (aux)
    {
        count++;
        aux = aux->prox;
    }
    return count;
}

void imprimeLista(Lista* lista)
{
    Celula* aux = lista->primeiro;
    while (aux)
    {
        switch (aux->tipo)
        {
        case VEGANO:
            imprimeComidaVegana(aux->item);
            break;
        case NAOVEGANO:
            imprimeComidaNaoVegana(aux->item);
            break;
        default:
            break;
        }

        aux = aux->prox;
    }
    printf("\n");
}

// Não desaloca os itens dentro
void desalocaLista(Lista* lista)
{
    if (lista)
    {
        Celula* aux = lista->primeiro;
        while (aux)
        {
            Celula* prox = aux->prox;
            free(aux);
            aux = prox;
        }

        free(lista);
    }
    lista = NULL;
}