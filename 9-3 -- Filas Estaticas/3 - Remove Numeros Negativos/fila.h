#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#define MAX 100

typedef struct fila Fila;

Fila *Criar();

void Limpar(Fila *f);
void Mostrar(Fila *f);

int Inserir(Fila *f, int it);
int Remover(Fila *f, int *it);
int Remover2(Fila *f);


int Consultar(Fila *f, int *it);
int Tamanho(Fila *f);
int FilaVazia(Fila *f);
int FilaCheia(Fila *f);

//================================================================================================================================================================================================================================
int Intercala(Fila *f1, Fila *f2, Fila *ret);
int RemoveNegativo(Fila *f);

#endif // FILA_H_INCLUDED
