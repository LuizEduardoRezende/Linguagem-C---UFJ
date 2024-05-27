#include <stdio.h>
#include <stdlib.h>

int main()
{
    int exer;
    printf("Digite o exercicio desejado, de 1 a 9.\n");
    scanf("%d", &exer);
    while (exer != 0)
    {
        switch (exer)
        {
        case 1:
            printf("Exercicio 1.\n");
            break;
        case 2:
            printf("Exercicio 2.\n");
            break;
        case 3:
            printf("Exercicio 3.\n");
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
        case 9:
            printf("Exercicio 9.\n");
            break;
        default:
            printf("Exercicio inexistente.\n");
            break;
        }
        printf("Digite 0 caso queira encerrar o menu.\n");
        scanf("%d", &exer);
    }
    printf("Menu encerrado.\n");

    return 0;
}