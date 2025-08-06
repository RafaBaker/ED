#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "hash.h"

struct Palavra
{
    char *str;
    int freq;
    Palavra *prox;
};

Palavra* criaPalavra(char* palavra)
{
    Palavra* p = malloc(sizeof(Palavra*));

    p->str = strdup(palavra);
    p->freq = 0;
    p->prox = NULL;

    return p;
}

struct Hash
{
    int n;
    int dim;
    Palavra **v;
};



Hash *hsh_cria()
{
    Hash *tab = (Hash *)malloc(sizeof(Hash));
    tab->n = 0;
    tab->dim = 7;

    tab->v = (Palavra **)malloc(tab->dim * sizeof(Palavra *));
    for (int i = 0; i < tab->dim; ++i)
        tab->v[i] = NULL;
    return tab;
}

static int hash(Hash *tab, int soma)
{
    return (soma % tab->dim);
}

void hsh_insere(Hash *tab, void* palavra)
{
    char* p = (char*)palavra;

    if (tab->n > 0.75 * tab->dim)
        redimensiona(tab);

    // Somando o ASCII dos caracteres.
    int i = 0;
    int c = 0;
    while (p[i])
    {
        c += p[i];
        i++;
    }

    int h = hash(tab, c);

    if (tab->v[h] != NULL)
    {
        Palavra* aux = tab->v[h];

        if (!strcmp(aux->str, p))
        {
            aux->freq++;
        }
        else
        {
            while (aux->prox != NULL)
            {
                aux = aux->prox;
            }
            //Criando a palavra
            Palavra* plv = criaPalavra(p);
            aux->prox = plv;
        }
    }
    else
    {
        Palavra* plv = criaPalavra(p);
        plv->freq++;
        tab->v[h] = plv;
        tab->n++;
    }
}

static void redimensiona(Hash *tab)
{
    int max_ant = tab->dim;
    Palavra **ant = tab->v;
    tab->n = 0;
    tab->dim *= 1.947;
    /* evitar múltiplos */
    tab->v = (Palavra **)malloc(tab->dim * sizeof(Palavra *));
    for (int i = 0; i < tab->dim; ++i)
        tab->v[i] = NULL;
    for (int i = 0; i < max_ant; ++i)
    {
        if (ant[i])
        {
            hsh_insere(tab, ant[i]);
        }
    }
    free(ant);
}