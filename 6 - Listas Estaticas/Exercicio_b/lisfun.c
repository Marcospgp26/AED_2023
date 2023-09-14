#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct lista
{
    int total;
    Aluno valores[MAX];
} Lista;

Lista *Criar ()
{
    Lista *l;
    l = (Lista *) malloc(sizeof(Lista));
    if(l != NULL) l -> total = 0;
    return l;
}

void Limpar_Lista (Lista *l)
{
    if(l != NULL) l -> total = 0;
}

int Inserir_Inicio (Lista *l, Aluno a)
{
    int i;
    if(l == NULL) return 2;
    if(Lista_Cheia(l) == 0) return 1;
    for(i = l ->total; i > 0; i--)
    {
        l ->valores[i] = l ->valores[i - 1];
    }
    l ->valores[0] = a;
    l ->total++;
    return 0;
}

int Inserir_Final (Lista *l, Aluno a)
{
    if(l == NULL) return 2;
    if(Lista_Cheia(l) == 0) return 1;
    l -> valores[l -> total] = a;
    l -> total++;
    return 0;
}

int Inserir_Posicao (Lista *l, Aluno a, int posicao)
{
    int i;
    if(l == NULL) return 2;
    if(Lista_Cheia(l) == 0) return 1;
    if((posicao < 0) || (posicao > ((l ->total)-1))) return 3;
    for(i = l -> total; i > posicao; i--)
    {
        l -> valores[i] = l -> valores[i - 1];
    }
    l ->valores[posicao] = a;
    l -> total++;
    return 0;
}

int Remover_Inicio (Lista *l)
{
    int i;
    if(l == NULL) return 2;
    if(Lista_Vazia(l) == 0) return 1;
    for(i = 0; i < ((l -> total) - 1); i++)
    {
        l -> valores[i] = l -> valores[i + 1];
    }
    l -> total--;
    return 0;
}

int Remover_Fim (Lista *l)
{
    if(l == NULL) return 2;
    if(Lista_Vazia(l) == 0) return 1;
    l -> total--;
    return 0;
}

int Remover_Posicao (Lista *l, int posicao)
{
    int i;
    if(l == NULL) return 2;
    if(Lista_Vazia(l) == 0) return 1;
    if((posicao < 0) || (posicao > ((l -> total) - 1))) return 3;
    for(i = posicao; i < ((l -> total) - 1); i++)
        l -> valores[i] = l -> valores [i + 1];
    l ->total--;
    return 0;
}

int Remover_Item (Lista *l, Aluno a)
{
    int i, j;
    if(l == NULL) return 2;
    if(Lista_Vazia(l) == 0) return 1;
    for(i = 0; i < ((l ->total) - 1); i++)
    {
        if((l -> valores[i].mat == a.mat))
        {
            for(j = i; j < ((l -> total) - 1); i++)
            {
                l -> valores[j] = l-> valores[j + 1];
            }
            break;
        }
    }
    l ->total--;
    return 0;
}

int Buscar_Item (Lista *l, int chave, Aluno *retorno)
{
    int i;
    if(l == NULL) return 2;
    if(Lista_Vazia(l) == 0) return 1;
    for(i = 0; i < ((l -> total) - 1); i++)
    {
        if(l -> valores[i].mat == chave)
        {
            *retorno = l -> valores[i];
            return 0;
        }
    }
    return -1;
}

int Buscar_Posicao (Lista *l, int posicao, Aluno *a)
{
    if(l == NULL) return 2;
    if(Lista_Vazia(l) == 0) return 1;
    if((posicao < 0) || (posicao > ((l ->total) - 1)))
    {
        return 3;
    }
    *a = l ->valores[posicao];
    return 0;
}

int Lista_Vazia (Lista *l)
{
    if(l == NULL) return 2;
    if(l -> total == 0) return 0;
    return 1;
}

int Lista_Cheia (Lista *l)
{
    if(l == NULL) return 2;
    if(l -> total == MAX) return 0;
    return 1;
}

int Tamanho (Lista *l)
{
    if( l == NULL) return -1;
    return l -> total;
}

void Mostrar (Lista *l)
{
    int i;
    if(l != NULL)
    {
        printf("[ ");
        for(i = 0; i < l -> total; i++)
        {
            printf("{%d, ", l ->valores[i].mat);
            printf("%s, ", l ->valores[i].nome);
            printf("%0.2f} ", l ->valores[i].n1);
        }
        printf("]\n");
    }
}

int Contem_item(Lista *l, int *a)
{
    int i;
    if(l == NULL) return 2;
    if(Lista_Vazia(l) == 0) return 3;
    for(i = 0; i < ((l ->total) - 1); i++)
    {
        if((l ->valores[i].mat) == (*a))
        {
            return 0;
        }
    }
    return 1;
}

Lista* Reversa(Lista *l)
{
    Lista *rev = Criar();
    int i, contador = 0;;
    rev ->total = l->total;
    if(l != NULL)
    {
        for(i = (rev -> total - 1); i >= 0; i--)
        {
            rev->valores[i] = l->valores[contador];
            contador++;
        }
        return rev;
    }
    return NULL;
}

int Conta_Item(Lista *l, int *item)
{
    int conta = 0, i;
    if(l == NULL) return -2;
    if(Lista_Vazia(l) == 0) return -1;
    for(i = 0; i < ((l -> total) -1); i++)
    {
        if((l ->valores[i].mat) == (*item))
        {
            conta++;
        }
    }
    return conta;
}
