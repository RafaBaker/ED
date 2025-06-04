#include "Cachorro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Cachorro
{
    char* nome;
    int agressividade;
};

Cachorro* inicCachorro(char* nome, int agressividade)
{
    Cachorro* cachorro = malloc(sizeof(Cachorro));

    cachorro->nome = strdup(nome);
    cachorro->agressividade = agressividade;

    return cachorro;
}

void imprimeCachorro(Cachorro* cachorro)
{
    printf("Cachorro: %s\nAgressividade: %d\n", cachorro->nome, cachorro->agressividade);
}

int getAgressividadeCachorro(Cachorro* cachorro)
{
    return cachorro->agressividade;
}

char* getNomeCachorro(Cachorro* cachorro)
{
    return cachorro->nome;
}

void atualizaAgressividade(Cachorro* cachorro)
{
    cachorro->agressividade = (cachorro->agressividade++) % 2;
}

void desalocaCachorro(Cachorro* cachorro)
{
    if (cachorro)
    {
        if (cachorro->nome)
        {
            free(cachorro->nome);
        }
        cachorro->nome = NULL;
        free(cachorro);
    }
    cachorro = NULL;
}