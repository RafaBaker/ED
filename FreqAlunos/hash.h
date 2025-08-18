#ifndef HASH_H
#define HASH_H

typedef struct Hash Hash;

typedef struct Aluno Aluno;

Hash* criaHash();

void hashInsere(Aluno* a, Hash* tab);

void liberaHash(Hash *tab);

#endif