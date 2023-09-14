#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct aluno
{
    int mat;
    char nome[30];
    float n1;
}Aluno;


typedef struct lista Lista;

Lista *Criar();

void Limpar_Lista(Lista *l);

int Inserir_Inicio(Lista *l, Aluno a);

int Inserir_Final(Lista *l, Aluno a);

int Inserir_Posicao(Lista *l, Aluno a, int posicao);

int Remover_Inicio(Lista *l);

int Remover_Fim(Lista *l);

int Remover_Posicao(Lista *l, int posicao);

int Remover_Item(Lista *l, Aluno a);

int Buscar_Item(Lista *l, int chave, Aluno *retorno);

int Buscar_Posicao(Lista *l, int posicao, Aluno *a);

int Lista_Vazia(Lista *l);

int Lista_Cheia(Lista *l);

int Tamanho(Lista *l);

void Mostrar(Lista *l);

int Contem_item(Lista *l, int *a);

Lista* Reversa(Lista *l);

int Conta_Item(Lista *l, int *item);

#endif // LISTA_H_INCLUDED
