#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "hash.h"

struct Pais
{
    char* sigla;
    int ouro, prata, bronze, total;
    Pais* prox;
};

Pais* criaPais(char* sigla, int ouro, int prata, int bronze, int total)
{
    Pais* pais = malloc(sizeof(Pais));

    pais->ouro = ouro;
    pais->prata = prata;
    pais->bronze = bronze;
    pais->total = total;

    pais->prox = NULL;
    pais->sigla = strdup(sigla);

    return pais;
}

void atualizaPais(Pais* pais, int ouro, int prata, int bronze, int total)
{
    pais->ouro = ouro;
    pais->prata = prata;
    pais->bronze = bronze;
    pais->total = total;
}

int comparaPaisSigla(Pais* pais, char* sigla)
{
    return strcmp(pais->sigla, sigla);
}

int comparaPaises(const void* p1, const void* p2)
{
    Pais* pais1 = *(Pais**)p1;
    Pais* pais2 = *(Pais**)p2;

    if (pais1->ouro == pais2->ouro)
    {
        if (pais1->prata == pais2->prata)
        {
            if (pais1->bronze == pais2->bronze)
            {
                return strcmp(pais1->sigla, pais2->sigla);
            }
            return pais2->bronze - pais1->bronze;
        }
        return pais2->prata - pais1->prata;
    }
    return pais2->ouro - pais1->ouro;
}

void imprimePais(Pais* pais)
{
    printf("%s %d %d %d %d\n", pais->sigla, pais->ouro, pais->prata, pais->bronze, pais->total);
}

struct Hash
{
    Pais** v;
    int n;
    int dim;
};

Hash* criaHash()
{
    Hash* tab = malloc(sizeof(Hash));

    tab->dim = 7;
    tab->n = 0;
    tab->v = calloc(tab->dim ,sizeof(Pais*));

    return tab;
}

static int hash(Hash* tab, char* pais)
{
    int c = 0;
    for (int  i = 0; i < strlen(pais); i++)
    {
        c += pais[i];
    }
    return (c % tab->dim);
}

static int redimensionaHash(Hash* tab)
{
    int antMax = tab->dim;
    Pais** ant = tab->v;

    tab->dim *= 1.947;
    tab->n = 0;
    tab->v = calloc(tab->dim, sizeof(Pais*));

    for (int i = 0; i < antMax; i++)
    {
        if (ant[i])
        {
            insereHash(tab, ant[i]);
        }
    }
    free(ant);
}

void insereHash(Hash* tab, Pais* pais)
{
    if (tab->n >= tab->dim*0.75)
        redimensionaHash(tab);

    int h = hash(tab, pais->sigla);
    if (tab->v[h])
    {
        Pais* aux = tab->v[h];
        while (aux->prox)
        {
            aux = aux->prox;
        }

        aux->prox = pais;
    }
    else
    {
        tab->v[h] = pais;
        tab->n++;
    }
}

Pais* hashBusca(Hash* tab, char* sigla)
{
    int h = hash(tab, sigla);
    if (tab->v[h])
    {
        Pais* aux = tab->v[h];
        while (aux && comparaPaisSigla(aux, sigla))
        {
            aux = aux->prox;
        }
        if (aux) return aux;
    }
    return NULL;
}

int qtdPaisesDistintos(Hash* tab)
{
    int count = 0;
    for (int i = 0; i < tab->dim; i++)
    {
        Pais* aux = tab->v[i];
        while (aux)
        {
            count++;
            aux = aux->prox;
        };
    }
    return count;
}

Pais** criaVetor(Hash* tab)
{
    int c = qtdPaisesDistintos(tab);
    Pais** paises = calloc(c, sizeof(Pais*));

    int j = 0;
    for (int i = 0; i < tab->dim; i++)
    {
        Pais* aux = tab->v[i];
        while (aux)
        {
            paises[j] = aux;
            j++;
            aux = aux->prox;
        }
    }
    return paises;
}

void imprimeHash(Hash* tab)
{
    Pais** paises = criaVetor(tab);
    int c = qtdPaisesDistintos(tab);
    qsort(paises, c, sizeof(Pais*), comparaPaises);

    for (int i = 0; i < c; i++)
    {
        imprimePais(paises[i]);
    }
}