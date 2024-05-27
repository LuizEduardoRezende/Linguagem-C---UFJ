#include <stdio.h>
#include <stdlib.h>

int main()
{
    int M[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int i = 0, j = 0, k = 0;
    int s_linha[3] = {0, 0, 0}, s_coluna[3] = {0, 0, 0}, s_diagonal = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Digite o %d termo da %d linha :\n", j + 1, i + 1);
            scanf("%d", &M[i][j]);
        }
    }

    printf("\nA matriz digitada e a seguinte:\n\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }

    k = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            s_linha[k] += M[i][j];
        }
        k++;
    }

    k = 0;
    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 3; i++)
        {
            s_coluna[k] += M[i][j];
        }
        k++;
    }

    j = 0;
    for (i = 0; i < 3; i++)
    {
        s_diagonal += M[i][j];

        j++;
    }

    if (s_linha[0] == s_linha[1] && s_linha[1] == s_linha[2])
    {
        if (s_coluna[0] == s_coluna[1] && s_coluna[1] == s_coluna[2])
        {
            if (s_linha[0] == s_diagonal)
            {
                printf("Essa matriz e uma matriz Quadrado Magico.\n");
            }
            else
                printf("Essa matriz nao e uma matriz Quadrado Magico.\n");
        }
        else
            printf("Essa matriz nao e uma matriz Quadrado Magico.\n");
    }
    else
        printf("Essa matriz nao e uma matriz Quadrado Magico.\n");

    return 0;
}