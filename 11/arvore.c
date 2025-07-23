#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "arvore.h"

struct Arv
{
    Aluno* info;
    Arv* esq;
    Arv* dir;
};


//Cria uma árvore vazia
Arv* abb_cria ()
{
    return NULL;
}

//libera o espaço de memória ocupado pela árvore a
Arv* abb_libera (Arv* a)
{
    if (!abb_vazia(a))
    {
        abb_libera(a->esq); // Sub-arvore da esquerda
        abb_libera(a->dir); // Sub-arvore da direita
        free(a); // libera raiz
    }

    return NULL;
}

//retorna true se a árvore estiver vazia e false caso contrário
int abb_vazia (Arv* a)
{
    return a==NULL;
}

//imprime as informações dos nós da árvore
void abb_imprime (Arv* a)
{
    if (!abb_vazia(a))
    {
        imprimeAluno(a->info);
        printf("\n");
        abb_imprime(a->esq);
        abb_imprime(a->dir);
    }
}

void abb_imprimeRaiz (Arv* a)
{
    if (!abb_vazia(a))
    {
        imprimeAluno(a->info);
        printf("\n");
    }
    else
    {
        printf("ninguem\n");
    }
}

Arv* abb_insere (Arv* a, Aluno* item)
{
    if (a==NULL)
    {
        a = (Arv*)malloc(sizeof(Arv));
        a->info = item;
        a->esq = a->dir = NULL;
    }
    else if (retornaMat(item) < retornaMat(a->info))
        a->esq = abb_insere(a->esq,item);
    else /* item < a->info */
        a->dir = abb_insere(a->dir,item);

    return a;
}

Arv* abb_retira (Arv* r, Aluno* item)
{
    if (r == NULL)
        return NULL;
    else if (retornaMat(r->info) > retornaMat(item))
        r->esq = abb_retira(r->esq, item);
    else if (retornaMat(r->info) < retornaMat(item))
        r->dir = abb_retira(r->dir, item);

    else
    { /* achou o nó a remover */
        /* nó sem filhos */
        if (r->esq == NULL && r->dir == NULL)
        {
            free (r);
            r = NULL;
        }
        /* nó só tem filho à direita */
        else if (r->esq == NULL)
        {
            Arv* t = r;
            r = r->dir;
            free (t);
        }
        /* só tem filho à esquerda */
        else if (r->dir == NULL)
        {
            Arv* t = r;
            r = r->esq;
            free (t);
        }
        /* nó tem os dois filhos */
        else
        {
            Arv* f = r->esq;
            while (f->dir != NULL)
            {
                f = f->dir;
            }
            r->info = f->info; /* troca as informações */
            f->info = item;
            r->esq = abb_retira(r->esq,item);
        }
    }
    return r;
}

Arv* abb_busca (Arv* r, int v)
{
    if (r == NULL) return NULL;
    else if (retornaMat(r->info) > retornaMat(v)) return abb_busca (r->esq, v);
    else if (retornaMat(r->info) < retornaMat(v)) return abb_busca (r->dir, v);
    else return r;
}