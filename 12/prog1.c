#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "aluno.h"
#include "abbgen.h"

int main(int argc, char const *argv[])
{
    FILE* pEntrada = fopen("entrada.txt", "r");


    char linha[256];
    AbbGen* arvore = abb_cria();

    while (fgets(linha, sizeof(linha), pEntrada))
    {
        int mat=0, cr=0;
        char nome[50];

        sscanf(linha, "%d %s %d", &mat, nome, &cr);

        Aluno* aluno = criaAluno(mat, nome, cr);
        arvore = abb_insere(arvore, aluno, comparaAlunoMat);
    }

    FILE* pSaida = fopen("saida.txt", "w");

    abb_imprime(arvore, imprimeAluno, pSaida);
    
    fclose(pSaida);
    fclose(pEntrada);
    
    return 0;
}
