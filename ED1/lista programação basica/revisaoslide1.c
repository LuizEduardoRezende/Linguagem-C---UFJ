#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    int cod_peca = 0, quant = 0;
    float valor_total = 0, valor = 0;

    printf("Digite o codigo da peca:\n");
    scanf("%d", &cod_peca);
    fflush(stdin);

    printf("Digite o valor da peca:\n");
    scanf("%f", &valor);
    fflush(stdin);

    printf("Digite a quantidade de pecas:\n");
    scanf("%d", &quant);
    fflush(stdin);

    valor_total = (float)quant * valor;

    printf("Codigo da peca: %d\nValor total: %f\n", cod_peca, valor_total);

    return 0;
}
