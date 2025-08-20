#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "abb.h"

#define MAX_TAM 256

int main()
{
    FILE* pEntrada = fopen("entrada.txt", "r");
    if (!pEntrada)
    {
        printf("Erro ao abrir arquivo de entrada\n");
        exit(1);
    }

    int qtdArq;
    fscanf(pEntrada, "%d\n", &qtdArq);
    char nome[100];
    Abb* raiz = criaAbb();

    while (fscanf(pEntrada, "%s\n", nome) == 1)
    {
        Aluno* a = criaAluno(nome);
        raiz = abbInsere(raiz, a);
    }


    char presenca;
    for (int i = 1; i <= qtdArq; i++)
    {
        //Lendo os arquivos
        char entrada[MAX_TAM] = {0};
        sprintf(entrada, "entrada%d.txt", i);
        FILE* pAula = fopen(entrada, "r");

        while (fscanf(pAula, "%s %c\n", nome, &presenca) == 2)
        {
            // char* token = strtok(linha, " ");
            Aluno* aux = abbBusca(raiz, nome);

            if (aux && presenca == 'P') incPresenca(aux);
            else if (aux && presenca == 'F') incFalta(aux);
        }

        fclose(pAula);
    }

    abbImprime(raiz);
    return 0;
}