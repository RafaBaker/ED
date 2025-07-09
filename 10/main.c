#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "utils.h"

#define QUANTIDADE 100000

int main(int argc, char const *argv[])
{
    clock_t start, end;
    double tempo;

    start = clock();

    int* vetor = calloc(QUANTIDADE, sizeof(int));

    for (int i = 0; i < QUANTIDADE; i++)
    {
        vetor[i] = rand() % 1000 + 1;
        // printf("vetor[%d]: %d\n", i, vetor[i]);
    }

    bubbleSort(vetor, QUANTIDADE);

    free(vetor);

    end = clock();

    tempo = (double)(end-start) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.2f segundos\n", tempo);

    return 0;
}
