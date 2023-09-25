#include <stdio.h>
#include <stdlib.h>
#include "listacircular.h"

typedef struct no
{
    Aluno valor;
    struct no *prox;
} No;

typedef struct lista
{
    No* fim;
} Lista;

Lista *Criar()
{
    Lista *l;
    l = (Lista *) malloc(sizeof(Lista));
    if(l != NULL) l->fim = NULL;
    return l;
}

void Limpar(Lista *l)
{
    while((ListaVazia(l) != 0) && (ListaVazia(l) != 2))
    {
        RemoverInicio(l);
    }
}

void Mostrar(Lista *l)
{
    if(l != NULL)
    {
        printf("[ ");
        No *n = l->fim;
        if(n != NULL)
        {
            do
            {
                n = n->prox;
                printf("{%d, %s, %.2f} ", n->valor.mat, n->valor.nome, n->valor.n1);
            }
            while(n->prox != l->fim->prox);
        }
        printf("]\n");
    }
}

int Tamanho(Lista *l)
{
    if(l == NULL) return (-1);
    if(ListaVazia(l) == 0) return 0;
    int cont = 1;
    No* n = l->fim;

    while(n->prox != l->fim)
    {
        cont++;
        n = n->prox;
    }
    return cont;
}

int ListaVazia(Lista *l)
{
    if(l == NULL) return 2;
    if(l->fim == NULL) return 0;
    return 1;
}

int InserirInicio(Lista *l, Aluno it)
{
    if(l == NULL) return 2;
    No *n = (No*) malloc(sizeof(No));
    n ->valor = it;
    if(ListaVazia(l) == 0)
    {
        l->fim = n;
        n->prox = n;
    }
    else
    {
        n->prox = l->fim->prox;
        l->fim->prox = n;
    }
    return 0;
}

int InserirFim(Lista *l, Aluno it)
{
    if(l == NULL) return 2;
    if(ListaVazia(l) == 0)
        return InserirInicio(l, it);
    else
    {
        No *n = (No *) malloc(sizeof(No));
        n->valor = it;
        n->prox = l->fim->prox;
        l->fim->prox = n;
        l->fim = n;
    }
    return 0;
}

int InserirPosicao(Lista *l, int pos, Aluno it)
{
    if(l == NULL) return 2;
    if(pos == 0)
    {
        return InserirInicio(l, it);
    }
    if(pos >= (Tamanho(l) -1))
    {
        return InserirFim(l, it);
    }

    No* n = l->fim;
    No* in = (No*) malloc(sizeof(No));
    in->valor = it;

    while(pos > 0)
    {
        pos--;
        n = n->prox;
    }

    in->prox = n->prox;
    n->prox = in;
    return 0;
}

int RemoverInicio(Lista *l)
{
    if(l == NULL) return 2;
    if(ListaVazia(l) == 0) return 1;
    No * n = l->fim->prox;
    if(Tamanho(l) == 1)
    {
        l->fim = NULL;
        free(n);
    }
    else
    {
        l->fim->prox = n->prox;
        free(n);
    }
    return 0;
}

int RemoverFim(Lista *l)
{
    if(l == NULL) return 2;
    if(ListaVazia(l) == 0) return 1;
    if(Tamanho(l) == 1)
        return RemoverInicio(l);
    No * n = l->fim;
    while(n->prox != l->fim)
        n = n->prox;
    n->prox = l->fim->prox;
    free(l->fim);
    l->fim = n;
    return 0;
}

int RemoverPosicao(Lista *l, int pos)
{
    if(l == NULL) return 2;
    if(ListaVazia(l) == 0) return 1;
    if((pos == 0) || (Tamanho(l) == 1))
        return RemoverInicio(l);
    if(pos >= (Tamanho(l) -1))
        return RemoverFim(l);
    No* frente = l->fim;
    No* tras = NULL;
    while((pos > (-1)) && (frente->prox != l->fim))
    {
        tras = frente;
        frente = frente->prox;
    }
    tras->prox = frente->prox;
    free(frente);
    return 0;
}

int BuscarItemChave(Lista *l, int it, Aluno *retorno)
{
    if(l == NULL) return 2;
    if(ListaVazia(l) == 0) return 1;
    No* aux = l->fim;
    do
    {
        if(((aux->valor).mat) == it)
        {
            *retorno = aux->valor;
            return 0;
        }
        aux = aux->prox;
    }
    while(aux != l->fim);
    return 3;
}
int BuscarPosicao(Lista *l, int pos, Aluno *retorno)
{
    if(l == NULL) return 0;
    if(ListaVazia(l) == 0) return 1;
    No* aux = l->fim;
    if((aux->prox == l->fim) && (pos == 0))
    {
        *retorno = aux->valor;
        return 0;
    }
    else
    {
        while((aux->prox != l->fim) && (pos > (-1)))
        {
            aux = aux->prox;
        }
        if(pos > (-1))
        {
            *retorno = aux->valor;
            return 0;
        }
    }
    return 3;
}


//============================================================================
int RemoveMeio(Lista *l)
{
    if(l == NULL) return 2;

    int aux = ((Tamanho(l)) / 2);

    return RemoverPosicao(l, aux);
}

//============================================================================
int RemoveUmaOcorrencia(Lista *l, int it)
{
    if(l == NULL) return 2;
    if(ListaVazia(l) == 0) return 1;
    No * frente = l->fim;
    No* tras = NULL;

    if((frente->prox == l->fim) && (frente->valor.mat == it))
        return RemoverInicio(l);

    while((frente->prox != l->fim) && (frente->valor.mat != it))
    {
        tras = frente;
        frente = frente->prox;
    }

    if((frente == l->fim) && ((frente->valor.mat == it)))
        return RemoverFim(l);

    if(frente->valor.mat == it)
    {
        tras->prox = frente->prox;;
        free(frente);
        return 0;
    }
    return 3;
}
int RemoveItemChave(Lista *l, int it)
{
    if(l == NULL) return 2;
    if(ListaVazia(l) == 0) return 1;
    int ver;
    do
    {
        ver = RemoveUmaOcorrencia(l, it);
    }while(ver == 0);
    return 0;
}
