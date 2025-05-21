#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

//Tipo matriz (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementacao do TAD
struct matriz
{
    int linhas;
    int colunas;
    int** matriz;
};

/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz* inicializaMatriz (int nlinhas, int ncolunas)
{
    Matriz* matriz = (Matriz*)malloc(sizeof(Matriz));

    if (nlinhas == 0 || ncolunas == 0)
    {
        printf("Erro ao criar matriz (numero de linhas ou colunas = 0)\n");
        exit(0);
    }

    matriz->colunas = ncolunas;
    matriz->linhas = nlinhas;
    matriz->matriz = (int**)malloc(sizeof(int*)*nlinhas);

    for (int i = 0; i < nlinhas; i++)
    {
        matriz->matriz[i] = malloc(sizeof(int)*ncolunas);
        for (int j = 0; j < ncolunas; j++)
        {
            //printf("posição [%d][%d]\n", i, j);
            matriz->matriz[i][j] = 0;
        }
    }

    return matriz;
}

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento (Matriz* mat, int linha, int coluna, int elem)
{
    if (mat == NULL)
    {
        printf("Matriz não existe\n");
        exit(0);
    }

    if (linha < recuperaNLinhas(mat) && coluna < recuperaNColunas(mat))
    {
        mat->matriz[linha][coluna] = elem;
    }
    else
    {
        printf("N de colunas ou linhas não são validos dentro da matriz.\n");
        printf("linha e coluna passados: %d %d\n", linha, coluna);
        printf("linhas e colunas da mat: %d %d\n", recuperaNLinhas(mat), recuperaNColunas(mat));
        exit(0);
    }
}

/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a coluna
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: mat nao eh modificada
 */
int recuperaElemento(Matriz* mat, int linha, int coluna)
{
    if (mat == NULL)
    {
        printf("Matriz não existe\n");
        exit(0);
    }

    if (linha < recuperaNLinhas(mat) && coluna < recuperaNColunas(mat))
    {
        return mat->matriz[linha][coluna];
    }
    else
    {
        printf("N de colunas ou linhas não são validos dentro da matriz.\n");
        printf("linha e coluna passados: %d %d\n", linha, coluna);
        printf("linhas e colunas da mat: %d %d\n", recuperaNLinhas(mat), recuperaNColunas(mat));
        exit(0);
    }
}

/*Retorna o numero de colunas da matriz mat
 * inputs: a matriz
 * output: o numero de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNColunas (Matriz* mat)
{
    if (mat == NULL)
    {
        printf("Matriz não existe\n");
        exit(0);
    }
    return mat->colunas;
}

/*Retorna o numero de linhas da matriz mat
 * inputs: a matriz
 * output: o numero de linhas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNLinhas (Matriz* mat)
{
    if (mat == NULL)
    {
        printf("Matriz não existe\n");
        exit(0);
    }
    return mat->linhas;
}

/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada e matriz transposta existe
 */
Matriz* transposta (Matriz* mat)
{
    if (mat == NULL)
    {
        printf("Matriz não existe\n");
        exit(0);
    }

    Matriz* tspt = inicializaMatriz(mat->colunas, mat->linhas);

    for (int i = 0; i < mat->colunas; i++)
    {
        for (int j = 0; j < mat->linhas; j++)
        {
            modificaElemento(tspt, j, i, recuperaElemento(mat, i, j));
        }
    }
    return tspt;
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicacao
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1 correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 nao sao modificadas e a matriz multiplicacao existe
 */
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2)
{
    if (recuperaNColunas(mat1) != recuperaNLinhas(mat2))
    {
        printf("Erro ao multiplicar matrizes: a multiplicação não está definida");
        return NULL;
    }

    Matriz* mult = inicializaMatriz(recuperaNLinhas(mat1), recuperaNColunas(mat2));
    int res = 0;

    for (int i = 0; i < recuperaNLinhas(mat1); i++)
    {
        for (int j = 0; j < recuperaNColunas(mat2); j++)
        {
            for (int k = 0; k < recuperaNColunas(mat1); k++)
            {
                res = recuperaElemento(mult, i, j) + (recuperaElemento(mat1, i, k) * recuperaElemento(mat2, k, j));
                modificaElemento(mult, i, j, res);
            }
        }
    }
    
    return mult;
}

/*Imprime a matriz completa
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz* mat)
{
    if (mat == NULL)
    {
        printf("Matriz não existe\n");
        exit(0);
    }
    for (int i = 0; i < recuperaNLinhas(mat); i++)
    {
        for (int j = 0; j < recuperaNColunas(mat); j++)
        {
            //printf("oi estou aqui\n");
            printf("%d ", recuperaElemento(mat, i, j));
        }
        printf("\n");
    }
    printf("\n");
}

/*Imprime apenas uma linha da matriz
 * inputs: matriz mat e o indice da linha
 * output: nenhum
 * pre-condicao: matriz mat existe e indice eh valido na matriz
 * pos-condicao: nenhuma
 */
void imprimeLinha (Matriz* mat, int indice)
{
    if (mat == NULL)
    {
        printf("Matriz não existe\n");
        exit(0);
    }
    for (int i = 0; i < recuperaNColunas(mat); i++)
        printf("%d ", recuperaElemento(mat, indice, i));
    printf("\n");
}

/*Libera toda a memoria alocada para a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: memoria ocupada por linhas e colunas liberada!
 */
void destroiMatriz (Matriz* mat)
{
    if (mat)
    {
        if (mat->matriz)
        {
            for (int i = 0; i < recuperaNLinhas(mat); i++)
            {
                if (mat->matriz[i])
                {
                    free(mat->matriz[i]);
                }
                mat->matriz[i] = NULL;
            }
            free(mat->matriz);
        }
        mat->matriz = NULL;
        free(mat);
    }
    mat = NULL;
}

