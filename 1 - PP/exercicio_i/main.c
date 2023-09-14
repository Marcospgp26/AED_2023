#include <stdio.h>

struct livro
{
    char titulo[31];
    int ano_edi;
    int numero_pag;
    float preco;

};

typedef struct livro liv;

int main()
{
    liv biblio[5];
    int i;
    float media;

    for(i = 0; i < 5; i++)
    {

        printf("Livro %i de 5\n\n",i + 1);
        printf("Insira o nome do livro (maximo de 30 caracteres): ");
        fflush(stdin);
        fgets(biblio[i].titulo, 30, stdin);

        printf("Insira o ano de edicao do livro: ");
        scanf("%i", &biblio[i].ano_edi);

        printf("Insira o numero de paginas do livro: ");
        scanf("%i",&biblio[i].numero_pag);

        printf("Insira o preco do livro: ");
        scanf("%f", &biblio[i].preco);
    }

    media = (biblio[0].numero_pag + biblio[1].numero_pag + biblio[2].numero_pag + biblio[3].numero_pag + biblio[4].numero_pag) / 5.0;

    printf("A media de paginas presente nos livros inseridos eh: %0.2f paginas\n", media);

    system("pause");
    return 0;
}
