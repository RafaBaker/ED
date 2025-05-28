#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "produto.h"
#include "utils.h"
#include "lista.h"

int main(int argc, char const *argv[])
{
    Produto* p1 = leProduto();
    Produto* p2 = leProduto();

    // imprimeProduto(p1);
    // imprimeProduto(p2);

    Lista* lista = inicializaLista();
    lista = insereLista(lista, p1);
    //imprimeLista(lista);
    lista = insereLista(lista, p2);
    //imprimeLista(lista);

    // //Retirando o fubá
    // lista = retiraLista(lista, 210501);
    // imprimeLista(lista);

    int qtd = 0;
    scanf("%d\n", &qtd);

    for (int i = 0; i < qtd; i++)
    {
        Produto* p = leProduto();
        lista = insereLista(lista, p);
    }

    imprimeLista(lista);

    //Retirando o arroz
    retiraLista(lista, 210507);
    imprimeLista(lista);

    desalocaLista(lista);

    return 0;
}
