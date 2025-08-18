#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "hash.h"

struct Aluno
{
    char* nome;
    int pres, faltas;
    Aluno* prox;
};

