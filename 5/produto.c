#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "utils.h"
#include "produto.h"

struct Produto
{
    int codigo;
    char* nome;
    float preco;
};

Produto* inicializaProduto(int codigo, char* nome, float preco)
{
    Produto* p = (Produto*)malloc(sizeof(Produto));
    
    p->codigo = codigo;
    p->nome = nome;
    p->preco = preco;

    return p;
}

Produto* leProduto()
{
    int codigo;
    char* nome;
    float preco;

    scanf("%d\n", &codigo);
    nome = leLinha();
    scanf("%f\n", &preco);

    return inicializaProduto(codigo, nome, preco);
}

void desalocaProduto(Produto* p)
{
    if (p)
    {
        if (p->nome)
        {
            free(p->nome);
        }
        p->nome = NULL;
        free(p);
    }
    p = NULL;
}

int retornaCodigo(Produto* p)
{
    return p->codigo;
}

void imprimeProduto(Produto* p)
{
    //printf("Codigo: %d, Nome: %s, Preco: %.2f\n", p->codigo, p->nome, p->preco);
    printf("%d,%s,%.2f\n", p->codigo, p->nome, p->preco);
}
