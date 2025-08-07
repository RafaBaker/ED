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

Palavra *criaPalavra(char *palavra)
{
    Palavra *p = malloc(sizeof(Palavra));

    p->str = strdup(palavra);
    p->freq = 1;
    p->prox = NULL;

    return p;
}

void liberaPalavra(Palavra* palavra)
{
    if (palavra)
    {
        free(palavra->str);
        free(palavra);
    }
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

void hsh_insere(Hash *tab, void *palavra)
{
    char *p = (char *)palavra;

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
        Palavra *aux = tab->v[h];
        Palavra *ant = NULL;

        while (aux != NULL)
        {
            ant = aux;
            if (!strcmp(aux->str, p))
            {
                aux->freq++;
                return;
            }
            aux = aux->prox;
            // Criando a palavra
        }
        Palavra *plv = criaPalavra(p);
        ant->prox = plv;
    }
    else
    {
        Palavra *plv = criaPalavra(p);
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

int retornaPalavrasDistintas(Hash *tab)
{
    int count = 0;
    for (int i = 0; i < tab->dim; i++)
    {
        Palavra *aux = tab->v[i];
        while (aux != NULL)
        {
            count++;
            aux = aux->prox;
        }
    }
    return count;
}

int retornaTotalPalavras(Hash *tab)
{
    int count = 0;
    for (int i = 0; i < tab->dim; i++)
    {
        Palavra *aux = tab->v[i];
        while (aux != NULL)
        {
            count += aux->freq;
            aux = aux->prox;
        }
    }
    return count;
}

Palavra *retornaPalavraMaiorFreq(Hash *tab)
{
    int f = 0;
    Palavra *maior = NULL;
    for (int i = 0; i < tab->dim; i++)
    {
        Palavra *aux = tab->v[i];
        while (aux != NULL)
        {
            if (!f)
            {
                f = 1;
                maior = aux;
                aux = aux->prox;
                continue;
            }
            if (aux->freq > maior->freq)
                maior = aux;
            aux = aux->prox;
        }
    }
    return maior;
}

Palavra** retornaVetor(Hash* tab)
{
    int qtd = retornaPalavrasDistintas(tab);
    Palavra** vet = malloc(sizeof(Palavra*)*qtd);

    int index = 0;
    for (int i = 0; i < tab->dim; i++)
    {
        Palavra* aux = tab->v[i];
        while (aux != NULL)
        {
            vet[index] = aux;
            index++;
            aux = aux->prox;
        }
    }

    return vet;
}

int comparaFreq(const void* a, const void* b)
{
    Palavra** palA = (Palavra**)a;
    Palavra** palB = (Palavra**)b;
    int dif = (*palA)->freq - (*palB)->freq;
    if (dif == 0)
        return strcmp((*palA)->str, (*palB)->str);
    return dif;
}

void imprimeVetor(Palavra** ord, int tamanho, FILE* saida)
{
    for (int i = 0; i < tamanho; i++)
    {
        fprintf(saida, "%s %d\n", ord[i]->str, ord[i]->freq);
    }
    fprintf(saida, "------------------------\n");
}

void imprimeMaior(Palavra* palavra, FILE* saida)
{
    fprintf(saida, "%s é a palavra de maior frequencia (%d)\n", palavra->str, palavra->freq);
}

void liberaHash(Hash* tab)
{
    if (tab)
    {
        if (tab->v)
        {
            free(tab->v);
        }
        free(tab);
    }
    tab = NULL;
}

void liberaVetor(Palavra** vet, int tamanho)
{
    if (vet)
    {
        for (int i = 0; i < tamanho; i++)
        {
            liberaPalavra(vet[i]);
        }
        free(vet);
    }
}