#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listacircular.h"
void menu()
{
    printf("Escolha\n1)Sair\n2)Limpar a lista\n3)Mostrar a lista\n4)Mostrar o tamanho da lista\n5)Verificar se a lista esta vazia\n");
    printf("6)Inserir no inicio\n7)Inserir no fim\n8)Inserir numa posicao\n9)Remover o inicio\n10)Remover o fim\n11)Remover uma posicao\n");
    printf("12)Buscar um item\n13)Buscar uma posicao\n14)Intersectar as duas listas\n");
}

int main()
{
    Aluno inser;
    int mn, pos, verif, ar, ext, esc;
    Lista *l1 = NULL, *l2 = NULL, *inter = NULL;
    l1 = Criar();
    l2 = Criar();

    do
    {
        printf("\n\n");
        menu();
        scanf("%i", &mn);

        switch(mn)
        {
        case 1:
            ext = 1;
            break;
        case 2:
            printf("\nVoce deseja limpar qual lista 1 ou 2?\n");
            scanf("%i", &esc);
            if(esc == 1)
            {
                Limpar(l1);
                printf("\nLista limpa\n");
            }
            else if(esc == 2)
            {
                Limpar(l2);
                printf("\nLista limpa\n");
            }
            else
            {
                printf("\nLista invalida\n");
            }
            system("pause");
            break;
        case 3:
            printf("\nVoce deseja ver qual lista 1 ou 2?\n");
            scanf("%i", &esc);
            if(esc == 1) Mostrar(l1);
            else if(esc == 2) Mostrar(l2);
            else printf("\nLista invalida\n");
            system("pause");
            break;
        case 4:
            printf("\nVoce deseja saber o tamanho de qual lista 1 ou 2?\n");
            scanf("%i", &esc);
            printf("\nO tamanho da lista eh: ");
            if(esc == 1)
            {
                verif = Tamanho(l1);
                if(verif == (-1))
                {
                    printf("\nErro\n");
                }
                else
                {
                    printf("%i\n", verif);
                }
            }
            else if(esc == 2)
            {
                verif = Tamanho(l2);
                if(verif == (-1))
                {
                    printf("\nErro\n");
                }
                else
                {
                    printf("%i\n", verif);
                }
            }
            else printf("\nLista invalida\n");

            system("pause");
            break;
        case 5:
            printf("\nVoce deseja verificar se qual lista esta vazia 1 ou 2?\n");
            scanf("%i", &esc);
            if(esc == 1)
            {
                verif = ListaVazia(l1);
                if(verif == 0)
                {
                    printf("\nLista vaziaz\n");
                }
                else if(verif == 1)
                {
                    printf("\nLista nao vazia\n");
                }

                else if(verif == 2)
                {
                    printf("\nERRO\n");
                }
            }
            else if(esc == 2)
            {
                verif = ListaVazia(l2);
                if(verif == 0)
                {
                    printf("\nLista vaziaz\n");
                }
                else if(verif == 1)
                {
                    printf("\nLista nao vazia\n");
                }

                else if(verif == 2)
                {
                    printf("\nERRO\n");
                }
            }
            else printf("\nLista Invalida\n");
            system("pause");
            break;
        case 6:
            printf("\nVoce deseja inserir os dados na lista 1 ou 2?\n");
            scanf("%i", &esc);

            printf("Insira o nome do aluno: ");
            fflush(stdin);
            fgets(inser.nome, 50, stdin);
            ar = strlen(inser.nome);
            inser.nome[ar - 1] = '\0';

            printf("Insira a matricula: ");
            scanf("%i", &inser.mat);

            printf("Insira a nota n1: ");
            scanf("%f", &inser.n1);

            if(esc == 1)
            {
                verif = InserirInicio(l1, inser);
                if(verif == 0) printf("\nInserida\n");
                else if(verif == 2) printf("\nErro\n");
            }

            else if(esc == 2)
            {
                verif = InserirInicio(l2, inser);
                if(verif == 0) printf("\nInserida\n");
                else if(verif == 2) printf("\nErro\n");
            }
            else printf("\nLista Invalida\n");

            system("pause");
            break;
        case 7:
            printf("\nVoce deseja inserir os dados na lista 1 ou 2?\n");
            scanf("%i", &esc);

            printf("Insira o nome do aluno: ");
            fflush(stdin);
            fgets(inser.nome, 50, stdin);
            ar = strlen(inser.nome);
            inser.nome[ar] = '\0';

            printf("Insira a matricula: ");
            scanf("%i", &inser.mat);

            printf("Insira a nota n1: ");
            scanf("%f", &inser.n1);

            if(esc == 1)
            {
                verif = InserirFim(l1, inser);
                if(verif == 0) printf("\nInserida\n");
                else if(verif == 2) printf("\nErro\n");
                system("pause");
            }
            else if(esc == 2)
            {
                verif = InserirFim(l2, inser);
                if(verif == 0) printf("\nInserida\n");
                else if(verif == 2) printf("\nErro\n");
                system("pause");
            }
            else printf("\nLista invalida\n");
            break;
        case 8:
            printf("\nVoce deseja inserir os dados na lista 1 ou 2?\n");
            scanf("%i", &esc);

            printf("Insira o nome do aluno: ");
            fflush(stdin);
            fgets(inser.nome, 50, stdin);
            ar = strlen(inser.nome);
            inser.nome[ar] = '\0';

            printf("Insira a matricula: ");
            scanf("%i", &inser.mat);

            printf("Insira a nota n1: ");
            scanf("%f", &inser.n1);

            printf("Insira a posicao: ");
            scanf("%i", &pos);

            if(esc == 1)
            {
                verif = InserirPosicao(l1, pos, inser);
                if(verif == 0) printf("\nInserida\n");
                else if(verif == 2) printf("\nErro\n");
            }
            else if(esc == 2)
            {
                verif = InserirPosicao(l2, pos, inser);
                if(verif == 0) printf("\nInserida\n");
                else if(verif == 2) printf("\nErro\n");
            }
            else printf("\nLista invalida\n");
            system("pause");
            break;
        case 9:
            printf("\nVoce deseja remover os dados da lista 1 ou 2?\n");
            scanf("%i", &esc);

            if(esc == 1)
            {
                verif = RemoverInicio(l1);
                if(verif == 2) printf("\nERRO\n");
                else if(verif == 1) printf("\nLista vazia\n");
                else printf("\nElemento retirado\n");
            }
            else if(esc == 2)
            {
                verif = RemoverInicio(l2);
                if(verif == 2) printf("\nERRO\n");
                else if(verif == 1) printf("\nLista vazia\n");
                else printf("\nElemento retirado\n");
            }
            else printf("\nLista invalida\n");

            system("pause");
            break;
        case 10:
            printf("\nVoce deseja remover os dados da lista 1 ou 2?\n");
            scanf("%i", &esc);

            if(esc == 1)
            {
                verif = RemoverFim(l1);
                if(verif == 2) printf("\nERRO\n");
                else if(verif == 1) printf("\nLista vazia\n");
                else printf("\nElemento retirado\n");
            }
            else if(esc == 2)
            {
                verif = RemoverFim(l2);
                if(verif == 2) printf("\nERRO\n");
                else if(verif == 1) printf("\nLista vazia\n");
                else printf("\nElemento retirado\n");
            }
            else printf("\nLista invalida\n");
            system("pause");
            break;
        case 11:
            printf("\nVoce deseja remover os dados da lista 1 ou 2?\n");
            scanf("%i", &esc);

            printf("Insira uma posicao: ");
            scanf("%i", &pos);

            if(esc == 1)
            {
                verif = RemoverPosicao(l1, pos);
                if(verif == 2) printf("\nERRO\n");
                else if(verif == 1) printf("\nLista vazia\n");
                else printf("\nElemento retirado\n");
            }
            else if(esc == 2)
            {
                verif = RemoverPosicao(l2, pos);
                if(verif == 2) printf("\nERRO\n");
                else if(verif == 1) printf("\nLista vazia\n");
                else printf("\nElemento retirado\n");
            }
            else printf("\nLista invalida\n");

            system("pause");
            break;
        case 12:
            printf("\nVoce deseja buscar os dados na lista 1 ou 2?\n");
            scanf("%i", &esc);

            printf("Insira uma matricula: ");
            scanf("%i", &pos);

            if(esc == 1)
            {
                verif = BuscarItemChave(l1, pos, &inser);
                if(verif == 0)
                {
                    printf("\nElemento encontrado: {%d, %s, %f}\n",inser.mat, inser.nome, inser.n1);
                }
                else if(verif == 1) printf("\nLista Vazia\n");
                else if(verif == 2) printf("\nERRO\n");
                else printf("\nElemento nao encontrado\n");
            }
            else if(esc == 2)
            {
                verif = BuscarItemChave(l2, pos, &inser);
                if(verif == 0)
                {
                    printf("\nElemento encontrado: {%d, %s, %f}\n",inser.mat, inser.nome, inser.n1);
                }
                else if(verif == 1) printf("\nLista Vazia\n");
                else if(verif == 2) printf("\nERRO\n");
                else printf("\nElemento nao encontrado\n");
            }
            else printf("\nLista Invalida\n");
            system("pause");
            break;
        case 13:
            printf("\nVoce deseja buscar os dados na lista 1 ou 2?\n");
            scanf("%i", &esc);

            printf("Insira uma posicao: ");
            scanf("%i", &pos);

            if(esc == 1)
            {
                verif = BuscarPosicao(l1, pos, &inser);
                if(verif == 0)
                {
                    printf("\nElemento encontrado: {%d, %s, %f}\n",inser.mat, inser.nome, inser.n1);
                }
                else if(verif == 1) printf("\nLista Vazia\n");
                else if(verif == 2) printf("\nERRO\n");
                else printf("\nElemento nao encontrado\n");
            }
            else if(esc == 2)
            {
                verif = BuscarPosicao(l2, pos, &inser);
                if(verif == 0)
                {
                    printf("\nElemento encontrado: {%d, %s, %f}\n",inser.mat, inser.nome, inser.n1);
                }
                else if(verif == 1) printf("\nLista Vazia\n");
                else if(verif == 2) printf("\nERRO\n");
                else printf("\nElemento nao encontrado\n");
            }
            else printf("\nLista Invalida\n");
            system("pause");
            break;
        case 14:
            inter = Intersect(l1, l2);
            if(inter == NULL) printf("\nImpossivel realizar a interseccao\n");
            else
            {
                printf("\nInterseccao feita, lista nova eh:\n");
                Mostrar(inter);
            }
            break;
        }
        if(ext) break;
    }
    while(1);
    system("pause");
    return 0;
}
