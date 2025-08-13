#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "arv_exp.h"

// Tipo == '#': Operando
struct arv
{
    char tipo;
    int data;
    Arv *esq, *dir;
};

Arv *CriaVazia(void)
{
    Arv *arv = malloc(sizeof(Arv));

    arv->esq = arv->dir = NULL;
    arv->data = arv->tipo = 0;

    return arv;
}

Arv *CriaOperador(char c, Arv *esq, Arv *dir)
{
    Arv *op = CriaVazia();

    op->esq = esq;
    op->dir = dir;
    op->tipo = c;

    return op;
}

Arv *CriaOperando(int valor)
{
    Arv *operando = CriaVazia();

    operando->tipo = '#';
    operando->data = valor;

    return operando;
}

void Imprime(Arv *arv)
{
    if (arv != NULL)
    {
        // printf("(");
        //  Imprime(arv->esq);
        //  if (arv->tipo == '#')
        //  {
        //      printf("%d", arv->data);
        //      //printf(")");
        //  }
        //  else
        //  {
        //      printf("%c", arv->tipo);
        //  }
        //  Imprime(arv->dir);

        if (arv->esq != NULL && arv->esq->tipo == '#')
        {
            printf("(");
            Imprime(arv->esq);
            printf("%c", arv->tipo);
            Imprime(arv->dir);
            printf(")");
        }
        else
        {
            Imprime(arv->esq);
            if (arv->esq == NULL && arv->dir == NULL)
            {
                printf("%d", arv->data);
            }
            else
            {
                printf("%c", arv->tipo);
            }
            Imprime(arv->dir);
        }
    }
    // printf("\n");
}

Arv *Libera(Arv *arv)
{
    if (arv != NULL)
    {
        Libera(arv->esq);
        Libera(arv->dir);
        free(arv);
    }
    return NULL;
}

float Avalia(Arv *arv)
{
    if (arv->dir == NULL && arv->esq == NULL)
    {
        return (float)arv->data;
    }
    switch (arv->tipo)
    {
    case '+':
        return Avalia(arv->esq) + Avalia(arv->dir);
        break;
    case '-':
        return Avalia(arv->esq) - Avalia(arv->dir);
        break;
    case '*':
        return Avalia(arv->esq) * Avalia(arv->dir);
        break;
    case '/':
        return Avalia(arv->esq) / Avalia(arv->dir);
        break;
    default:
        printf("Operador inválido");
        break;
    }
}

int Folhas(Arv *arv)
{
    if (arv == NULL)
        return 0;
    if (arv->dir == NULL && arv->esq == NULL)
        return 1;

    int d = 0;
    int e = 0;

    d = Folhas(arv->dir);
    e = Folhas(arv->esq);

    return d + e;
}

static int max2(int a, int b)
{
    return (a > b) ? a : b;
}

int Altura(Arv *arv)
{
    if (arv == NULL)
        return -1;
    return 1 + max2(Altura(arv->esq), Altura(arv->dir));
}
