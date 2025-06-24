#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "ComidaNaoVegana.h"
#include "ComidaVegana.h"

typedef float (*func_ptr_valor)(void* dado);

typedef void (*func_ptr_imprime)(void* dado);

enum Tipo
{
    VEGANO,
    NAOVEGANO,
};

typedef struct Lista Lista;

Lista* inicializaLista();

void insereLista(Lista* lista, void* item, int tipo);

int buscaLista(Lista* lista, char* nome);

void removeLista(Lista* lista, char* nome);

float retornaValorLista(Lista* lista);

int quantidadeLista(Lista* lista);

void imprimeLista(Lista* lista);

void desalocaLista(Lista* lista);

#endif