#include <stdio.h>

int main()
{
    char str[21], vet[21];
    int i, j, k, cont = 0 ;

    printf("Insira uma frase ou palavra (maximo de 20 caracteres): \n");
    fflush(stdin);
    fgets(str, 20, stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        for(j = (i + 1); str[j] != '\0'; j++)
        {
            if(str[i] == str[j])
            {
                vet[cont] = str[i];
                cont++;
                break;;
            }
        }
    }

    if(cont == 0)
    {
        printf("\nNao ha letras repetidas.\n");
    }
    else
    {
        //retirar letras repetidas no vetor
        for(i = 0; i < cont; i++)
        {
            for(j = (i + 1); j < cont; j++)
            {
                if(vet[i] == vet[j])
                {
                    for(k = j; k < cont; k++)
                    {
                        vet[k] = vet[k + 1];
                    }
                    cont--;
                }
            }
        }

        //segunda verificacao
        for(i = 0; i < cont; i++)
        {
            for(j = (i + 1); j < cont; j++)
            {
                if(vet[i] == vet[j])
                {
                    for(k = j; k < cont; k++)
                    {
                        vet[k] = vet[k + 1];
                    }
                    cont--;
                }
            }
        }

        printf("\nExistem letras repetidas, elas sao:\n");
        for(i = 0; i < cont; i++)
        {
            printf(" %c\n", vet[i]);
        }
    }

    system("pause");
    return 0;
}
