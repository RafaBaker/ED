#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "aluno.h"

struct Aluno
{
    int mat;
    char* nome;
};

Aluno* criaAluno(int mat, char* nome)
{
    Aluno* aluno = malloc(sizeof(Aluno));

    aluno->mat = mat;
    aluno->nome = strdup(nome);

    return aluno;
}

int retornaMat(Aluno* aluno)
{
    return aluno->mat;
}

void imprimeAluno(Aluno* aluno)
{
    printf("Aluno %s", aluno->nome);
}

void liberaAluno(Aluno* aluno)
{
    if (aluno)
    {
        if (aluno->nome)
            free(aluno->nome);
        

        free(aluno);
    }
}