#include <stdio.h>

int main()
{
    int menor_10 = 0, i = 1;
    float entrada, soma = 0;

    printf("Insira um numero para que uma das opcoes abaixo ocorra:\n CASO 1: Numeros maiores que 10 serao somados entre si\n CASO 2: Sera calculado quantos numeros MENORES que 10 foram adicionados\n");

    do
    {
        if(i > 1)
        {
            printf("\n\n");
        }

        printf("Ao adicionar o numero 10 a entrada de valores sera interrompida.\n\nInsira um valor (valor numero %d): ", i);
        scanf("%f", &entrada);

        if(entrada < 10)
        {
            menor_10++;
        }
        else if(entrada > 10)
        {
            soma += entrada;
        }
        else
        {
            printf("\n\n O valor inserido foi 10. Entrada de valores interrompida");
        }
        i++;
    }while(entrada != 10);

    printf("\n\n Soma dos numeros maiores que 10: %f.\n Quantidade de numeros menores que 10 inseridos: %d.\n\n",soma, menor_10);
    system("pause");
    return 0;
}
