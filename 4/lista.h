#ifndef LISTA_H
#define LISTA_H

#include "produto.h"

typedef struct Lista Lista;

Lista* inicializaLista();

void insereLista(Lista* lista, Produto* p);

void retiraLista(Lista* lista, int codigo);

void imprimeLista(Lista* lista);

void desalocaLista(Lista* lista);

#endif