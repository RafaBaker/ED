#ifndef ABB_H
#define ABB_H

typedef struct Aluno Aluno;

Aluno* criaAluno(char* nome);

void incFalta(Aluno* aluno);

void incPresenca(Aluno* aluno);

int comparaAluno(Aluno* aluno, char* nome);


typedef struct Abb Abb;

Abb* criaAbb();

Abb* abbInsere(Abb* arv, Aluno* item);

void abbImprime(Abb* arv);

void abbLibera(Abb* arv);

Aluno* abbBusca(Abb* arv, char* nome);

#endif