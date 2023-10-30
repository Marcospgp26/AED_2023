#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no
{
   int valor;
   struct no *prox;
}No;

typedef struct pilha{
    No *topo;
}Pilha;


Pilha *Criar()
{
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    if(p != NULL) p->topo = NULL;
    return p;
}

void Limpar (Pilha *p)
{
    if(p != NULL){
        int it;
        while(PilhaVazia(p) != 0) Pop(p, &it);
    }
}

int Push(Pilha *p, int it)
{
    if(p == NULL) return 2;
    No* insere = (No*) malloc(sizeof(No));
    insere->valor = it;
    insere->prox = p->topo;
    p->topo = insere;
    return 0;

}
int Pop(Pilha *p, int *it)
{
    if(p == NULL) return 2;
    if(PilhaVazia(p) == 0) return 1;
    No* no = p->topo;
    p->topo = no->prox;
    *it = no->valor;
    free(no);
    return 0;
}

int Consultar(Pilha *p, int *it)
{
    if(p == NULL) return 2;
    if(PilhaVazia(p) == 0) return 1;

    *it = p->topo->valor;
    return 0;
}

int Tamanho(Pilha *p)
{
    if(p == NULL) return -2;
    No* no = p->topo;
    int cnt = 0;
    while(no != NULL)
    {
        cnt++;
        no = no->prox;
    }
    return cnt;
}
int PilhaVazia(Pilha *p)
{
    if(p == NULL) return 2;
    if(p->topo == NULL) return 0;
    return 1;
}

void Mostrar(Pilha *p)
{
    if(p != NULL)
    {
        No* no = p->topo;
        printf("[\n");
        while(no != NULL)
        {
            printf("%i \n", no->valor);
            no = no->prox;
        }
        printf("]");
    }
}
