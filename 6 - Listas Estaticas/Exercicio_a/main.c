#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void Imprime_menu()
{
    system("cls");
    printf("(1) - Criar a lista\n(2) - Limpar a Lista\n(3) - Inserir dado no inicio da Lista\n(4) - Inserir dados no final da Lista");
    printf("\n(5) - Inserir em uma posicao\n(6) - Remover dado no inicio\n(7) - Remover dado no Fim\n(8) - Remover uma posicao\n(9) - Remover um item");
    printf("\n(10) - Buscar um Item\n(11) - Buscar uma posicao\n(12) - Verificar se a lista esta vazia\n(13) - Verificar se a lista esta cheia");
    printf("\n(14) - Ver o tamanho da lista\n(15) - Mostrar a Lista\n(16) - Sair\n");
}

int main()
{
    int esc, verif, pos, chave, brk = 0;
    Aluno a;
    Lista *l;
    do
    {
        Imprime_menu();
        scanf("%d", &esc);
        switch(esc)
        {
        case 1:
            l = Criar();
            break;

        case 2:
            Limpar_Lista(l);
            break;

        case 3:
            printf("Insira a matricula, nome e nota da n1 do aluno:\n");
            scanf("%d", &a.mat);
            fflush(stdin);
            fgets(a.nome, 29, stdin);
            scanf("%f", &a.n1);
            verif = Inserir_Inicio(l, a);
            switch(verif)
            {
            case 1:
                printf("A lista esta cheia\n");
                break;
            case 2:
                printf("Nao exsite lista\n");
                break;
            }
            system("pause");
            break;

        case 4:
            printf("Insira a matricula, nome e nota da n1 do aluno:\n");
            scanf("%d", &a.mat);
            fflush(stdin);
            fgets(a.nome, 29, stdin);
            scanf("%f", &a.n1);
            verif = Inserir_Final(l, a);
            switch(verif)
            {
            case 1:
                printf("A lista esta cheia\n");
                break;
            case 2:
                printf("Nao exsite lista\n");
                break;
            }
            system("pause");
            break;

        case 5:
            printf("Insira a matricula, nome e nota da n1 do aluno:\n");
            scanf("%d", &a.mat);
            fflush(stdin);
            fgets(a.nome, 29, stdin);
            scanf("%f", &a.n1);
            printf("Insira a posicao:\n");
            scanf("%i", &pos);
            verif = Inserir_Posicao(l, a, pos);
            switch(verif)
            {
            case 1:
                printf("A lista esta cheia\n");
                break;
            case 2:
                printf("Nao exsite lista\n");
                break;
            case 3:
                printf("Posicao invalida\n");
                break;
            }
            system("pause");
            break;
        case 6:
            verif = Remover_Inicio(l);
            switch(verif)
            {
            case 1:
                printf("A lista esta vazia\n");
                break;
            case 2:
                printf("Nao exsite lista\n");
                break;
            }
            system("pause");
            break;
        case 7:
            verif = Remover_Fim(l);
            switch(verif)
            {
            case 1:
                printf("A lista esta vazia\n");
                break;
            case 2:
                printf("Nao exsite lista\n");
                break;
            }
            system("pause");
            break;
        case 8:
            printf("Insira a posicao: ");
            scanf("%d", &pos);
            verif = Remover_Posicao(l, pos);
            switch(verif)
            {
            case 1:
                printf("A lista esta vazia\n");
                break;
            case 2:
                printf("Nao exsite lista\n");
                break;
            case 3:
                printf("Posicao invalida\n");
                break;
            }
            system("pause");
            break;
        case 9:
            printf("Insira a matricula, nome e nota da n1 do aluno:\n");
            scanf("%d", &a.mat);
            fflush(stdin);
            fgets(a.nome, 29, stdin);
            scanf("%f", &a.n1);

            verif = Remover_Item(l, a);
            switch(verif)
            {
            case 1:
                printf("A lista esta vazia\n");
                break;
            case 2:
                printf("Nao exsite lista\n");
                break;
            }
            system("pause");
            break;
        case 10:
            printf("Insira a matricula do aluno: ");
            scanf("%d", &chave);

            verif = Buscar_Item(l, chave, &a);
            switch(verif)
            {
            case 1:
                printf("A lista esta vazia\n");
                break;
            case 2:
                printf("Nao exsite lista\n");
                break;
            }
            printf("Item: ");
            printf("{%d %s %0.2f}\n", a.mat, a.nome, a.n1);

            system("pause");
            break;
        case 11:
            printf("Insira a posicao:\n");
            scanf("%d", &pos);
            verif = Buscar_Posicao(l, pos, &a);
            switch(verif)
            {
            case 1:
                printf("A lista esta vazia\n");
                break;
            case 2:
                printf("Nao exsite lista\n");
                break;
            case 3:
                printf("Posicao invalida\n");
                break;
            }
            printf("Item: ");
            printf("{%d %s %0.2f}\n", a.mat, a.nome, a.n1);
            system("pause");
            break;
        case 12:
            verif = Lista_Vazia(l);
            switch(verif)
            {
            case 0:
                printf("A lista esta vazia\n");
                break;
            case 1:
                printf("A lista nao esta vazia\n");
                break;
            case 2:
                printf("Nao exsite lista\n");
            }
            system("pause");
            break;
        case 13:
            verif = Lista_Cheia(l);
            switch(verif)
            {
            case 0:
                printf("A lista esta cheia\n");
                break;
            case 1:
                printf("A lista nao esta cheia\n");
                break;
            case 2:
                printf("Nao existe lista\n");
            }
            system("pause");
            break;
        case 14:
            verif = Tamanho(l);
            if(verif == (-1))
            {
                printf("Nao existe lista\n");
            }
            else
            {
                printf("O tamanho da lista eh: %d", verif);
            }
            system("pause");
            break;
        case 15:
            Mostrar(l);
            system("pause");
            break;
        case 16:
            brk = 1;
            break;
        }
        if(brk)
        {
            break;
        }
    }while(1);
    return 0;
}
