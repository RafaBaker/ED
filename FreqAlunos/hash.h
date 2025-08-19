#ifndef HASH_H
#define HASH_H

typedef struct Hash Hash;

typedef struct Aluno Aluno;

Aluno* criaAluno(char* nome);

void incFalta(Aluno* aluno);

void incPresenca(Aluno* aluno);

int comparaAluno(Aluno* aluno, char* nome);

Hash* criaHash();

void hashInsere(Aluno* a, Hash* tab);

void liberaHash(Hash *tab);

Aluno* hashBusca(Hash* tab, char* nome);

void imprimeHash(Hash* tab);

#endif