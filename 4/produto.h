#ifndef PRODUTO_H
#define PRODUTO_H

#include "utils.h"
#include "produto.h"

typedef struct Produto Produto;

Produto* inicializaProduto(int codigo, char* nome, float preco);

Produto* leProduto();

void desalocaProduto(Produto* p);

void imprimeProduto(Produto* p);

#endif