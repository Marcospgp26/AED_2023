#ifndef LISTAAUXILIAR_H_INCLUDED
#define LISTAAUXILIAR_H_INCLUDED

typedef struct letra
{
    char c;
    int quant;
}Letra;

typedef struct lista Lista;

Lista *Criar();

int Inserir(Lista *l);

int Muda_quant(Lista *l, char mod);

int busca_posicao(Lista *l, char bsc);

void Imprime_Lista(Lista *l);

#endif // LISTAAUXILIAR_H_INCLUDED
