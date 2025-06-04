#ifndef LISTA_H
#define LISTA_H

#include "lista.h"

enum Agressividade{
    MANSO,
    BRAVO,
};

enum Tipo{
    CACHORRO,
    GATO
};

typedef struct Lista Lista;

Lista* inicializaLista();

void insereListaCachorro(Lista* lista, void* item);

void insereListaGato(Lista* lista, void* item);

#endif