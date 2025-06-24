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
    void *item;
    int tipo;
    Celula *prox;
    Celula *ant;
};

struct Lista
{
    Celula *primeiro, *ultimo;
};

Lista *inicializaLista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));

    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

// //Insere no final
// void insereListaCachorro(Lista* lista, void* item)
// {
//     Celula* nova = (Celula*)malloc(sizeof(Celula));

//     if (lista->ultimo == NULL)
//     {
//         lista->primeiro = lista->ultimo = nova;
//     }
//     else
//     {
//         lista->ultimo->prox = nova;
//         lista->ultimo = lista->ultimo->prox;
//     }
//     // lista->ultimo->ant = lista->ultimo;
//     lista->ultimo->item = item;
//     lista->ultimo->tipo = CACHORRO;
//     lista->ultimo->prox = NULL;
// }

// //Insere no final
// void insereListaGato(Lista* lista, void* item)
// {
//     Celula* nova = (Celula*)malloc(sizeof(Celula));

//     if (lista->ultimo == NULL)
//     {
//         lista->primeiro = lista->ultimo = nova;
//     }
//     else
//     {
//         lista->ultimo->prox = nova;
//         lista->ultimo = lista->ultimo->prox;
//     }
//     lista->ultimo->item = item;
//     lista->ultimo->tipo = GATO;
//     lista->ultimo->prox = NULL;
// }

void insereLista(Lista *lista, void *item, Tipo tipo)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    if (nova == NULL)
    {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    nova->item = item;
    nova->tipo = tipo;
    nova->prox = NULL;

    if (lista->ultimo == NULL)
    { // Lista vazia
        nova->ant = NULL;
        lista->primeiro = nova;
        lista->ultimo = nova;
    }
    else
    {                               // Lista não vazia
        nova->ant = lista->ultimo;  // Configura o anterior do novo nó
        lista->ultimo->prox = nova; // Atualiza o próximo do antigo último
        lista->ultimo = nova;       // Atualiza o ponteiro de último
    }
}

Celula *buscaLista(Lista *lista, char *nome)
{
    Celula *p = lista->primeiro;
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

void retiraLista(Lista *lista, char *nome)
{
    Celula *celula = buscaLista(lista, nome);

    if (!celula)
        return;

    // Caso especial: item unico
    if (celula == lista->primeiro && celula == lista->ultimo)
    {
        lista->primeiro = lista->ultimo = NULL;
    }

    // Vendo se é o primeiro
    else if (celula == lista->primeiro)
    {
        lista->primeiro = celula->prox;
        lista->primeiro->ant = NULL;
    }

    // Vendo se é o último
    else if (celula == lista->ultimo)
    {
        lista->ultimo = celula->ant;
        lista->ultimo->prox = NULL;
    }

    else
    {
        celula->ant->prox = celula->prox;
        celula->prox->ant = celula->ant;
    }

    // switch (celula->tipo)
    // {
    // case CACHORRO:
    //     desalocaCachorro(celula->item);
    //     break;
    // case GATO:
    //     desalocaGato(celula->item);
    // default:
    //     break;
    // }
    free(celula);
}

void imprimeLista(Lista *lista)
{
    Celula *aux = lista->primeiro;
    while (aux)
    {
        switch (aux->tipo)
        {
        case CACHORRO:
            imprimeCachorro(aux->item);
            break;
        case GATO:
            imprimeGato(aux->item);
            break;
        default:
            break;
        }
        aux = aux->prox;
    }
    printf("\n");
}

void liberaLista(Lista *lista)
{
    if (lista)
    {
        Celula *aux;
        Celula *prox;
        aux = lista->primeiro;
        while (aux)
        {
            prox = aux->prox;
            free(aux);
            aux = prox;
        }
        lista->primeiro = NULL;
        lista->ultimo = NULL;
        free(lista);
    }
    lista = NULL;
}

// Nova função de iteração
void paraCadaItem(Lista *lista, IteradorLista iterador, void *dadoExtra)
{
    if (lista == NULL || iterador == NULL)
        return;

    Celula *atual = lista->primeiro;
    while (atual != NULL)
    {
        iterador(atual->item, atual->tipo, dadoExtra);
        atual = atual->prox;
    }
}

//