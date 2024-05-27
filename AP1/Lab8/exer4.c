#include <stdio.h>
#include <stdlib.h>

int main()
{
    int exer;
    do
    {
        printf("Digite o numero do exercicio desejado, 4 ate o 8. Digite 0 para encerrar o menu.\n");
        scanf("%d", &exer);
        switch (exer)
        {
        case 0:
            printf("Menu encerrado.\n");
            break;
        case 4:
            printf("Exercicio 4.\n");
            break;
        case 5:
            printf("Exercicio 5.\n");
            break;
        case 6:
            printf("Exercicio 6.\n");
            break;
        case 7:
            printf("Exercicio 7.\n");
            break;
        case 8:
            printf("Exercicio 8.\n");
            break;
        default:
            printf("Exercicio invalido.\n");
            break;
        }

    } while (exer != 0);

    system("pause");
    return 0;
}