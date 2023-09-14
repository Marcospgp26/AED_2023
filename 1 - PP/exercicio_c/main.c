#include <stdio.h>

int main()
{
    int op1, op2, esc, result;
    char oper;

    printf("Insira o primeiro operando: ");
    scanf("%i", &op1);

    printf("Insira o segundo operando: ");
    scanf("%i", &op2);

    do
    {
        printf("Escolha um operador dentre os abaixo:\n (+) - adicao\n (-) - Subtracao\n (*) - Multiplicacao\n (/) - Divisao");
        printf("\n\nInsira o operador: ");
        fflush(stdin);
        scanf("%c", &oper);

        if((oper != '+') && (oper != '-') && (oper != '/') && (oper != '*'))
        {
            printf("\nEscolha de operadores invalida. Por favor escolha-os novamente.\n\n");
        }
    }while((oper != '+') && (oper != '-') && (oper != '/') && (oper != '*'));

    switch(oper)
    {
        case '-':
            do
            {
                printf("Escolha qual operacao deseja realizar:\n (1) %d - %d\n (2) %d - %d", op1, op2,op2,op1);
                printf("\n\n Insira o numero que indica a operacao: ");
                scanf("%i", &esc);

                if((esc != 1) && (esc != 2))
                {
                    printf("\nEscolha invalida, por favor reeinsira-a.\n\n");
                }
            }while((esc != 1) && (esc != 2));

            if(esc == 1)
            {
                result = op1 - op2;
            }
            else
            {
                result = op2 - op1;
            }
            break;
        case '/':

            do
            {
                printf("Escolha qual operacao deseja realizar:\n (1) %d / %d\n (2) %d / %d", op1, op2,op2,op1);
                printf("\n\n Insira o numero que indica a operacao: ");
                scanf("%i", &esc);

                if((esc != 1) && (esc != 2))
                {
                    printf("\nEscolha invalida, por favor reeinsira-a.\n\n");
                }
            }while((esc != 1) && (esc != 2));

            if(esc == 1)
            {
                if(op2 == 0)
                {
                    printf("\n\nImpossivel realizar a operacao, divisor = 0\n");
                    system("pause");
                    exit(1);
                }
                result = op1 / op2;
            }
            else
            {
                if(op1 == 0)
                {
                    printf("\n\nImpossivel realizar a operacao, divisor = 0\n");
                    system("pause");
                    exit(1);
                }
                result = op2 / op1;
            }
            break;
        case '+':
            result = op1 + op2;
            break;
        case '*':
            result = op1 * op2;
            break;
    }

    printf("O resultado da operacao escolhida eh: %d\n\n", result);
    system("pause");
    return 0;
}
