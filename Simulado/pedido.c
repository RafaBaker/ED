//
//  pedido.h
//  Prova1ED
//
//  Created by Patricia Dockhorn Costa on 02/10/19.
//  Copyright © 2019 Patricia Dockhorn Costa. All rights reserved.
//

/* TAD Pedido. Um Pedido consiste de uma lista de Produtos!!!! */


#include "produto.h"
#include "pedido.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* Define o tipo TPedido (tipo opaco). Estrutura interna deste tipo eh definida na implementacao do TAD.
 * Trata-se da sentinela da lista e deve conter as seguintes informacoes:
 * Dono do pedido (char*) e os campos prim e ult da sentinela
 */

typedef struct Celula Celula;

struct Celula
{
    TProduto* item;
    Celula* proximo;
};

struct pedido
{
    char* dono;
    Celula *primeiro, *ultimo;
};

/*----------------------------------------------------------------------
 * Inicializa o pedido de um cliente (ou seja, a sentinela!)
 * inputs: nome do dono do pedido
 * output: Pedido inicializado
 * pre-condicao: nome devidamente alocado
 * pos-condicao: Pedido inicializado contendo o nome como informado
 *---------------------------------------------------------------------- */
TPedido* InicPedido (char* dono)
{
    TPedido* pedido = malloc(sizeof(TPedido));

    pedido->dono = strdup(dono);
    pedido->primeiro = NULL;
    pedido->ultimo = NULL;

    return pedido;
}

/*----------------------------------------------------------------------
 * Inclui um produto no pedido de um cliente (ou seja, a sentinela!). Inserir ao FINAL!
 * Lembrando que um produto nao pode ser inserido mais de uma vez no pedido! Neste caso, exiba a mensagem "Produto já existe no pedido\n"
 * inputs: o pedido e o produto a ser inserido
 * output: nada
 * pre-condicao: pedido e produto foram devidamente inicializados
 * pos-condicao: produto inserido no pedido OU lista inalterada (caso o produto ja esteja na lista)
 *----------------------------------------------------------------------*/
void IncluiProdutoPedido (TPedido* pedido, TProduto* prod)
{
    Celula* aux = pedido->primeiro;
    
    while (aux)
    {
        if (!strcmp(RetornaNome(aux->item), RetornaNome(prod)))
        {
            printf("Produto já existe no pedido\n");
            return;
        }
        aux = aux->proximo;
    }
    
    Celula* nova = malloc(sizeof(Celula));
    nova->item = prod;
    nova->proximo = NULL;
    if (!pedido->primeiro && !pedido->ultimo)
    {
        pedido->primeiro = pedido->ultimo = nova;
    }
    else if (pedido->primeiro == pedido->ultimo)
    {
        pedido->primeiro->proximo = nova;
        pedido->ultimo = nova;
    }
    else
    {
        pedido->ultimo->proximo = nova;
        pedido->ultimo = nova;
    }
}

/*----------------------------------------------------------------------
 * Imprime todos os dados de um pedido (o dono seguido de todos os produtos e ingredientes)
 * Caso o pedido seja novo e nao tenha ainda produtos, exibir a mensagem "Nao ha produtos neste pedido!\n"
 * inputs: o pedido
 * output: nada
 * pre-condicao: pedido devidamente inicializado
 * pos-condicao: funcao nao alterad os dados do pedido
 *----------------------------------------------------------------------*/
void ImprimePedido (TPedido* pedido)
{
    printf("\nDono: %s", pedido->dono);
    Celula* aux = pedido->primeiro;
    if (aux)
    {
        while (aux)
        {
            ImprimeIngredientes(aux->item);
            aux = aux->proximo;
        }
    }
    else 
    {
        printf("Não há produtos nesse pedido\n");
    }
}

/*----------------------------------------------------------------------
 * Retira a unica ocorrência do produto (caso ele exista na lista).
 * Importante!!! Esta funcao nao libera o produto! Apenas o retira do pedido!
 * inputs: o pedido e, o produto a ser retirado
 * output: nada
 * pre-condicao: pedido e produto devidamente inicializados
 * pos-condicao: pedido nao contem o produto
 *----------------------------------------------------------------------*/
void RetiraProdutoPedido (TPedido* pedido, char* prod)
{
    Celula* ant = NULL;
    Celula* p = pedido->primeiro;
    while (p && strcmp(RetornaNome(p->item), prod))
    {
        ant = p;
        p = p->proximo;
    }

    if (!p)
    {
        return;
    }

    if (p == pedido->primeiro && p == pedido->ultimo)
    {
        pedido->primeiro = pedido->ultimo = NULL;
    }
    else if (p == pedido->ultimo)
    {
        pedido->ultimo = ant;
        ant->proximo = NULL;
    }
    else if (p == pedido->primeiro)
    {
        pedido->primeiro = p->proximo;
    }
    else
    {
        ant->proximo = p->proximo;
    }
    free(p);

}

//A função envia pedido verifica se há restrição calórica ou restrição alimentar
//Se estiver tudo ok, retira o pedido da lista (libera o pedido, porém não libera o produto) e retorna 1
//Se não estiver ok, a lista permanece a mesma e a função retorna zero

/*----------------------------------------------------------------------
 * Primeiramente, verifica se há restrição calórica ou restrição alimentar, de acordo com os parametros
 **** Para a restricao calorica, deve-se somar as calorias de todos o produtos do pedido! Caso o numero de calorias do pedido ultrapasse a restricao, exiba a mensagem : "Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!"
 ****** Para a restricao alimentar, deve-se verificar se algum produto contem como ingrediente a restricao especificada. Caso algum produto contenha o ingrediente indicado, exiba a mensagem: nPedido não Enviado! Restricao alimentar no produto: %s\n
* Se estiver tudo certo (ou seja respeitando-se as restricoes), destroi o pedido da pessoa, porém não libera os produtos) e retorna 1
 * inputs: o pedido e as restricoes calorica e alimentar
 * output: 0 (problema em algumas das restricoes). 1 (pedido enviado)
 * pre-condicao: pedido devidamente inicializado e strings validas
 * pos-condicao: se houver problema com as restricoes, o pedido deve ficar inalterado. se estiver tudo ok com as restricoes, deve destruir o pedido, porem os produtos nao devem ser liberados (pois podem estar em outros pedidos, de outras pessoas).
 *----------------------------------------------------------------------*/
int EnviaPedido (TPedido* pedido, int restricao_calorica, char* restricao_alimentar)
{
    int caloriasTotais = 0;
    
    Celula* aux = pedido->primeiro;
    while (aux)
    {
        caloriasTotais += Calorias(aux->item);
        aux = aux->proximo;
    }
    if (caloriasTotais > restricao_calorica)
    {
        printf("Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!\n");
        return 0;
    }

    if (*restricao_alimentar)
    {
        aux = pedido->primeiro;
        while (aux)
        {
            if (VerificaIngrediente(aux->item, restricao_alimentar))
            {
                printf("Pedido não Enviado! Restricao alimentar no produto: %s\n", RetornaNome(aux->item));
                return 0;
            }
            aux = aux->proximo;
        }
    }

    if (pedido)
    {
        aux = pedido->primeiro;
        Celula* prox;

        while (aux)
        {
            prox = aux->proximo;
            free(aux);
            aux = prox;
        }
        pedido->primeiro = NULL;
        pedido->ultimo = NULL;
        if (pedido->dono)
        {
            free(pedido->dono);
        }
        free(pedido);
        pedido = NULL;
        return 1;
    }
    return -1;
}
