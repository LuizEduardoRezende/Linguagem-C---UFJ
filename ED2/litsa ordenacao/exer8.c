#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 12

int num[TAM] = {26, 65, 45, 73, 10, 18, 78, 93, 70, 49, 23, 22};
int aux;

void selection_sort_4trocas(int num[])
{
    int i, j, min_idx;
    for (i = 0; i < TAM - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < TAM; j++)
        {
            if (num[j] < num[min_idx])
            {
                min_idx = j;
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        aux = num[min_idx];
        num[min_idx] = num[i];
        num[i] = aux;

        if(i == 3)
            return;
    }
}

int main(){
    printf("Vetor antes de ser utilizado a selection sort.\n");
    for(int i = 0; i<TAM; i++)
        printf("%d\t", num[i]);

    selection_sort(num);

    printf("\nVetor depois de 4 passos da selection sort.\n");
    for(int i = 0; i<TAM; i++)
        printf("%d\t", num[i]);

    return 0;
}