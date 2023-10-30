#include <stdio.h>
#include <string.h>
#include "pilha.h"


int Binario(Pilha *p, int *num);

int main()
{
    Pilha *p = Criar();
    int num, verif;

    printf("Insira o numero em decimal: ");
    scanf("%i", &num);

    verif = Binario(p, &num);
    if(verif == 2) printf("Pilha nao alocada\n");
    else Mostrar(p);

    system("pause");
    return 0;

}

int Binario(Pilha *p, int *num)
{
    if(p == NULL) return 2;
    int resto, prox;

    if(*num == 0)
        return 0;
    resto = (*num % 2);
    prox = (*num / 2);

    Push(p, resto);
    return Binario(p, &prox);
}
