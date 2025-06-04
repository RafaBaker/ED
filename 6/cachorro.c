#include "cachorro.h"
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