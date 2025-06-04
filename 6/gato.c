#include "gato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Gato
{
    char* nome;
    int agressividade;
};

Gato* inicGato(char* nome, int agressividade)
{
    Gato* gato = malloc(sizeof(Gato));

    gato->nome = strdup(nome);
    gato->agressividade = agressividade;

    return gato;
}

void imprimeGato(Gato* gato)
{
    printf("Gato: %s\nAgressividade: %d\n", gato->nome, gato->agressividade);
}

void desalocaGato(Gato* gato)
{
    if (gato)
    {
        if (gato->nome)
        {
            free(gato->nome);
        }
        gato->nome = NULL;
        free(gato);
    }
    gato = NULL;
}