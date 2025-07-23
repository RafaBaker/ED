#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Aluno Aluno;

Aluno* criaAluno(int mat, char* nome);

int retornaMat(Aluno* aluno);

void imprimeAluno(Aluno* aluno);

void liberaAluno(Aluno* aluno);

#endif