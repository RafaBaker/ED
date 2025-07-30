#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct AbbGen AbbGen;

typedef void (*func_ptr_imprime)(void* dado, FILE* saida);

typedef int (*func_ptr_compara)(void* dado1, void* dado2);

//Cria uma árvore vazia
AbbGen* abb_cria ();

//libera o espaço de memória ocupado pela árvore a
AbbGen* abb_libera (AbbGen* a);

//retorna true se a árvore estiver vazia e false caso contrário
int abb_vazia (AbbGen* a);

//indica a ocorrência (1) ou não (0) do aluno (pela chave de busca mat)
int abb_pertence (AbbGen* a, int mat);

//imprime as informações dos nós da árvore
void abb_imprime (AbbGen* a, func_ptr_imprime imprime, FILE* saida);

AbbGen* abb_insere (AbbGen* a, void* item, func_ptr_compara compara);

AbbGen* abb_retira (AbbGen* r, void* item, func_ptr_compara compara);

AbbGen* abb_busca (AbbGen* r, int v, func_ptr_compara compara);


#endif