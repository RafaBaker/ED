#ifndef HASH_H
#define HASH_H

typedef struct Pais Pais;

Pais* criaPais(char* sigla, int ouro, int prata, int bronze, int total);

void atualizaPais(Pais* pais, int ouro, int prata, int bronze, int total);

int comparaPaisSigla(Pais* pais, char* sigla);

typedef struct Hash Hash;

Hash* criaHash();

static int hash(Hash* tab, char* pais);

static int redimensionaHash(Hash* tab);

void insereHash(Hash* tab, Pais* pais);

Pais* hashBusca(Hash* tab, char* sigla);

void imprimeHash(Hash* tab);

#endif