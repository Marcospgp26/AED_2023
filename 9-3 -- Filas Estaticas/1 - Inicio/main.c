#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    Fila* f = Criar();
    int it;

    printf("Mostrando a fila: ");
    Mostrar(f);

    printf("\n\nInserindo 10\n\n");
    Inserir(f, 10);
    printf("\n\n Mostrando novamente:\n\n");
    Mostrar(f);

    printf("\n\nInserindo 20\n\n");
    Inserir(f, 20);
    printf("\n\n Mostrando novamente:\n\n");
    Mostrar(f);

    printf("\n\nInserindo 30\n\n");
    Inserir(f, 30);
    printf("\n\n Mostrando novamente:\n\n");
    Mostrar(f);

    printf("\n\nInserindo 45\n\n");
    Inserir(f, 45);
    printf("\n\n Mostrando novamente:\n\n");
    Mostrar(f);

    printf("\n\nInserindo 21\n\n");
    Inserir(f, 21);
    printf("\n\n Mostrando novamente:\n\n");
    Mostrar(f);

    printf("\n\nRemovendo\n\n");
    Remover(f, &it);
    printf("\nInteiro Removido: %i", it);
    printf("\n\n Mostrando novamente:\n\n");
    Mostrar(f);

     printf("\n\nRemovendo\n\n");
    Remover(f, &it);
    printf("\nInteiro Removido: %i", it);
    printf("\n\n Mostrando novamente:\n\n");
    Mostrar(f);

    printf("\n");
    system("pause");
    return 0;

}
