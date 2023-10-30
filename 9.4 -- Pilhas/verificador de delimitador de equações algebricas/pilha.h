#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilha Pilha;

Pilha *Criar();
void Limpar (Pilha *p);

int Push(Pilha *p, int it);
int Pop(Pilha *p, int *it);

int Consultar(Pilha *p, int *it);
int Tamanho(Pilha *p);
int PilhaVazia(Pilha *p);

void Mostrar(Pilha *p);

#endif // PILHA_H_INCLUDED
