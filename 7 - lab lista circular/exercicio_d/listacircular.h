#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED

typedef struct aluno
{
    char nome[50];
    int mat;
    float n1;
}Aluno;

typedef struct lista Lista;

Lista *Criar();
void Limpar(Lista *l);
void Mostrar(Lista *l);
int Tamanho(Lista *l);
int ListaVazia(Lista *l);

int InserirInicio(Lista *l, Aluno it);
int InserirFim(Lista *l, Aluno it);
int InserirPosicao(Lista *l, int pos, Aluno it);

int RemoverInicio(Lista *l);
int RemoverFim(Lista *l);
int RemoverPosicao(Lista *l, int pos);

int BuscarItemChave(Lista *l, int it, Aluno *retorno);
int BuscarPosicao(Lista *l, int pos, Aluno *retorno);


//==================================================================================================
Lista *Intersect(Lista *l1, Lista *l2);

#endif // LISTACIRCULAR_H_INCLUDED
