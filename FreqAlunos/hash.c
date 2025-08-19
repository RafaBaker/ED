#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "hash.h"

struct Aluno
{
    char *nome;
    int pres, faltas;
    Aluno *prox;
};

Aluno *criaAluno(char *nome)
{
    Aluno *aluno = malloc(sizeof(Aluno));

    aluno->nome = strdup(nome);
    aluno->pres = aluno->faltas = 0;
    aluno->prox = NULL;

    return aluno;
}

void incFalta(Aluno* aluno)
{
    aluno->faltas++;
}

void incPresenca(Aluno* aluno)
{
    aluno->pres++;
}

int comparaAluno(Aluno* aluno, char* nome)
{
    return !strcmp(aluno->nome, nome);
}

static int comparaAlunoQsort(const void* n1, const void* n2)
{
    Aluno* a1 = *(Aluno**)n1;
    Aluno* a2 = *(Aluno**)n2;
    return strcmp(a1->nome, a2->nome);
}

void imprimeAluno(Aluno* aluno)
{
    printf("%s %dP %dF\n", aluno->nome, aluno->pres, aluno->faltas);
}

struct Hash
{
    Aluno **tab;
    int n;
    int dim;
};

static int hash(Hash *tab, int n)
{
    return (n % tab->dim);
}

static void redimensionaHash(Hash *tab)
{
    Aluno **ant = tab->tab;
    int antmax = tab->dim;
    tab->n = 0;
    tab->dim *= 1.947;

    tab->tab = (Aluno **)malloc(sizeof(Aluno *) * tab->dim);
    for (int i = 0; i < tab->dim; i++)
    {
        // Deixando a tabela vazia
        tab->tab[i] = NULL;
    }

    for (int i = 0; i < antmax; i++)
    {
        // Preenchendo com os items antigos
        if (ant[i])
        {
            hashInsere(ant[i], tab);
        }
    }
    free(ant);
}

Hash *criaHash()
{
    Hash *tab = malloc(sizeof(Hash));

    tab->dim = 7;
    tab->n = 0;
    tab->tab = (Aluno **)calloc(tab->dim, sizeof(Aluno *));

    return tab;
}

void hashInsere(Aluno *a, Hash *tab)
{
    if (tab->n > 0.75 * tab->dim)
        redimensionaHash(tab);

    // Calculando a soma dos caracteres dos nomes
    int i = 0, c = 0;
    c = strlen(a->nome);

    int h = hash(tab, c);

    if (tab->tab[h] == NULL)
    {
        tab->tab[h] = a;
        tab->n++;
    }
    else
    {
        Aluno *aux = tab->tab[h];
        while (aux->prox)
        {
            aux = aux->prox;
        }

        aux->prox = a;
    }
}

void liberaHash(Hash *tab)
{
    if (tab)
    {
        if (tab->tab)
        {
            free(tab);
        }

        free(tab);
    }
}

Aluno* hashBusca(Hash* tab, char* nome)
{
    int c = strlen(nome);
    int h = hash(tab, c);

    Aluno *aux = tab->tab[h];
    while (!comparaAluno(aux, nome))
    {
        aux = aux->prox;
    }
    if (!comparaAluno(aux, nome))
        return NULL;
    return aux;
}

int retornaAlunosDistintos(Hash* tab)
{
    Aluno* aux = NULL;
    int count = 0;

    for (int i = 0; i < tab->dim; i++)
    {
        aux = tab->tab[i];
        while (aux)
        {
            count++;
            aux = aux->prox;
        }
    }
    return count;
}

Aluno** retornaVetor(Hash* tab)
{
    int qtd = retornaAlunosDistintos(tab);
    Aluno** vet = malloc(sizeof(Aluno*)*qtd);

    int index = 0;
    for (int i = 0; i < tab->dim; i++)
    {
        Aluno* aux = tab->tab[i];
        while (aux != NULL)
        {
            vet[index] = aux;
            index++;
            aux = aux->prox;
        }
    }

    return vet;
}


void imprimeHash(Hash* tab)
{
    Aluno** ord = retornaVetor(tab);
    int t = retornaAlunosDistintos(tab);
    qsort(ord, t, sizeof(Aluno*), comparaAlunoQsort);
    for (int i = 0; i < t; i++)
    {
        imprimeAluno(ord[i]);
    }
}
