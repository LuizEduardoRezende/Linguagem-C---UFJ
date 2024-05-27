#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20000000

double num[TAM];
double aux;

void insertion_sort()
{
    int i, j, t;

    for (i = 1; i < TAM; i++)
    {
        t = num[i];
        j = i - 1;

        while (j >= 0 && t < num[j])
        {
            num[j + 1] = num[j];
            j--;
        }

        num[j + 1] = t;
    }
}

int main()
{
    int i;

    srand(time(NULL));

    // Preenche o vetor com números aleatórios entre 0 e 1
    for (i = 0; i < TAM; i++)
    {
        num[i] = ((double)rand() / RAND_MAX);
    }

    // Inicia o cronômetro
    clock_t start_time = clock();

    // Chama o algoritmo de ordenação (Insertion Sort)
    insertion_sort();

    // Para o cronômetro
    clock_t end_time = clock();

    // Calcula o tempo de execução em segundos
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Exibe o tempo de execução
    printf("\n\nTempo de execucao: %.6f segundos\n\n", elapsed_time);

    // Exibe os primeiros e últimos elementos do vetor ordenado
    printf("Vetor ordenado (primeiros e ultimos elementos):\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%f\t", num[i]);
    }

    printf("...\t");

    for (int i = TAM - 5; i < TAM; i++)
    {
        printf("%f\t", num[i]);
    }

    return 0;
}
