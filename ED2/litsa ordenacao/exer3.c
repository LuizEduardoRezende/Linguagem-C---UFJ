#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
int num[TAM] = {9,6,3,4,1,7,8,3,0};
int aux;

void bubble_sort()
{
    int i, j;

    for (i = 0; i < TAM; i++)
    {
        for (j = i + 1; j < TAM; j++)
        {
            if (num[j] < num[i])
            {
                aux = num[j];
                num[j] = num[i];
                num[i] = aux;
            }
        }
    }
}

int main()
{
    printf("Vetor desordenado:\n");
    for(int i = 0; i<TAM; i++)
    {
        printf("%d\t", num[i]);
    }

    bubble_sort();


    printf("\nVetor ordenado:\n");
    for(int i = 0; i<TAM; i++)
    {
        printf("%d\t", num[i]);
    }

    return 0;
}
