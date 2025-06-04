#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "gato.h"
#include "cachorro.h"

int main(int argc, char const *argv[])
{
    Gato* branca = inicGato("Branca", BRAVO);
    Gato* ronaldo = inicGato("RonaldoCesar", MANSO);

    imprimeGato(branca);
    imprimeGato(ronaldo);

    desalocaGato(branca);
    desalocaGato(ronaldo);

    Cachorro* iris = inicCachorro("Iris", BRAVO);
    Cachorro* bob = inicCachorro("Bob", MANSO);
    Cachorro* baby = inicCachorro("Baby", MANSO);

    imprimeCachorro(iris);
    imprimeCachorro(bob);
    imprimeCachorro(baby);

    desalocaCachorro(iris);
    desalocaCachorro(bob);
    desalocaCachorro(baby);

    return 0;
}
