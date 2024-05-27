#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    float total = 0, parcelas = 0;
    char opcao;
    int quant_parcelas = 0;

    printf("Digite o total gasto:\n");
    scanf("%f", &total);
    fflush(stdin);

    printf("Opcao A: a vista com 10%% de desconto.\n");
    printf("Opcao B: em duas vezes preco da etiqueta.\n");
    printf("Opcao C: de 3 ate 10 vezes com 3%% de juros ao mes (somente para compras acima de R$ 100,00).\n");
    do
    {
        printf("Digite a opcao de pagamento desejada:\n");
        scanf("%c", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 'A':
            printf("Valor a ser pago: %f", total * 0.9);
            break;

        case 'B':
            printf("Valor a ser pago: 2 vezes de %f", total / 2);
            break;

        case 'C':
            if (total > 100)
            {
                printf("Quantas parcelas deseja ?\n");
                do
                {
                    scanf("%d", &quant_parcelas);
                    fflush(stdin);
                } while ((quant_parcelas < 3) || (quant_parcelas > 10));

                printf("Valor a ser pago em %d vezes:\n", quant_parcelas);
                parcelas = total/ quant_parcelas;
                for(int i = 0; i<quant_parcelas; i++){
                    parcelas = parcelas * 1.03;
                    printf("%d parcela: %.2f\n", i+1, parcelas);
                }
                    
            }
            else
            {
                printf("Esta opcao e valida somente para compras acima de 100 reais.\n");
                opcao = 0;
            }
            break;

        default:
            printf("Digite uma opcao valida.\n");
            break;
        }
    } while ((opcao != 'A') && (opcao != 'B') && (opcao != 'C'));

    return 0;
}
