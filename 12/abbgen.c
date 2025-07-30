#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "abbgen.h"

struct AbbGen
{
    void* info;
    AbbGen* esq;
    AbbGen* dir;
};

//Cria uma árvore vazia
AbbGen* abb_cria ()
{
    return NULL;
}

//libera o espaço de memória ocupado pela árvore a
AbbGen* abb_libera (AbbGen* a)
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
int abb_vazia (AbbGen* a)
{
    return a==NULL;
}

//imprime as informações dos nós da árvore
void abb_imprime (AbbGen* a, func_ptr_imprime imprime, FILE* saida)
{
    if (!abb_vazia(a))
    {
        abb_imprime(a->esq, imprime, saida);
        imprime(a->info, saida);
        abb_imprime(a->dir, imprime, saida);
    }
}

AbbGen* abb_insere (AbbGen* a, void* item, func_ptr_compara compara)
{
    if (a==NULL)
    {
        a = (AbbGen*)malloc(sizeof(AbbGen));
        a->info = item;
        a->esq = a->dir = NULL;
    }
    else if (compara(item, a->info) < 0)
        a->esq = abb_insere(a->esq,item, compara);
    else /* item < a->info */
        a->dir = abb_insere(a->dir,item, compara);

    return a;
}

AbbGen* abb_retira (AbbGen* r, void* item, func_ptr_compara compara)
{
    if (r == NULL)
        return NULL;
    else if (compara(r->info, item) > 0)
        r->esq = abb_retira(r->esq, item, compara);
    else if (compara(r->info, item) < 0)
        r->dir = abb_retira(r->dir, item, compara);

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
            AbbGen* t = r;
            r = r->dir;
            free (t);
        }
        /* só tem filho à esquerda */
        else if (r->dir == NULL)
        {
            AbbGen* t = r;
            r = r->esq;
            free (t);
        }
        /* nó tem os dois filhos */
        else
        {
            AbbGen* f = r->esq;
            while (f->dir != NULL)
            {
                f = f->dir;
            }
            r->info = f->info; /* troca as informações */
            f->info = item;
            r->esq = abb_retira(r->esq,item, compara);
        }
    }
    return r;
}
