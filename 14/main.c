#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "hash.h"

int main(int argc, char const *argv[])
{
    FILE* pEntrada = fopen("entrada.txt", "r");
    assert(pEntrada && "Erro ao abrir arquivo de entrada");
    
    Hash* hash = hsh_cria();

    char palavraAtual[256];
    while (fscanf(pEntrada, "%[a-zA-Z] ", palavraAtual) == 1)
    {
        hsh_insere(hash, palavraAtual);
    }

    return 0;
}
