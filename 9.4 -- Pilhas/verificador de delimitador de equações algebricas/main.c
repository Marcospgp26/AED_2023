#include <stdio.h>
#include <string.h>
#include "pilha.h"


int Verifica(Pilha *p);

int main()
{
    Pilha *p = Criar();
    int tam, verif;
    char str[61];

    printf("Insira a sequencia de delimitadores: ");
    fgets(str, 60, stdin);

    str[strlen(str) - 1] = str[strlen(str)];
    tam = strlen(str);

    for(int i = 0; i < tam; i++)
    {
        Push(p, ((int) str[tam - i - 1]));
    }

    verif = Verifica(p);
    if(verif == 0) printf("Existe!\n");
    else printf("Nao existe!\n");
    system("pause");
    return 0;
}

int Verifica(Pilha *p)
{
    Pilha *aux = Criar();
    int retirado, ret2;

    if((Tamanho(p) % 2) != 0) return 1;

    while(PilhaVazia(p) != 0)
    {
        Pop(p, &retirado);
        if((retirado == 41) || (retirado == 125)) break;

        while(PilhaVazia(p) != 0)
        {
            Pop(p, &ret2);
            if(((retirado == 40) && (ret2 == 41)) || ((retirado == 123) && (ret2 == 125))) break;
            Push(aux, ret2);
        }
        while(PilhaVazia(aux) != 0)
        {
            Pop(aux, &ret2);
            Push(p, ret2);
        }
    }

    if(PilhaVazia(p) == 0) return 0;
    return 1;
}
