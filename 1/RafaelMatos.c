#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

void calc_esfera(float r, float *area, float *volume)
{
    *area = 4 * PI * r * r;
    *volume = (4 * PI * r * r * r) / 4;
}

int raizes(float a, float b, float c, float *x1, float *x2)
{
    double delta = 0;
    delta = (b * b) - (4 * a * c);
    if (delta < 0)
        return 0;

    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);

    return 1;
}

int pares(int n, int *vet)
{
    int qtd = 0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i] % 2 == 0)
            qtd++;
    }

    return qtd;
}

void inverte(int n, int *vet)
{
    int j = n - 1;
    int aux;
    for (int i = 0; i < (n / 2); i++)
    {
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
        j--;
    }
}

double avalia(double *poli, int grau, double x)
{
    double resultado = 0.0;
    for (int i = 0; i <= grau; i++)
    {
        resultado += poli[i] * pow(x, i);
    }
    return resultado;
}

int** inverte2 (int n, int* vet)
{
    int** ord = malloc(sizeof(int*)*n);

    for (int i = 0; i < n; i++)
    {
        ord[i] = &vet[i];
    }


    int menor = 0;
    int* aux;
    for (int i = 0; i < n-1; i++)
    {
        menor = i;
        for (int j = i+1; j < n; j++)
        {
            if (*ord[j] < *ord[menor])
            {
                menor = j;
            }
        }
        aux = ord[i];
        ord[i] = ord[menor];
        ord[menor] = aux;
    }

    return ord;
}

int main(int argc, char const *argv[])
{
    // Questao 1
    float area;
    float volume;
    float r = 3;

    area = 0;
    volume = 0;

    calc_esfera(r, &area, &volume);

    printf("Esfera de Raio %.2f\nÁrea: %.2f\n Volume: %.2f\n", r, area, volume);


    // Questao 2
    float x1 = 0;
    float x2 = 0;

    if (raizes(1.0, -5.0, 6.0, &x1, &x2))
    {
        printf("x1: %.2f\nx2: %.2f\n", x1, x2);
    }
    
    // Questao 3
    int vet[5] = {1, 2, 3, 4, 5};
    printf("Quantidade de pares no vetor: %d\n", pares(5, vet));


    // Questao 4
    inverte(5, vet);
    printf("Vetor invertido: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");

    // Questao 5
    double coef[3] = {12.0, 2.0, 3.0};
    int grau = 2;
    double x = 2;
    double valor = avalia(coef, grau, x);
    printf("O valor do polinômio para x = %.2f é %.2f\n", x, valor);

    // Desafio

    int vet1[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int** ord = inverte2(10, vet1);
    printf("Vetor Ordenado: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", *ord[i]);
    }
    printf("\n");

    //Liberando o vetor :D 
    free(ord);

    return 0;
}
