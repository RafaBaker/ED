#ifndef LISTA_H
#define LISTA_H

#include "produto.h"

typedef struct Lista Lista;

Lista* inicializaLista();

void insereLista(Lista* lista, Produto* p);

/**
 * Essa função desaloca os itens que foram retirados da memória
 */
void retiraLista(Lista* lista, int codigo);

void imprimeLista(Lista* lista);

void desalocaLista(Lista* lista);

#endif