#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listacircular.h"
void menu()
{
    printf("Escolha\n1)Sair\n2)Limpar a lista\n3)Mostrar a lista\n4)Mostrar o tamanho da lista\n5)Verificar se a lista esta vazia\n");
    printf("6)Inserir no inicio\n7)Inserir no fim\n8)Inserir numa posicao\n9)Remover o inicio\n10)Remover o fim\n11)Remover uma posicao\n");
    printf("12)Buscar um item\n13)Buscar uma posicao\n14)Inserir um item sem repeticao\n");
}

int main()
{
    Aluno inser;
    int mn, pos, verif, ar, ext;
    Lista *l = NULL;
    l = Criar();

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
            Limpar(l);
            printf("\nLista limpa\n");
            system("pause");
            break;
        case 3:
            Mostrar(l);
            system("pause");
            break;
        case 4:
            printf("\nO tamanho da lista eh: ");
            verif = Tamanho(l);
            if(verif == (-1))
            {
                printf("\nErro\n");
            }
            else
            {
                printf("%i\n", verif);
            }
            system("pause");
            break;
        case 5:
            verif = ListaVazia(l);
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
            system("pause");
            break;
        case 6:
            printf("Insira o nome do aluno: ");
            fflush(stdin);
            fgets(inser.nome, 50, stdin);
            ar = strlen(inser.nome);
            inser.nome[ar - 1] = '\0';

            printf("Insira a matricula: ");
            scanf("%i", &inser.mat);

            printf("Insira a nota n1: ");
            scanf("%f", &inser.n1);

            verif = InserirInicio(l, inser);
            if(verif == 0) printf("\nInserida\n");
            else if(verif == 2) printf("\nErro\n");
            system("pause");
            break;
        case 7:
            printf("Insira o nome do aluno: ");
            fflush(stdin);
            fgets(inser.nome, 50, stdin);
            ar = strlen(inser.nome);
            inser.nome[ar] = '\0';

            printf("Insira a matricula: ");
            scanf("%i", &inser.mat);

            printf("Insira a nota n1: ");
            scanf("%f", &inser.n1);

            verif = InserirFim(l, inser);
            if(verif == 0) printf("\nInserida\n");
            else if(verif == 2) printf("\nErro\n");
            system("pause");
            break;
        case 8:
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

            verif = InserirPosicao(l, pos, inser);
            if(verif == 0) printf("\nInserida\n");
            else if(verif == 2) printf("\nErro\n");
            system("pause");
            break;
        case 9:
            verif = RemoverInicio(l);
            if(verif == 2) printf("\nERRO\n");
            else if(verif == 1) printf("\nLista vazia\n");
            else printf("\nElemento retirado\n");
            system("pause");
            break;
        case 10:
            verif = RemoverFim(l);
            if(verif == 2) printf("\nERRO\n");
            else if(verif == 1) printf("\nLista vazia\n");
            else printf("\nElemento retirado\n");
            system("pause");
            break;
        case 11:
            printf("Insira uma posicao: ");
            scanf("%i", &pos);

            verif = RemoverPosicao(l, pos);
            if(verif == 2) printf("\nERRO\n");
            else if(verif == 1) printf("\nLista vazia\n");
            else printf("\nElemento retirado\n");
            system("pause");
            break;
        case 12:
            printf("Insira uma matricula: ");
            scanf("%i", &pos);

            verif = BuscarItemChave(l, pos, &inser);
            if(verif == 0)
            {
                printf("\nElemento encontrado: {%d, %s, %f}\n",inser.mat, inser.nome, inser.n1);
            }
            else if(verif == 1) printf("\nLista Vazia\n");
            else if(verif == 2) printf("\nERRO\n");
            else printf("\nElemento nao encontrado\n");
            system("pause");
            break;
        case 13:
            printf("Insira uma posicao: ");
            scanf("%i", &pos);

            verif = BuscarPosicao(l, pos, &inser);
            if(verif == 0)
            {
                printf("\nElemento encontrado: {%d, %s, %f}\n",inser.mat, inser.nome, inser.n1);
            }
            else if(verif == 1) printf("\nLista Vazia\n");
            else if(verif == 2) printf("\nERRO\n");
            else printf("\nElemento nao encontrado\n");
            system("pause");
            break;
        case 14:
            printf("Insira o nome do aluno: ");
            fflush(stdin);
            fgets(inser.nome, 50, stdin);
            ar = strlen(inser.nome);
            inser.nome[ar - 1] = '\0';

            printf("Insira a matricula: ");
            scanf("%i", &inser.mat);

            printf("Insira a nota n1: ");
            scanf("%f", &inser.n1);
            verif = InsereFimSemRepet(l, inser);
            if(verif == (-2)) printf("\nNao inserido\n");
            else if(verif == 0) printf("\nInserido\n");
            else printf("\nErro\n");
            system("pause");
            break;
        }
        if(ext) break;
    }while(1);
    system("pause");
    return 0;
}
