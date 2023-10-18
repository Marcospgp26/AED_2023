#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct fila
{
    int valores[MAX];
    int qnt;
    int inicio;
    int fim;
} Fila;

Fila * Criar()
{
    Fila *f = (Fila *) malloc(sizeof(Fila));
    if(f != NULL)
    {
        f->qnt = 0;
        f->inicio = 0;
        f->fim = 0;
    }
    return f;
}

void Limpar(Fila *f)
{
    if(f != NULL)
    {
        free(f);
        f= NULL;
    }
}
void Mostrar(Fila *f)
{
    if(f != NULL)
    {
        printf("[ ");
        int i = f->qnt;
        int a = f->inicio;
        while(i > 0)
        {
            printf("%i,", f->valores[a]);
            a = (a + 1) % MAX;
            i--;
        }
        printf(" ]");

    }
}

int Inserir(Fila *f, int it)
{
    if(f == NULL) return 2;
    if(FilaCheia(f) == 0) return 1;
    f->valores[f->fim] = it;
    f->fim = (f->fim + 1) % MAX;
    f->qnt++;
    return 0;
}
int Remover(Fila *f, int *it)
{
    if(f == NULL) return 2;
    if(FilaVazia(f) == 0) return 1;
    *it = f->valores[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->qnt--;
    return 0;
}
int Consultar(Fila *f, int *it)
{
    if(f == NULL) return 2;
    if(FilaVazia(f) == 0) return 1;

    *it = f->valores[f->inicio];
    return 0;
}
int Tamanho(Fila *f)
{
    if(f == NULL) return (-1);
    return f->qnt;
}
int FilaVazia(Fila *f)
{
    if(f == NULL) return 2;
    if(f->qnt == 0) return 0;
    return 1;
}
int FilaCheia(Fila *f)
{
    if(f == NULL) return 2;
    if(f->qnt == MAX) return 0;
    return 1;
}

int Intercala(Fila *f1, Fila *f2, Fila *ret)
{
    if((f1 == NULL) || (f2 == NULL) || (ret == NULL)) return 2;
    if((FilaVazia(f1) == 0) || (FilaVazia(f2) == 0)) return 1;

    int it, a = f1->qnt, b = f2->qnt;

    while((a > 0) && (b > 0))
    {
        Remover(f1, (&it));
        Inserir(f1, it);
        Inserir(ret, it);

        Remover(f2, (&it));
        Inserir(f2, it);
        Inserir(ret, it);
        a--;
        b--;
    }


    while(a > 0)
    {
        Remover(f1, &it);
        Inserir(f1, it);
        Inserir(ret, it);
        a--;
    }
    while(b > 0)
    {
        Remover(f2, &it);
        Inserir(f2, it);
        Inserir(ret, it);
        b--;
    }
    return 0;
}
