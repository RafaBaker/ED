#ifndef HASH_H
#define HASH_H

typedef struct Hash Hash;
typedef struct Palavra Palavra;

Palavra* criaPalavra(char* palavra);

Hash* hsh_cria ();

static int hash (Hash* tab , int soma);

void hsh_insere (Hash* tab , void* palavra);

static void redimensiona (Hash* tab);

int retornaPalavrasDistintas(Hash *tab);

int retornaTotalPalavras(Hash *tab);

Palavra *retornaPalavraMaiorFreq(Hash *tab);

Palavra** retornaVetor(Hash* tab);

int comparaFreq(const void* a, const void* b);

void imprimeVetor(Palavra** ord, int tamanho, FILE* saida);

void imprimeMaior(Palavra* palavra, FILE* saida);

void liberaHash(Hash* tab);

void liberaVetor(Palavra** vet, int tamanho);

#endif