#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Aluno Aluno;

Aluno* criaAluno(int mat, char* nome, int cr);

int retornaMat(void* aluno);

int retornaCR(void* aluno);

void imprimeAluno(void* aluno, FILE* saida);

void liberaAluno(void* aluno);

int comparaAlunoMat(void* aluno1, void* aluno2);

int comparaAlunoNome(void* aluno1, void* aluno2);

#endif