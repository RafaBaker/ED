#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "hash.h"

int main(int argc, char const *argv[])
{
    FILE* pEntrada = fopen("entrada.txt", "r");
    assert(pEntrada && "Erro ao abrir arquivo de entrada");
    
    Hash* tab = hsh_cria();

    char palavraAtual[256];
    while (fscanf(pEntrada, "%[a-zA-Z] ", palavraAtual) == 1)
    {
        hsh_insere(tab, palavraAtual);
    }
    int contPalavras = retornaPalavrasDistintas(tab);
    int totalPalavras = retornaTotalPalavras(tab);
    Palavra* maior = retornaPalavraMaiorFreq(tab);

    // Segunda parte: ordenação
    Palavra** ord = retornaVetor(tab);
    qsort(ord, contPalavras, sizeof(Palavra*), comparaFreq);

    // Gerando arquivo de saida
    FILE* pSaida = fopen("saida.txt", "w");

    imprimeVetor(ord, contPalavras, pSaida);
    fprintf(pSaida, "%d palavras distintas encontradas\n", contPalavras);
    fprintf(pSaida, "%d palavras no total\n", totalPalavras);
    imprimeMaior(maior, pSaida);


    liberaHash(tab);
    liberaVetor(ord, contPalavras);
    fclose(pEntrada);
    fclose(pSaida);

    return 0;
}
