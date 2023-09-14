#include <stdio.h>
#include <stdlib.h>
#include "listaauxiliar.h"

typedef struct lista
{
    Letra *valores;
    int tam;
}Lista;

Lista *Criar()
{
    Lista *l;
    l = (Lista*) malloc(sizeof(Lista));
    l -> tam = 0;

    return l;
}

int Muda_quant(Lista *l, char mod)
{
    int pos;
    if(l == NULL) return 2;
    pos = busca_posicao(l, mod);
    if(pos == (-1))
    {
        if(l->tam == 0)
        {
            l->valores = (Letra*) calloc((l->tam +1), sizeof(Letra));
            l->valores[l->tam].c = mod;
            l->valores[l->tam].quant = 1;
            l->tam++;
        }
        else
        {
            l ->valores = (Letra*) realloc((l ->valores), (((l->tam) +1) * sizeof(Letra)));
            l->valores[l->tam].c = mod;
            l->valores[l->tam].quant = 1;
            l->tam++;
        }
    }
    else
    {
        l->valores[pos].quant++;
    }
    return 0;
}

int busca_posicao(Lista *l, char bsc)
{
    int i;
    if(l == NULL) return 2;
    for(i = 0; i < (l ->tam); i++)
    {
        if((l->valores[i].c) == bsc)
        {
            return i;
        }
    }
    return (-1);
}

void Imprime_Lista(Lista *l)
{
    int i, j;
    for(i = 0; i < (l ->tam); i++)
    {
        printf("[%c] - ", l->valores[i].c);
        for(j = 0; j <(l->valores[i].quant); j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
