#ifndef GATO_H
#define GATO_H

enum Agressividade{
    MANSO,
    BRAVO,
};

typedef struct Gato Gato;

Gato* inicGato(char* nome, int agressividade);

void imprimeGato(Gato* gato);

void desalocaGato(Gato* gato);

#endif