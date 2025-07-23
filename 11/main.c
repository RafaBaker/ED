#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "arvore.h"


int main(int argc, char const *argv[])
{
    Aluno* rafael = criaAluno(100, "Rafael");
    Aluno* davi = criaAluno(101, "Davi");
    Aluno* yuri = criaAluno(102, "Yuri");
    Aluno* bruno = criaAluno(103, "Bruno");
    Aluno* ronald = criaAluno(104, "Ronald");
    Aluno* caio = criaAluno(105, "Caio");

    Arv* arvore = abb_cria();

    arvore = abb_insere(arvore, rafael);
    arvore = abb_insere(arvore, davi);
    arvore = abb_insere(arvore, yuri);
    arvore = abb_insere(arvore, bruno);
    arvore = abb_insere(arvore, ronald);
    arvore = abb_insere(arvore, caio);

    liberaAluno(rafael);
    liberaAluno(davi);
    liberaAluno(yuri);
    liberaAluno(bruno);
    liberaAluno(ronald);

    arv_libera(arvore);

    return 0;
}
