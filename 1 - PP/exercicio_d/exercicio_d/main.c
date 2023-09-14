#include <stdio.h>

int main()
{
    float notas[3], media, nota_ex;
    int i;

    for(i = 0; i < 3; i++)
    {
        do
        {
            printf("Insira a nota do aluno (nota %i de 3): ", i + 1);
            scanf("%f", &notas[i]);

            if((notas[i] < 0) || (notas[i] > 10))
            {
                printf("\n\nNota invalida. Por favor reeinsira-a.\n\n");
            }

        }while((notas[i] < 0) || (notas[i] > 10));
    }

    media = ((notas[0] + notas[1] + notas[2]) / 3);


    printf("\n\nMEDIA ARITMETICA DO SEMESTRE: %f\n", media);

    if((media > 3) && (media <= 7))
    {
        nota_ex = 12 - media;

        printf("\n\nAluno de EXAME FINAL.\n Necesario %0.2f pontos no EXAME FINAL.\n\n", nota_ex);
    }
    else if((media > 7) && (media <= 10))
    {
        printf("\n\nAluno APROVADO\n\n");
    }
    else
    {
        printf("\n\n Aluno REPROVADO\n\n");
    }

    system("pause");
    return 0;
}
