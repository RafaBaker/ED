#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "utils.h"

void bubbleSort(int *vetor, int n)
{
    clock_t start, end;
    double tempo;
    start = clock();

    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }

    end = clock();
    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução (bubbleSort): %.9f segundos\n", tempo);
}

int buscaLinear(int n, int *vet, int elem)
{
    clock_t start, end;
    double tempo;
    start = clock();

    int i;
    for (i = 0; i < n; i++)
    {
        if (elem == vet[i])
        {
            end = clock();
            tempo = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Tempo de execução (buscaLinear): %.9f segundos\n", tempo);
            return i; /* elemento encontrado */
        }
    }
    /* elemento não encontrado após percorrer todo o vetor */
    end = clock();
    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução (buscaLinear): %.9f segundos\n", tempo);
    return -1;
}

void quickSort(int n, int *v)
{
    if (n <= 1)
        return;
    else
    {
        int x = v[0];
        int a = 1;
        int b = n - 1;
        do
        {
            while (a < n && v[a] <= x)
                a++; /* ver (1) */
            while (v[b] > x)
                b--; /* ver (2) */
            if (a < b)
            { /* faz troca */
                int temp = v[a];
                v[a] = v[b];
                v[b] = temp;
                a++;
                b--;
            }
        } while (a <= b);
        /* troca pivô */
        v[0] = v[b];
        v[b] = x;
        /* ordena sub-vetores restantes */
        quickSort(b, v);
        quickSort(n - a, &v[a]);
    }
}

int buscaBinaria(int n, int *vet, int elem)
{
    clock_t start, end;
    double tempo;
    start = clock();

    /* no início consideramos todo o vetor */
    int ini = 0;
    int fim = n - 1;
    int meio;
    /* enquanto a parte restante for maior que zero */
    while (ini <= fim)
    {
        meio = (ini + fim) / 2;
        if (elem < vet[meio])
            fim = meio - 1; /* ajusta posição final */
        else if (elem > vet[meio])
            ini = meio + 1; /* ajusta posição inicial */
        else
        {
            end = clock();
            tempo = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Tempo de execução (buscaBinaria): %.9f segundos\n", tempo);
            return meio; /* elemento encontrado */
        }
    }
    /* não encontrou: restou parte de tamanho zero */

    end = clock();
    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução (buscaBinaria): %.9f segundos\n", tempo);
    return -1;
}