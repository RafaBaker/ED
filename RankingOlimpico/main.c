#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "hash.h"

int main(int argc, char const *argv[])
{
    Hash* tab = criaHash();

    int ouro, prata, bronze, total;
    char sigla[4] = {0};
    while (scanf("%s %d %d %d %d\n", sigla, &ouro, &prata, &bronze, &total) == 5)
    {
        Pais* aux = hashBusca(tab, sigla);
        if (aux == NULL)
        {
            Pais* p = criaPais(sigla, ouro, prata, bronze, total);
            insereHash(tab, p);
        }
        else
        {
            atualizaPais(aux, ouro, prata, bronze, total);
        }
    }
    imprimeHash(tab);

    return 0;
}
