#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaauxiliar.h"

int main()
{
    int i, tam;
    Lista *l;
    char str[2001], c;
    l = Criar();


    printf("Insira uma string (Max 2000 caracteres): ");
    fgets(str, 2000, stdin);

    tam = strlen(str);

    for(i = 0; i < tam; i++)
    {
        if(((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= 'A') && (str[i] <= 'Z')))
        {
            c = str[i];
            Muda_quant(l, c);
        }
    }

    printf("O Histograma da frase: ");
    puts(str);
    printf("Eh:\n");
    Imprime_Lista(l);
    printf("\n");
    system("pause");
    return 0;
}
