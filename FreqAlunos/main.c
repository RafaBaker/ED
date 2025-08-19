#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "utils.h"
#include "hash.h"

#define MAX_TAM 256

int main(int argc, char const *argv[])
{
    FILE* pEntrada = fopen("entrada.txt", "r");
    if (!pEntrada)
    {
        printf("Erro ao abrir arquivo de entrada\n");
        exit(1);
    }

    int qtdArq;
    fscanf(pEntrada, "%d\n", &qtdArq);

    char linha[MAX_TAM];
    Hash* tab = criaHash();
    while (lePalavra(pEntrada, linha))
    {
        hashInsere(criaAluno(linha), tab);
    }

    for (int i = 1; i <= qtdArq; i++)
    {
        //Lendo os arquivos
        char entrada[MAX_TAM] = {0};
        sprintf(entrada, "entrada%d.txt", i);
        FILE* pAula = fopen(entrada, "r");

        while (lePalavra(pAula, linha))
        {
            char c = 0;
            fscanf(pAula, "%c\n", &c);
            // char* token = strtok(linha, " ");
            Aluno* aux = hashBusca(tab, linha);

            if (c == 'P') incPresenca(aux);
            else if (c == 'F') incFalta(aux);
        }

        fclose(pAula);
    }
    
    imprimeHash(tab);

    return 0;
}
