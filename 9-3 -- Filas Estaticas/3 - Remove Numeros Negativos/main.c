#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    Fila *f1, *f2, *ret;
    int it, esc, esc2, verif, brk = 0;

    f1 = Criar();
    f2 = Criar();
    ret = Criar();

    while(1)
    {
        printf("1)Inserir elemento\n2)Remover Elemento\n3)Ver alguma das Filas\n4)Intercalar ambas as filas\n5)Remover as ocorrencias negativas\n6)Sair\n");
        scanf("%i", &esc);

        switch(esc)
        {
        case 1:
            printf("Deseja inserir na fila 1 ou 2?\n");
            scanf("%i", &esc2);

            printf("Escreva o numero para ser inserido: ");
            scanf("%i", &it);

            if(esc2 == 1) verif = Inserir(f1, it);
            else if(esc2 == 2) verif = Inserir(f2, it);

            if(verif == 0) printf("Inserido\n");
            else if(verif == 1) printf("Lista Cheia\n");
            else if (verif == 2) printf("Lista Inexistente\n");
            break;

        case 2:
            printf("Deseja remover da fila 1 ou 2?\n");
            scanf("%i", &esc2);

            if(esc2 == 1) verif = Remover(f1, &it);
            else if(esc2 == 2) verif = Remover(f2, &it);

            if(verif == 0) printf("Removido\n");
            else if(verif == 1) printf("Lista Vazia\n");
            else if (verif == 2) printf("Lista Inexistente\n");
            break;

        case 3:
            printf("Deseja mostrar a fila 1 ou 2?\n");
            scanf("%i", &esc2);
            if(esc2 == 1) Mostrar(f1);
            else if(esc2 == 2) Mostrar(f2);
            break;
        case 4:
            verif = Intercala(f1, f2, ret);

            if(verif == 0) Mostrar(ret);
            else if(verif == 1) printf("Listas Vazias\n");
            else if(verif == 2) printf("Listas nao alocadas\n");
            break;
        case 5:
            printf("Deseja remover da fila 1 ou 2?\n");
            scanf("%i", &esc2);

            if(esc2 == 1) verif = RemoveNegativo(f1);
            else if(esc2 == 2) verif = RemoveNegativo(f2);

            if(verif == 0) printf("Removido\n");
            else if(verif == 1) printf("Lista Vazia\n");
            else if (verif == 2) printf("Lista Inexistente\n");
            break;

        case 6:
            brk++;
            break;

        }
        if(brk) break;
        printf("\n\n\n");
    }
}
