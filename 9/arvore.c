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
Arv* arv_criavazia ()
{
    return NULL;
}

//cria uma árvore com a informação do nó raiz c, e com subárvore esquerda e e subárvore direita d
Arv* arv_cria (Aluno* c, Arv* e, Arv* d)
{
    Arv* p = malloc(sizeof(Arv));

    p->info = c;
    p->esq = e;
    p->dir = d;

    return p;
}

//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a)
{
    if (!arv_vazia(a))
    {
        arv_libera(a->esq); // Sub-arvore da esquerda
        arv_libera(a->dir); // Sub-arvore da direita
        free(a); // libera raiz
    }

    return NULL;
}

//retorna true se a árvore estiver vazia e false caso contrário
int arv_vazia (Arv* a)
{
    return a==NULL;
}

//indica a ocorrência (1) ou não (0) do aluno (pela chave de busca mat)
int arv_pertence (Arv* a, int mat)
{
    if (arv_vazia(a))
        return 0;

    return (retornaMat(a->info) == mat) || arv_pertence(a->esq, mat) || arv_pertence(a->dir, mat);
}

//imprime as informações dos nós da árvore
void arv_imprime (Arv* a)
{
    if (!arv_vazia(a))
    {
        imprimeAluno(a->info);
        printf("\n");
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
}

void arv_imprimeRaiz (Arv* a)
{
    if (!arv_vazia(a))
    {
        imprimeAluno(a->info);
        printf("\n");
    }
    else
    {
        printf("ninguem\n");
    }
}

//retorna a mãe/pai de um dado no que contém o aluno com a matrícula mat
Arv* arv_pai (Arv* a, int mat)
{
    if (arv_vazia(a) || retornaMat(a->info) == mat)
        return NULL;
    
    if ((a->dir && retornaMat(a->dir->info) == mat) || (a->esq && retornaMat(a->esq->info) == mat))
        return a;

    Arv* b = arv_pai(a->dir, mat);
    if (b)
        return b;

    b = arv_pai(a->esq, mat);
    if (b)
        return b;

    return NULL;
}

//retorna a quantidade de folhas de uma arvore binaria
int folhas (Arv* a)
{
    if (arv_vazia(a))
        return 0;
    if (a->dir == NULL && a->esq == NULL)
        return 1;
    
    int d = 0;
    int e = 0;

    d = folhas(a->dir);
    e = folhas(a->esq);

    return d+e;
}

//retorna o numero de ocorrencias de um dado aluno na árvore
int ocorrencias (Arv* a, int mat)
{
    int cont = 0;
    if (arv_vazia(a))
        return 0;
    if (retornaMat(a->info) == mat)
        cont++;
    
    cont += ocorrencias(a->dir, mat) + ocorrencias(a->esq, mat);    
    return cont;
}

static int max2(int a, int b)
{
    return (a>b) ? a : b;
}

//retorna a altura da árvore a
int altura(Arv* a)
{
    if (arv_vazia(a))
        return -1;
    return 1+max2(altura(a->esq), altura(a->dir));
}
