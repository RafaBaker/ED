#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "lista.h"



/*TipoItem Aluno (tipo opaco)
 Estrutura interna do tipo deve ser definida na implementacao do TAD. Devem ser definidos campos:
 - nome (string)
 - matricula (int) */
struct aluno
{
    char* nome;
    int matricula;
    TAluno* proximo;
};

/*Tipo que define a lista (tipo opaco)
 Estrutura interna do tipo deve ser definida na implementacao do TAD.
 Usar lista COM Sentinela */
struct lista
{
    TAluno* primeiro, *ultimo;
};

/*Inicializa o sentinela de uma lista
 * inputs: nenhum
 * output: Sentinela inicializado (lista vazia)
 * pre-condicao: nenhuma
 * pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL */
TLista* CriaLista()
{
    TLista* lista = malloc(sizeof(TLista));

    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

/*Inicializa um TipoItem aluno
 * inputs: o nome e a matricula do aluno
 * output: um ponteiro para o tipo TAluno criado
 * pre-condicao: nome e matricula validos
 * pos-condicao: tipo TAluno criado, com os campos nome e matricula COPIADOS */
TAluno* InicializaAluno(char* nome, int matricula)
{
    TAluno* aluno = malloc(sizeof(TAluno));

    aluno->nome = strdup(nome);
    aluno->matricula = matricula;
    aluno->proximo = NULL;

    return aluno;
}

/*Insere um aluno na primeira posicao da lista de alunos
 * inputs: aluno a ser inserido na lista (do tipo TAluno) e a lista
 * output: nenhum
 * pre-condicao: aluno n�o NULL e lista n�o NULL (mas, a lista pode estar vazia)
 * pos-condicao: lista contem o aluno inserido na primeira posicao */
void InsereAluno (TLista* lista, TAluno* aluno)
{
    if (lista == NULL && aluno == NULL)
    {
        printf("Lista ou aluno NULL\n");
        return;
    }

    if (lista->primeiro == NULL && lista->ultimo == NULL)
    {
        lista->primeiro = lista->ultimo = aluno;
    }

    else
    {
        aluno->proximo = lista->primeiro;
        lista->primeiro = aluno;
    }
}

/*Retira a primeira ocorrencia de um aluno de matricula mat da lista de alunos
 * inputs: a lista e a matricula do aluno a ser retirado da lista
 * output: o aluno (do tipo TAluno) retirado da lista ou NULL, se o aluno nao se encontrar na lista
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: lista nao contem a primeira ocorrencia do aluno de matricula mat */
TAluno* Retira (TLista* lista, int mat)
{
    TAluno* aux = lista->primeiro;
    TAluno* ant = aux;

    while (aux && aux->matricula != mat)
    {
        ant = aux;
        aux = aux->proximo;
    }

    if (!aux)
    {
        printf("Aluno não encontrado no retira\n");
        return NULL;
    }

    if (aux == lista->primeiro && aux == lista->ultimo)
    {
        lista->primeiro = lista->ultimo = NULL;
    }
    else if (aux == lista->primeiro)
    {
        lista->primeiro = aux->proximo;
    }
    else if (aux == lista->ultimo)
    {
        lista->ultimo = ant;
        ant->proximo = NULL;
    }
    else
    {
        ant->proximo = aux->proximo;
    }


    return aux;

}

/* Retira as repeticoes na lista. Ou seja, deixa apenas uma referencia para cada aluno na lista
 * inputs: a lista
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: lista nao contem repeticoes de alunos - APENAS UMA OCORRENCIA DE CADA ALUNO */
void RetiraRepetidos (TLista* lista)
{
    TAluno* aluno = lista->primeiro;
    TAluno* aux;
    while (aluno)
    {
        aux = aluno->proximo;
        while (aux)
        {
            if (aux->matricula == aluno->matricula)
            {
                Retira(lista, aluno->matricula);
            }

            aux = aux->proximo;
        }



        aluno = aluno->proximo;
    }
}


/* Intercala os alunos das turmas 1 e 2 em uma nova lista. Por exemplo, se a turma 1 tiver (a1->a2->a3) e a turma 2 tiver (b1->b2->b3->b4->b5), a funcao deve retornar uma nova lista formada pelos elementos (a1->b1->a2->b2->a3->b3->b4->b5). Se uma das  listas tiver mais elementos que a outra, os elementos excedentes s�o transferidos na mesma ordem para a nova lista. As listas originais devem ficar vazias (com sentila prim e ult apontando para NULL).
 * inputs: duas listas n�o nulas (por�m, podem estar vazias)
 * output: uma nova lista com os elementos intercalados
 * pre-condicao: listas turma1 e turma2 nao sao NULL (mas podem estar vazias)
 * pos-condicao: lista retornada contem os elementos intercalados. As listas de entrada vazias (apenas com sentinela). */
TLista* Merge (TLista* turma1, TLista* turma2)
{
    TLista* nova = CriaLista();
    TAluno* aux1 = turma1->primeiro;
    TAluno* aux2 = turma2->primeiro;
    int vez = 1; // 1 para turma1, 0 para turma2

    while (aux1 || aux2)
    {
        if (vez)
        {
            if (aux1)
            {
                InsereAluno(nova, aux1);
                aux1 = aux1->proximo;
            }
            vez = 0;
        }
        else
        {
            if (aux2)
            {
                InsereAluno(nova, aux2);
                aux2 = aux2->proximo;
            }
            vez = 1;
        }
    }

    return nova;
}

/* Libera a memoria alocada para o aluno
 * inputs: o aluno do tipo TAluno*
 * output: nenhum
 * pre-condicao: aluno n�o NULL
 * pos-condicao: toda a memoria alocada para o aluno foi liberada (inclusive para o nome) */
void LiberaAluno (TAluno* aluno)
{
    if (aluno)
    {
        free(aluno->nome);

        free(aluno);
    }
    aluno = NULL;
}

/*Imprime os dados de todos os alunos da lista
 * inputs: a lista de alunos
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas, pode estar vazia)
 * pos-condicao: dados dos alunos impressos na saida padrao */
void Imprime (TLista* lista)
{
    if (!lista) return;


    TAluno* aux = lista->primeiro;
    while (aux)
    {
        printf("Aluno: %s Matricula: %d\n", aux->nome, aux->matricula);
        aux = aux->proximo;
    }

}

/*Libera toda a memoria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
 * inputs: a lista encadeada de alunos
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: toda memoria alocada eh liberada (use valgrind!) */
void LiberaLista (TLista* lista)
{
    if (lista)
    {
        TAluno* aux = lista->primeiro;

        while (aux)
        {
            TAluno* prox = aux->proximo;
            LiberaAluno(aux);
            aux = prox;
        }

        free(lista);
    }
    lista = NULL;
}


