#include <stdio.h>
int main(){
    printf("Entre com o valor: ");
    int n;
    scanf("%d",&n);
    int i,acc;

    /* O erro esta na inicialização da variavel acc que armazena o fatorial do numero, como ela nao eh inicializada com o valor 1
    Ou seja, int i, acc = 1, temos que o fatorial sera realizado com um valor de lixo do sistema, podendo obter resultados aleatorios
    a cada execução
    */

    for (i=n;i>0;i--)
        acc = acc * i;
    printf("O valor do fatorial de %d eh %d",n,acc);
}
