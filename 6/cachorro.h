#ifndef CACHORRO_H
#define CACHORRO_H

// enum Agressividade{
//     MANSO,
//     BRAVO,
// };

typedef struct Cachorro Cachorro;

Cachorro* inicCachorro(char* nome, int agressividade);

void imprimeCachorro(Cachorro* Cachorro);

void desalocaCachorro(Cachorro* Cachorro);

#endif