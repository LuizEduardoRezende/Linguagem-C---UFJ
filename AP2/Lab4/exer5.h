#ifndef exer5_h
#define exer5_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

float preco_atual = 0, percentual_acrescimo = 0, preco_antigo = 0;

int preco()
{
    setlocale(LC_ALL, "Portuguese");
    printf("Digite o preço atual:\n");
    fflush(stdin);
    scanf("%f", &preco_atual);
    printf("\nDigite o preço antigo:\n");
    fflush(stdin);
    scanf("%f", &preco_antigo);

    percentual_acrescimo = (100 * preco_atual - 100 * preco_antigo) / preco_atual;
    printf("O percentual de acrescimo é: %.2f %%\n", percentual_acrescimo);

    return 0;
}
#endif