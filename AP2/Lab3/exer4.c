#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct dia_mes_ano
    {
        int dia, mes, ano;
    } dma[3];
    int dias_totais = 0;

    // pegando valores da primeira data e colocando em dma[0]
    do
    {
        printf("Digite o ano da primeira data:\n");
        scanf("%d", &dma[0].ano);
        fflush(stdin);
    } while (dma[0].ano < 0);
    do
    {
        printf("Digite o mês da primeira data (número):\n");
        scanf("%d", &dma[0].mes);
        fflush(stdin);
    } while (dma[0].mes <= 0 || dma[0].mes > 12);
    do
    {
        printf("Digite o dia da primeira data:\n");
        scanf("%d", &dma[0].dia);
        fflush(stdin);
    } while (dma[0].dia <= 0 || dma[0].mes > 31);

    // pegando valores da segunda data e colocando em dma[1]
    do
    {
        printf("Digite o ano da segunda data.\n");
        scanf("%d", &dma[1].ano);
        fflush(stdin);
    } while (dma[1].ano < 0);
    do
    {
        printf("Digite o mês da segunda data:\n");
        scanf("%d", &dma[1].mes);
        fflush(stdin);
    } while (dma[1].mes <= 0 || dma[1].mes > 12);
    do
    {
        printf("Digite o dia da segunda:\n");
        scanf("%d", &dma[1].dia);
        fflush(stdin);
    } while (dma[1].dia <= 0 || dma[1].mes > 31);

    // calculando a diferença entre as duas datas e colocando em dma[3]
    dma[3].ano = abs(dma[0].ano - dma[1].ano);
    dma[3].mes = abs(dma[0].mes - dma[1].mes);
    dma[3].dia = abs(dma[0].dia - dma[1].dia);

    // calculando os dias totais entre as datas
    dias_totais = (dma[3].ano * 3600) + (dma[3].mes * 31) + dma[3].dia;
    
    if (dias_totais > 0)
    {
        printf("A quantidade de dias decorridos durante as datas informadas é: %d", dias_totais);
    }
    else
    {
        printf("As datas informadas são iguais.\n");
    }

    return 0;
}