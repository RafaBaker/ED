#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "utils.h"

#define QUANTIDADE 1000000

int main(int argc, char const *argv[])
{
    clock_t start, end;
    double tempo;

    start = clock();

    int* vetor = calloc(QUANTIDADE, sizeof(int));

    for (int i = 0; i < QUANTIDADE; i++)
    {
        vetor[i] = rand() % 100000 + 1;
        // printf("vetor[%d]: %d\n", i, vetor[i]);
    }

    // buscaLinear(QUANTIDADE, vetor, 5);

    // quickSort(QUANTIDADE, vetor);

    buscaLinear(QUANTIDADE, vetor, 500);
    buscaBinaria(QUANTIDADE, vetor, 500);

    free(vetor);

    end = clock();

    tempo = (double)(end-start) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.9f segundos\n", tempo);

    return 0;
}
