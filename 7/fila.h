#ifndef FILA_H
#define FILA_H

#include "amostra.h"

typedef struct Fila Fila;

Fila* inicializaFila();

void insereFilaFinal(Fila* fila, Amostra* a);

void insereFilaInicio(Fila* fila, Amostra* a);

Amostra* retiraFila(Fila* fila);

void imprimeFila(Fila* fila);

int filaVazia(Fila* fila);

void desalocaFila(Fila* fila);

#endif