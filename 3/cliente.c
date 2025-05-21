#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "matriz.h"

int main(int argc, char const *argv[])
{
    Matriz* mat = inicializaMatriz(3, 3);

    for (int i = 0; i < recuperaNLinhas(mat); i++)
    {
        for (int j = 0; j < recuperaNColunas(mat); j++)
        {
            if (i == j)
            {
                modificaElemento(mat, i, j, 2);
            }
            else
            {
                modificaElemento(mat, i, j, 0);
            }
        }
    }

    imprimeMatriz(mat);
    imprimeLinha(mat, 1);
    printf("\n");

    
    Matriz* mat2 = inicializaMatriz(3, 3);
    int c = 1;
    for (int i = 0; i < recuperaNLinhas(mat); i++)
    {
        for (int j = 0; j < recuperaNColunas(mat); j++)
        {
            modificaElemento(mat2, i, j, c++);
        }
    }
    imprimeMatriz(mat2);

    Matriz* mult = multiplicacao(mat, mat2);
    imprimeMatriz(mult);

    Matriz* trans = transposta(mult);
    imprimeMatriz(trans);

    destroiMatriz(mat);
    destroiMatriz(mat2);
    destroiMatriz(mult);
    destroiMatriz(trans);

    return 0;
}

