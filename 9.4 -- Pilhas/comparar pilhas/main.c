#include <stdio.h>
#include "pilha.h"

void menu(Pilha *p1, Pilha *p2);
void limpar_pilhas(Pilha *p1, Pilha *p2);
void push_pilhas(Pilha *p1, Pilha *p2);
void pop_pilhas(Pilha *p1, Pilha *p2);
void consultar_pilhas(Pilha *p1, Pilha *p2);
void tamanho_pilhas(Pilha *p1, Pilha *p2);
void mostrar_pilhas(Pilha *p1, Pilha *p2);
void sao_iguais(Pilha *p1, Pilha *p2);

int main()
{
    Pilha *p1 = Criar(), *p2 = Criar();
    menu(p1, p2);

}

void menu(Pilha *p1, Pilha *p2)
{
    int esc;
    do
    {
        printf("1)Sair\n2)Limpar\n3)Push\n4)Pop\n5)Consultar\n6)Tamanho\n7)Mostrar\n8)Ver se as pilhas sa iguais\n");
        scanf("%i", &esc);
        switch(esc)
        {
        case 2:
            limpar_pilhas(p1, p2);
            break;
        case 3:
            push_pilhas(p1, p2);
            break;
        case 4:
            pop_pilhas(p1, p2);
            break;
        case 5:
            consultar_pilhas(p1, p2);
            break;
        case 6:
            tamanho_pilhas(p1, p2);
            break;
        case 7:
            mostrar_pilhas(p1, p2);
            break;
        case 8:
            sao_iguais(p1, p2);
            break;
        }
        system("pause");
        system("cls");
    }
    while(esc != 1);

}

void limpar_pilhas(Pilha *p1, Pilha *p2)
{
    int tipo;
    printf("1)Pilha 1\n2)Pilha 2\n");
    scanf("%i", &tipo);

    if(tipo == 1)
    {
        Limpar(p1);
        p1 = Criar();
    }
    else if(tipo == 2)
    {
        Limpar(p2);
        p2 = Criar();
    }
    else printf("\nInvalido\n");
}

void push_pilhas(Pilha *p1, Pilha *p2)
{
    int tipo,it, verif = -1;

    printf("1)Pilha 1\n2)Pilha 2\n");
    scanf("%i", &tipo);

    if(tipo == 1)
    {
        printf("Insira o numero: ");
        scanf("%i", &it);

        verif = Push(p1, it);
    }
    else if(tipo == 2)
    {
        printf("Insira o numero: ");
        scanf("%i", &it);

        verif = Push(p2, it);
    }
    else printf("\nInvalido\n");

    switch(verif)
    {
    case 0:
        printf("\nInserido\n");
        break;
    case 2:
        printf("\nPilha nao alocada\n");
        break;
    }
}

void pop_pilhas(Pilha *p1, Pilha *p2)
{
        int tipo,it, verif = -1;

    printf("1)Pilha 1\n2)Pilha 2\n");
    scanf("%i", &tipo);

    if(tipo == 1)
    {
        verif = Pop(p1, &it);
    }
    else if(tipo == 2)
    {
        verif = Pop(p2, &it);
    }
    else printf("\nInvalido\n");

    switch(verif)
    {
    case 0:
        printf("O elemento retirado foi: %i\n", it);
        break;
    case 1:
        printf("Pilha Vazia\n");
        break;
    case 2:
        printf("Pilha nao alocada\n");
        break;
    }
}

void consultar_pilhas(Pilha *p1, Pilha *p2)
{
    int verif = -1, it, tipo;

    printf("1)Pilha 1\n2)Pilha 2\n");
    scanf("%i", &tipo);

    if(tipo == 1) verif = Consultar(p1, &it);
    else if(tipo == 2) verif = Consultar(p2, &it);
    else printf("\nInvalido\n");

    switch(verif)
    {
    case 0:
        printf("\nElemento no topo: %i\n", it);
        break;
    case 1:
        printf("\nPilha Vazia\n");
        break;
    case 2:
        printf("\nPilha nao alocada\n");
        break;
    }
}

void tamanho_pilhas(Pilha *p1, Pilha *p2)
{
    int verif = -1, tipo;

    printf("1)Pilha 1\n2)Pilha 2\n");
    scanf("%i", &tipo);

    if(tipo == 1) verif = Tamanho(p1);
    else if(tipo == 2) verif = Tamanho(p2);
    else printf("\nInvalido\n");

    if(verif != (-1))
    {
        if(verif == (-2))
        {
            printf("\nPilha nao alocada\n");
        }
        else
        {
            printf("Tamanho da lista: %i", verif);
        }
    }
}

void mostrar_pilhas(Pilha *p1, Pilha *p2)
{
    int tipo;

    printf("1)Pilha 1\n2)Pilha 2\n");
    scanf("%i", &tipo);

    system("cls");
    if(tipo == 1) Mostrar(p1);
    else if(tipo == 2) Mostrar(p2);
    else printf("\nInvalido\n");

    printf("\n");
}

void sao_iguais(Pilha *p1, Pilha *p2)
{
    int resp = 0, it1, it2;
    if(Tamanho(p1) != Tamanho(p2)) resp = 1;
    else
    {
        while(PilhaVazia(p1) != 0)
        {
            Pop(p1, &it1);
            Pop(p2, &it2);
            if(it1 != it2)
            {
                resp = 1;
                break;
            }
        }
    }
    if(resp == 1) printf("\nSao diferentes\n");
    else printf("\nSao iguais\n");
}
