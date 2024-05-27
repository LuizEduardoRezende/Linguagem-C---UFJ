#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 1000 

double num[TAM];
double aux;

void selection_sort()
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
    }
}

void insertion_sort()
{
    int i, j;
    for (i = 1; i < TAM; i++)
    {
        j = i - 1;
        aux = num[i];
        while (j >= 0 && aux < num[j])
        {
            num[j + 1] = num[j];
            j--;
        }
        num[j + 1] = aux; // Move o valor de aux para a posição correta
    }
}


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
    int i = 0;
    int esc = -1;

    srand(time(NULL));

    // Preenche o vetor com números aleatórios entre 0 e 1
    for (i = 0; i < TAM; i++)
    {
        num[i] = ((double)rand() / RAND_MAX);
    }

    printf("Digite qual metodo de ordenacao deseja:\n");
    printf("1. Selection sort.\n");
    printf("2. Insertion sort.\n");
    printf("3. Bubble sort.\n");
    scanf("%d", &esc);
    fflush(stdin);

    switch (esc)
    {
    case 1:
    {
        clock_t start_time = clock();

        selection_sort();

        clock_t end_time = clock();

        // Calcula o tempo de execução em segundos
        double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        // Exibe o tempo de execução
        printf("\n\nTempo de execucao: %.6f segundos\n\n", elapsed_time);

        break;
    }

    case 2:
    {
        clock_t start_time = clock();

        insertion_sort();

        clock_t end_time = clock();

        // Calcula o tempo de execução em segundos
        double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        // Exibe o tempo de execução
        printf("\n\nTempo de execucao: %.6f segundos\n\n", elapsed_time);

        break;
    }

    case 3:
    {
        clock_t start_time = clock();

        bubble_sort();

        clock_t end_time = clock();

        // Calcula o tempo de execução em segundos
        double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        // Exibe o tempo de execução
        printf("\n\nTempo de execucao: %.6f segundos\n\n", elapsed_time);

        break;
    }

    default:
        printf("Opcao invalida.\n");
        break;
    }

    for(i = 0; i< 1000; i++)
        printf("%f\t", num[i]);

    return 0;
}
