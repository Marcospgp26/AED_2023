#include <stdio.h>

int main()
{
    int a_nasc, a_atual, id_atual, id_2030;
    char verif;

    do
    {
    printf("Insira o ano em que voce nasceu: ");
    scanf("%i", &a_nasc);

    printf("Insira o ano atual: ");
    scanf("%i", &a_atual);

    if((a_atual < a_nasc) || (a_nasc < 0))
    {
        printf("\nDatas invalidas (ou o ano de nascimento eh maior que o ano atual, ou o ano de nascimento eh menor que 0), reinsira-as.\n\n");
    }

    }while((a_atual < a_nasc) || (a_nasc < 0));

    do
    {
        if(a_atual == a_nasc)
        {
            verif = 's';
            break;
        }
        printf("Voce ja fez aniversario esse ano?(s/n) ");
        fflush(stdin);
        scanf("%c", &verif);

        if((verif != 'S') && (verif != 's') && (verif != 'n') && (verif != 'N'))
        {
            printf("\n Escolha invalida, por favor realize-a novamente.\n\n");
        }
    }while((verif != 'S') && (verif != 's') && (verif != 'n') && (verif != 'N'));

    id_2030 = 2030 - a_nasc;
    id_atual = a_atual - a_nasc;

    if((verif == 'n') || (verif == 'N'))
    {
        id_atual--;
    }

    printf("\n\nSua idade atual eh: %d anos\nSua idade em 2030, apos realizar aniversario, sera: %d anos\n\n", id_atual, id_2030);

    system("pause");

    return 0;
}
