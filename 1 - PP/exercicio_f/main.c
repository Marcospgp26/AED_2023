#include <stdio.h>

int main()
{
    float base, altura, area;

    do
    {
        printf("Insira a altura do triangulo: ");
        scanf("%f", &altura);

        if(altura <= 0)
        {
            printf("\n\nALTURA INVALIDA (menor ou igual a 0), reensira-a\n\n");
        }
    }while(altura <=0);

    do
    {
        printf("Insira o tamanho da base do triangulo: ");
        scanf("%f", &base);

        if(base <= 0)
        {
            printf("\n\nTAMANHO DA BASE INVALIDO (menor ou igual a zero), reensira-a\n\n");
        }
    }while(base <= 0);

    area = (base * altura) / 2;

    printf("\nA area do triangulo eh: %f\n\n", area);

    system("pause");
    return 0;
}
