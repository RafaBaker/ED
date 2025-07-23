#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "aluno.h"

typedef struct Arv Arv;

//Cria uma árvore vazia
Arv* abb_cria ();

int abb_vazia (Arv* a);

//libera o espaço de memória ocupado pela árvore a
Arv* abb_libera (Arv* a);

//retorna true se a árvore estiver vazia e false caso contrário
int abb_vazia (Arv* a);

//indica a ocorrência (1) ou não (0) do aluno (pela chave de busca mat)
int abb_pertence (Arv* a, int mat);

//imprime as informações dos nós da árvore
void abb_imprime (Arv* a);

Arv* abb_insere (Arv* a, Aluno* item);

Arv* abb_retira (Arv* r, Aluno* item);

Arv* abb_busca (Arv* r, int v);


#endif