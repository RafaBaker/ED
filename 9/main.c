#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "arvore.h"


int main(int argc, char const *argv[])
{
    Aluno* rafael = criaAluno(100, "Rafael");
    Aluno* davi = criaAluno(101, "Davi");
    Aluno* yuri = criaAluno(102, "Yuri");
    Aluno* bruno = criaAluno(103, "Bruno");
    Aluno* ronald = criaAluno(104, "Ronald");

    Arv* a1= arv_cria(bruno, arv_criavazia(), arv_criavazia());

    Arv* a4= arv_cria(bruno, arv_criavazia(), a1);

    Arv* a5 = arv_cria(bruno, arv_criavazia(), a4);
    
    Arv* a2= arv_cria(davi, a5, arv_criavazia());
    
    Arv* a3= arv_cria(yuri,arv_criavazia(),arv_criavazia());
    
    Arv* a= arv_cria(rafael, a2, a3);

    arv_imprime(a);
    if (arv_pertence(a, 103))
    {
        imprimeAluno(davi);
        printf(" está presente na lista\n");
    }

    if (arv_pertence(a, 104))
    {
        imprimeAluno(ronald);
        printf(" está presente na lista\n");
    }
    else
    {
        imprimeAluno(ronald);
        printf(" NÃO está presente na lista\n");
    }


    Arv* paiBruno = arv_pai(a, retornaMat(bruno));
    printf("Pai do Bruno:\n");
    arv_imprimeRaiz(paiBruno);

    Arv* paiRafael = arv_pai(a, retornaMat(rafael));
    printf("Pai do Rafael:\n");
    arv_imprimeRaiz(paiRafael);

    int qtdFolhas = folhas(a);
    printf("Quantidade de folhas de A: %d\n", qtdFolhas);

    int qtdOcorrenciasBruno = ocorrencias(a, retornaMat(bruno));
    printf("Quantidade de vezes que Bruno aparece: %d\n", qtdOcorrenciasBruno);

    int alt = altura(a);
    printf("Altura da árvore A: %d\n", alt);

    liberaAluno(rafael);
    liberaAluno(davi);
    liberaAluno(yuri);
    liberaAluno(bruno);
    liberaAluno(ronald);

    arv_libera(a);

    return 0;
}
