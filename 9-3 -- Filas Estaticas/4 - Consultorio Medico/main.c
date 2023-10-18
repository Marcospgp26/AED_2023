#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    Fila *f = Criar();
    int n = 0, esc, ret, ext = 0, verif;
    char nome[100];

    printf("Bem vindo ao consultorio\n\n");
    while(1)
    {
        printf("Escolha:\n\n1)Cadastrar novo cliente\n2)Chamar o primeiro cliente\n3)Sair\n");
        scanf("%i", &esc);

        switch(esc)
        {

        case 1:
            printf("Insira o nome do paciente: ");
            fflush(stdin);
            fgets(nome, 100, stdin);
            verif = Inserir(f, n);
            if(verif == 0)
            {
                printf("Feito\n\n");
                n++;
            }
            else printf("Muitos Pacientes\n\n");
            break;

        case 2:
            verif = Remover(f, &ret);
            if(verif == 0) printf("Chame o paciente %i\n\n", ret);
            else if(verif == 1) printf("Sem paciente\n");
            system("pause");
            break;

        case 3:
            ext++;
            break;

        default:
            printf("Escolha invalida\n");
            break;

        }
        if(ext) break;
    }
    return 0;
}
