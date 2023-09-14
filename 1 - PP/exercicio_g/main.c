#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int mat[5][10], vet[5], i, j;
    srand(time(NULL));

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 10; j++)
        {
            //por questoes de facilidade de calculo limitei ate 9 os numeros gerados
            mat[i][j] = rand() % 10;
        }
        vet[i] = 0;
    }

    printf("MATRIZ INICIAL:\n");
    for(i = 0; i < 5; i++)
    {
        for(j =0; j < 10; j++)
        {

            printf("%d | ", mat[i][j]);
            vet[i] += mat[i][j];
        }
        printf("\n");
    }

    printf("\n MATRIZ NOVA:\n");

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 10; j++)
        {
            mat[i][j] = mat[i][j] * vet[i];
            printf("%d | ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    system("pause");
    return 0;
}
