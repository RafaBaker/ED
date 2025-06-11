#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "fila.h"
#include "amostra.h"

/* nó da fila para armazenar valores reais */
typedef struct Celula Celula;

struct Celula
{
    Amostra* item;
    Celula *prox;
};

/* estrutura da fila */
struct Fila
{
    Celula *primeiro;
    Celula *ultimo;
};

Fila* inicializaFila()
{
    Fila* fila = (Fila*)malloc(sizeof(Fila));

    fila->primeiro = NULL;
    fila->ultimo = NULL;

    return fila;
}

void insereFilaFinal(Fila* fila, Amostra* a)
{
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    
    if (fila->ultimo == NULL)
    {
        fila->primeiro = fila->ultimo = nova;
    }
    else
    {
        fila->ultimo->prox = nova;
        fila->ultimo = fila->ultimo->prox;
    }
    fila->ultimo->item = a;
    fila->ultimo->prox = NULL;
}

void insereFilaInicio(Fila* fila, Amostra* a)
{
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    
    if (fila->ultimo == NULL)
    {
        fila->primeiro = fila->ultimo = nova;
    }
    else
    {
        nova->prox = fila->primeiro;
        fila->primeiro = nova;
    }
    fila->primeiro->item = a; 
}

Amostra* retiraFila(Fila* fila)
{
    Celula* ant;
    Celula* a = fila->primeiro;
    Amostra* amostra = NULL;

    if (!a)
    {
        printf("Item nulo!\n");
        return NULL; //Não achou ou fila vazia
    }

    amostra = a->item;

    //Caso especial: fila com item unico
    if (a == fila->primeiro && a == fila->ultimo)
    {
        fila->primeiro = fila->ultimo = NULL;
        free(a);
    }
    else 
    {
        fila->primeiro = a->prox;
        free(a);
    }
    return amostra;
}

void imprimeFila(Fila* fila)
{
    Celula* aux;
    aux = fila->primeiro;
    while (aux)
    {
        imprimeAmostra(aux->item);
        aux = aux->prox;
    }
    printf("\n");
}

int filaVazia(Fila* fila)
{
    if (fila->primeiro == NULL)
    {
        return 1;
    }
    return 0;
}

void desalocaFila(Fila* fila)
{
    if (fila)
    {
        Celula* aux;
        Celula* prox;
        aux = fila->primeiro;
        while (aux)
        {
            prox = aux->prox;
            liberaAmostra(aux->item);
            free(aux);
            aux = prox;
        }
        fila->primeiro = NULL;
        fila->ultimo = NULL;
        free(fila);
    }
    fila = NULL;
}
