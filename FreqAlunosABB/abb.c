#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "abb.h"

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

void incFalta(Aluno *aluno)
{
    aluno->faltas++;
}

void incPresenca(Aluno *aluno)
{
    aluno->pres++;
}

int comparaAluno(Aluno *aluno, char *nome)
{
    return strcmp(aluno->nome, nome);
}

static int comparaAlunos(Aluno *n1, Aluno *n2)
{
    return strcmp(n1->nome, n2->nome);
}

void imprimeAluno(Aluno *aluno)
{
    printf("%s %dP %dF\n", aluno->nome, aluno->pres, aluno->faltas);
}

struct Abb
{
    Aluno *info;
    Abb *dir, *esq;
};

Abb *criaAbb()
{
    return NULL;
}

Abb* abbInsere(Abb *arv, Aluno *item)
{
    if (arv == NULL)
    {
        arv = malloc(sizeof(Abb));

        arv->dir = criaAbb();
        arv->esq = criaAbb();
        arv->info = item;
    }
    else if (comparaAlunos(item, arv->info) > 0)
    {
        arv->dir = abbInsere(arv->dir, item);
    }
    else
    {
        arv->esq = abbInsere(arv->esq, item);
    }
    return arv;
}

void abbImprime(Abb *arv)
{
    if (arv != NULL)
    {
        abbImprime(arv->esq);
        imprimeAluno(arv->info);
        abbImprime(arv->dir);
    }
}

void abbLibera(Abb *arv)
{
    if (arv)
    {
        abbLibera(arv->esq);
        free(arv);
        abbLibera(arv->dir);
    }
}

Aluno* abbBusca(Abb* arv, char* nome)
{
    if (arv == NULL) return NULL;
    if (comparaAluno(arv->info, nome) > 0 ) return abbBusca(arv->esq, nome);
    if (comparaAluno(arv->info, nome) < 0 ) return abbBusca(arv->dir, nome);
    else return arv->info;
}
