#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "aluno.h"

struct Aluno
{
    int mat;
    char* nome;
    int cr;
};

Aluno* criaAluno(int mat, char* nome, int cr)
{
    Aluno* aluno = malloc(sizeof(Aluno));

    aluno->mat = mat;
    aluno->nome = strdup(nome);
    aluno->cr = cr;

    return aluno;
}

int retornaMat(void* aluno)
{
    Aluno* a = (Aluno*)aluno;
    return a->mat;
}

int retornaCR(void* aluno)
{
    Aluno* a = (Aluno*)aluno;
    return a->cr;
}

void imprimeAluno(void* aluno, FILE* saida)
{
    Aluno* a = (Aluno*)aluno;
    fprintf(saida, "%d %s %d\n", a->mat, a->nome, a->cr);
}

void liberaAluno(void* aluno)
{
    Aluno* a = (Aluno*)aluno;

    if (aluno)
    {
        if (a->nome) free(a->nome);

        free(aluno);
    }
}

// Retorna 1 se aluno1 > aluno2
// Retorna -1 se aluno1 < aluno2
// Retorna 0 se igual
int comparaAlunoMat(void* aluno1, void* aluno2)
{
    Aluno* a1 = (Aluno*)aluno1;
    Aluno* a2 = (Aluno*)aluno2;

    if (a1->mat == a2->mat)
        return 0;

    if (a1->mat > a2->mat)
        return 1;

    if (a1->mat < a2->mat)
        return -1;
}

// Retorna o strcmp dos nomes
int comparaAlunoNome(void* aluno1, void* aluno2)
{
    Aluno* a1 = (Aluno*)aluno1;
    Aluno* a2 = (Aluno*)aluno2;

    return strcmp(a1->nome, a2->nome);
}