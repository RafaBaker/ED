#ifndef LISTA_H
#define LISTA_H

#include "lista.h"

enum Agressividade{
    MANSO,
    BRAVO,
};

typedef enum{
    CACHORRO,
    GATO
} Tipo;

typedef struct Lista Lista;

Lista* inicializaLista();

void insereLista(Lista* lista, void* item, Tipo tipo);

Celula* buscaLista(Lista* lista, char* nome);

void retiraLista(Lista* lista, char* nome);

// void insereListaCachorro(Lista* lista, void* item);
// void insereListaGato(Lista* lista, void* item);

void imprimeLista(Lista *lista);

void liberaLista(Lista* lista);

typedef void (*IteradorLista)(void *item, int tipo, void *dadoExtra);
void paraCadaItem(Lista *lista, IteradorLista iterador, void *dadoExtra);

#endif