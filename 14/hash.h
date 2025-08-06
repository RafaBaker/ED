#ifndef HASH_H
#define HASH_H

typedef struct Hash Hash;
typedef struct Palavra Palavra;

Palavra* criaPalavra(char* palavra);

Hash* hsh_cria ();

static int hash (Hash* tab , int soma);

void hsh_insere (Hash* tab , void* palavra);

static void redimensiona (Hash* tab);

#endif