#include <stdio.h>
#include <stdlib.h>

int main()
{
    int M[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int i = 0, j = 0;
    int quant_0 = 0;

    printf("Digite os termos para matriz 4x4.\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Digite o %d termo da %d linha :\n", j + 1, i + 1);
            scanf("%d", &M[i][j]);
            if(j < i)
            {
                if(M[i][j] == 0)
                {
                    quant_0++;
                }
            }
        }
    }

    printf("\nA matriz digitada e a seguinte:\n\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }

    if (quant_0 == 6)
    {
        printf("Essa matriz e uma matriz triangular superior.\n");
    }

    return 0;
}