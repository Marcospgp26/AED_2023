#include <stdio.h>
#include "pilha.h"

int main()
{
    Pilha *p = Criar();
    int it;

    Push(p, 11);
    Push(p, 34);
    Pop(p, &it);
    Pop(p, &it);
    Push(p, 23);
    Push(p, 45);
    Pop(p, &it);
    Push(p, 121);
    Push(p, 22);
    Pop(p, &it);
    Pop(p, &it);

    printf("Tamanho da Lista: ");
    it = Tamanho(p);
    printf("%i", it);
    printf("\nLista:\n");
    Mostrar(p);

    printf("\n");
    system("pause");
    return 0;
}
